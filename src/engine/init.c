/*| header declartions |*/
	#if defined HEADER 
	#include "io.c"
	#include "time.c"
	#include "vector.c"
	#include "task.c"
	#include "tick.c"
	#include "draw.c"

	void engine_init();
	void engine_exit();

/*| struct declarations |*/
	#elif defined STRUCT 
	void (*init)();
	void (*exit)();
	
	#include "io.c"
	#include "time.c"
	#include "vector.c"
	#include "task.c"
	#include "tick.c"
	#include "draw.c"

/*| struct initalizations |*/ 
	#elif defined STRUCT_INIT 
	.init = engine_init,
	.exit = engine_exit,
	
	#include "io.c"
	#include "time.c"
	#include "vector.c"
	#include "task.c"
	#include "tick.c"
	#include "draw.c"

/* function definitions */
	#else
	#include "io.c"
	#include "time.c"
	#include "vector.c"
	#include "task.c"
	#include "tick.c"
	#include "draw.c"
	
	void engine_init() {
		engine.task("initalizing engine");
			engine.sleep(1);
			engine.task("initalizing opengl");
			engine.task_done();
		engine.task_done();
		engine.tick();
	}
	
	void engine_exit() {
	}

	#endif
