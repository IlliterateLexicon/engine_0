/*| header |*/
	#if defined HEADER
	const engine_vector engine_tasks = {};
	void engine_task(const char *, ...);
	void engine_task_done();

/*| struct |*/
	#elif defined STRUCT
	engine_vector tasks;
	void (*task)(const char *, ...);
	void (*task_done)();

/*| struct init |*/
	#elif defined STRUCT_INIT 
	.tasks = engine_tasks,
	.task = engine_task,
	.task_done = engine_task_done,

/*| definitions |*/
	#else
	
	static void engine_task_indent() {
		for (int i=0; i < engine.vector.length(&engine.tasks); i++ ) fprintf(stdout, "\t");
		fflush(stdout);
	}

	void engine_task(const char * task_name, ...) {
		if ( ! engine.tasks.allocated ) { engine.vector.alloc(&engine.tasks); }
		engine_task_indent();
		engine.vector.add(&engine.tasks, task_name);
		fprintf(stdout, "\033[1mengine.\033[35mtask\033[0m: %s\n", task_name);
		fflush(stdout);
	}
	
	void engine_task_done() {
		engine.vector.rem(&engine.tasks);
	}
	#endif
