void engine_debug(const char * format, ...) {
	char * message;
	
	va_list args;
	va_start(args, format);
	vasprintf(&message, format, args); // format message
	va_end(args);	

	// print message and format debug message
	fprintf(stdout, "\033[1mengine.\033[34mdebug\033[0m: \033[2m%s\033[0m\n", message);
	fflush(stdout);
	
	free(message);
}

void engine_warning(const char * format, ...) {
	char * message;
	
	va_list args;
	va_start(args, format);
	vasprintf(&message, format, args); // format message
	va_end(args);	

	// print message and format debug message
	fprintf(stdout, "\033[1mengine.\033[33mwarning\033[0m: \033[2m%s\033[0m\n", message);
	fflush(stdout);
	
	free(message);
}

void engine_error(const char * format, ...) {
	char * message;
	
	va_list args;
	va_start(args, format);
	vasprintf(&message, format, args); // format message
	va_end(args);	
	
	fprintf(stderr, "\033[1mengine.\033[31merror\033[0m: \033[2m%s\033[0m\n", message);
	fflush(stderr);
	
	free(message);
	
	engine.exit(1);
}

void engine_assert(bool expression, const char * format, ...) {
	if ( expression ) return;
	
	char * message;
	
	va_list args;
	va_start(args, format);
	vasprintf(&message, format, args); // format message
	va_end(args);	
	
	fprintf(stderr, "\033[1mengine.\033[31massert\033[0m: \033[2m%s\033[0m\n", message);
	fflush(stderr);
	
	free(message);
	
	engine.exit(1);
}

void engine_task(const char * task_name) {
		
}

void engine_task_indent() {

}

void engine_done() {
	
}

