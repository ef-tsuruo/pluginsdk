#pragma once
SXCORE

#if __OBJC__
	#ifndef NSINTEGER_DEFINED
		#if __LP64__
			typedef long NSInteger;
			typedef unsigned long NSUInteger;
		#else
			typedef int NSInteger;
			typedef unsigned int NSUInteger;
		#endif
	#endif

	namespace sx {
		class autoid {
		public:
			id p;

			explicit autoid (id p = nil) : p(p) { }
			~autoid () {
				if (p) [p release];
			}
			operator id () const {
				return p;
			}
		};
		
		class autoreleasepool {
		public:
			autoreleasepool () : pool(nil) {
				pool = [[NSAutoreleasePool alloc] init];
			}
			~autoreleasepool () {
				[pool release];
			}
			void release () {
				[pool release];
				pool = nil;
			}
		private:
			NSAutoreleasePool *pool;
		};

		void raise_exception ();
	}
	
	#if !SXIOS
		static std::ostream &operator<< (std::ostream &o, const NSRect &r) {
			o << r.origin.x << " " << r.origin.y << " " << r.size.width << " " << r.size.height;
			return o;
		}
	#endif
#else
	typedef void *id;
	typedef void NSOpenGLContext;
	typedef void NSWindow;
	typedef void NSOpenGLPixelBuffer;
	typedef void NSFileHandle;
	typedef void NSEvent;
	typedef void NSCursor;
	typedef void NSView;
	typedef void NSScrollView;
	typedef void NSTableColumn;
	typedef void NSTableView;
	typedef void NSString;
	typedef void NSGraphicsContext;
	typedef int NSToolTipTag;
	typedef void NSMenu;
	typedef void NSPopUpButtonCell;
	typedef void NSButton;
	typedef void NSTextField;
	typedef void NSPopUpButton;
	typedef void NSColorWell;
	typedef void NSProgressIndicator;
	typedef void NSBox;
	typedef void NSMutableArray;
	typedef void NSBundle;
	typedef void NSData;
	typedef struct _NSPoint {
		float x;
		float y;
	} NSPoint;
	typedef struct _NSSize {
		float width;
		float height;
	} NSSize;
	typedef struct _NSRect {
		NSPoint origin;
		NSSize size;
	} NSRect;
	typedef unsigned int NSDragOperation;
	namespace sx {
		class autoid {
		public:
			id p;

			explicit autoid (id p = 0) : p(p) { }
			~autoid () { }
			operator id () const {
				return p;
			}
		};
		class autoreleasepool {
		};
	}
#endif

#define SXCOCOAIMPLEMENTATION do { sxassert(true); } while (false)
