// header declarations 
	#ifdef HEADER 
		void engine_debug(const char *, ...);
		void engine_error(const char *, ...);
		void engine_warning(const char *, ...);
		void engine_assert(bool, const char *, ...);
	#endif

// struct declartions
	#ifdef STRUCT
		void (*debug)(const char *, ...);	
		void (*error)(const char *, ...);	
		void (*warning)(const char *, ...);	
		void (*assert)(bool, const char *, ...);	
	#endif

// struct initalizations
	#ifdef STRUCT_INIT 
		.debug = engine_debug,
		.error = engine_error,
		.warning = engine_warning,
		.assert = engine_assert,
	#endif

// definitions
	#if !defined HEADER && !defined STRUCT && !defined STRUCT_INIT
		// engine_debug
		void engine_debug(const char * format, ...) {
			char * message;

			// format message
				va_list args;
				va_start(args, format);
				vasprintf(&message, format, args);
				va_end(args);	

			// print message
				fprintf(stdout, "\033[1mengine.\033[34mdebug\033[0m: \033[2m%s\033[0m\n", message);
				fflush(stdout);
			
			free(message);
		}

		// engine_error
		void engine_error(const char * format, ...) {
			char * message;

			// format message
				va_list args;
				va_start(args, format);
				vasprintf(&message, format, args); // format message
				va_end(args);	

			// print message
				fprintf(stderr, "\033[1mengine.\033[31merror\033[0m: \033[2m%s\033[0m\n", message);
				fflush(stderr);
			
			free(message);
			engine.exit(1); // exit with error
		}

		// engine_warnging
		void engine_warning(const char * format, ...) {
			char * message;

			// format message
				va_list args;
				va_start(args, format);
				vasprintf(&message, format, args); // format message
				va_end(args);	

			// print message
				fprintf(stdout, "\033[1mengine.\033[33mwarning\033[0m: \033[2m%s\033[0m\n", message);
				fflush(stdout);
			
			free(message);
		}
		
		// engine_assert
		void engine_assert(bool expression, const char * format, ...) {
			if ( expression ) return;
			char * message;

			// format message
				va_list args;
				va_start(args, format);
				vasprintf(&message, format, args); // format message
				va_end(args);	

			// print message
				fprintf(stderr, "\033[1mengine.\033[31massert\033[0m: \033[2m%s\033[0m\n", message);
				fflush(stderr);

			free(message);
			engine_exit(1); // exit with error
		}
	#endif
