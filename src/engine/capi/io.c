void engine_debug(const char * message) {
	printf("\033[1mengine.\033[34mdebug\033[0m: \033[2m%s\033[0m\n", message);
	fflush(stdout);
}

void engine_warning(const char * message) {
	printf("\033[1mengine.\033[33mwarning\033[0m: \033[2m%s\033[0m\n", message);
	fflush(stdout);
}

void engine_error(const char * message) {
	fprintf(stderr, "\033[1mengine.\033[31merror\033[0m: \033[2m%s\033[0m\n", message);
	fflush(stderr);
	engine.exit(1);
}

void engine_task(const char * task_name) {
		
}

void engine_task_indent() {

}

void engine_done() {
	
}

