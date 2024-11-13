
/*| header declartions |*/
	#if defined HEADER 
	#include "io.c"
	#include "time.c"
	#include "vector.c"

	void engine_init();
	void engine_exit();

/*| struct declarations |*/
	#elif defined STRUCT 
	void (*init)();
	void (*exit)();
	
	#include "io.c"
	#include "time.c"
	#include "vector.c"

/*| struct initalizations |*/ 
	#elif defined STRUCT_INIT 
	.init = engine_init,
	.exit = engine_exit,
	#include "io.c"
	#include "time.c"
	#include "vector.c"

/* function definitions */
	#else
	#include "io.c"
	#include "time.c"
	#include "vector.c"
	
	void engine_init() {
	}
	
	void engine_exit() {
	}

	#endif
