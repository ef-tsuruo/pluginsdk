#pragma once
SXCORE
#include <exception>
#include <ios>

namespace sx {
	class error : public std::exception {
	public:
		explicit error (const char *s, const char *file, int line) throw();
		virtual ~error () throw() { }
		virtual const char *what () const throw();
	private:
		std::string text;
	};

	class eof_error : public std::ios_base::failure {
	public:
		eof_error ();
	};

	class quiet_error : public std::exception {
	private:
		virtual const char *what () const throw() { return ""; }
	};

	class no_error : public std::exception {
	private:
		virtual const char *what () const throw() { return ""; }
	};

	class abort_error : public std::exception {
	private:
		virtual const char *what () const throw() { return ""; }
	};

	class filereference_error : public std::exception {
	public:
		const std::string file_name;
		explicit filereference_error (const std::string &file_name) throw() : file_name(file_name) { }
		virtual ~filereference_error () throw() { }
	};

	void verify_failed (const char *message, const char *file, int line);
	inline void verify (bool condition, const char *message, const char *file, int line) {
		if (!condition) verify_failed(message, file, line);
	}
	
	#if SXPOSIX
		const std::string format_message (int error_code);
	#elif SXWINDOWS
		const std::string format_message (DWORD error_code);
	#endif
}
