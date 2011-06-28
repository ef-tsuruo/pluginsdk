#pragma once
SXCORE
#include "sx/core/setting.hpp"

namespace sx {
	class recursive_mutex;

	namespace memory {
		#if SXDARWIN
			extern sx::recursive_mutex mutex; // attempt to fix infrequent carsh on quadxeon powermac with snow leopard. it is suspected that vm_(de)allocate() routines may not be thread safe. should to be verified.
		#endif
		// be warned that using reallocate() functions to shrink a block that's larger than chunk_size can be inefficient and can hog up virtual address space.
	
		namespace settings {
			extern sx::setting<bool> debug;
			extern sx::setting<bool> memory_analysis;
		}
		
		extern volatile std::size_t allocated_bytes;
		
		void initialize ();
		void finalize ();

		void *virtual_allocate (std::size_t n); // accepts multiiple of granularity although allocation may be slow. fast and efficient when n is multiple of chunk_size.
		void virtual_deallocate (void *p, std::size_t n);
		void virtual_query ();

		extern std::size_t page_size;
		extern std::size_t granularity; 
		//const int N = 12; // 4KiB
		//const int N = 14; // 16KiB
		//const int N = 16; // 64KiB
		//const int N = 20; // 1 MiB
		//const int N = 22; // 4 MiB
		//const int N = 24; // 16 MiB
		#if SXDARWIN
			const int N = 24;
		#elif SXWINDOWS
			const int N = 16;
		#endif
		const std::size_t chunk_size = (std::size_t(1) << N); // hard-coded so that this can be used in constant expression for performance. on 32bit Windows, an attempt to allocate a few megabytes of memory (including BitMap object) can easily fail due to fragmentation in 32-bit virtual address space. it may be best to try to avoid allocating blocks larger than the granularity.

		void check_address (void *p);
		void check_heap ();

		class header_base_imp {
		public:
			std::size_t		size; // logical size
			sx::unsigned32	offset; // sx::unsigned32(-1) when allocated outside the allocator's pool.
			bool			used; // when used is false, it is guaranteed that the block is linked in the avail list and physical_size is valid.
			sx::unsigned8	physical_size;
			#if SXSIGNATURE
				void *allocator_signature;
				sx::unsigned32 signature;
			#endif
		};
		
		template<int N> class header_base_template : public header_base_imp {
		private:
			char padding[N];
		};
		template<> class header_base_template<0> : public header_base_imp {
		};
		typedef header_base_template<(sizeof(header_base_imp)+15) / 16 * 16 - sizeof(header_base_imp)> header_base_class;

		class header_class : public header_base_imp {
		public:
			header_class *prev;
			header_class *next;
		};
		
		const std::size_t header_size = sizeof(header_base_class);
		
		inline static header_class *header (void *p) {
			return (header_class *)((char *)(p) - header_size);
		}
		inline static const header_class *header (const void *p) {
			return (const header_class *)((const char *)(p) - header_size);
		}
		inline static void *unheader (header_class *p) {
			return (void *)((char *)(p) + header_size);
		}
		inline static const void *unheader (const header_class *p) {
			return (const void *)((const char *)(p) + header_size);
		}
		inline std::size_t chunk_capacity (std::size_t item_size) { // returns the maximum number of items a chunk can hold, without resorting to extra-heap allocation.
			return ((chunk_size - header_size) / item_size);
		}

		inline static std::size_t get_size (const void *p) {
			if (p == 0) return 0;
			return header(p)->size;
		}
		inline static int find_size (std::size_t size) {
			size = std::max(size + header_size, sizeof(header_class));
			int	n;
			for (n = 0; (sx::unsigned64(1)<<n) < sx::unsigned64(size); ++n) {
				SXASSERT(n < (sizeof(std::size_t)*8));
			}
			return n;
		}
		inline static std::size_t get_optimum_size (const std::size_t size, const int N) {
			const int n = find_size(size);
			if (n <= N) return (std::size_t(1) << n) - header_size;

			const std::size_t chunk_size = (std::size_t(1) << N);
			#if SXSIGNATURE
				return (((header_size + size + sizeof(sx::unsigned32)) + chunk_size - 1) / chunk_size * chunk_size) - header_size;
			#else
				return (((header_size + size) + chunk_size - 1) / chunk_size * chunk_size) - header_size;
			#endif
		}
		inline static std::size_t get_optimum_size (std::size_t size) {
			return get_optimum_size(size, N);
		}

		void *allocate (std::size_t size);
		void *reallocate (void *p, std::size_t size);
		void free (void *p);
		bool shrink (void *p, std::size_t size);

		class object {
		public:
			void *operator new (std::size_t size) {
				return sx::memory::allocate(size);
			}
			void *operator new (std::size_t size, void *p) {
				return p;
			}
			void operator delete (void *p) {
				sx::memory::free(p);
			}
			void operator delete (void *p, void *q) {
			}
			void *operator new[] (std::size_t size) {
				return sx::memory::allocate(size);
			}
			void operator delete[] (void *p) {
				sx::memory::free(p);
			}
		};

		template<typename T> class allocator {
		public:
			typedef T        value_type;
			typedef T*       pointer;
			typedef const T* const_pointer;
			typedef T&       reference;
			typedef const T& const_reference;
			typedef std::size_t    size_type;
			typedef std::ptrdiff_t difference_type;
			template<typename U> struct rebind {
				typedef allocator<U> other;
			};
			pointer address (reference value) const { return &value; }
			const_pointer address (const_reference value) const { return &value; }
			allocator () throw() { }
			allocator (const allocator &) throw() { }
			template<typename U> allocator (const allocator<U> &) throw() { }
			~allocator () throw() { }
			size_type max_size () const throw() { return std::size_t(-1) / sizeof(T); }
			pointer allocate (size_type num, const void* = 0) { return pointer(sx::memory::allocate(num * sizeof(T))); }
			void construct (pointer p, const T& value) { new((void*)p)T(value); }
			void destroy (pointer p) { p->~T(); }
			void deallocate (pointer p, size_type num) { sx::memory::free(p); }
		};

		class block_info_class {
		public:
			std::size_t size;
			bool extra;
			explicit block_info_class (std::size_t size, bool extra) : size(size), extra(extra) { }
		};

		void get_analysis_data (std::map<void *, block_info_class> &data);
		const std::size_t get_free_size ();
		void eat (std::size_t free);
	}
}
template<typename T1, typename T2> bool operator== (const sx::memory::allocator<T1> &, const sx::memory::allocator<T2> &) throw() {
   return true;
}
template<class T1, class T2> bool operator!= (const sx::memory::allocator<T1> &, const sx::memory::allocator<T2> &) throw() {
   return false;
}

namespace sx {
	namespace core {
		namespace unittest {
			void test_memory ();
		}
	}
}
