#include "io.c"
#include "sleep.c"

// engine.init() 
	void engine_init() { 
		engine_debug("initalized engine");
	}  
	
// engine.exit()
	void engine_exit(int status) { 
		engine_debug("exiting engine");
		
		// return zero if status isnt 0 or 1 (if argument wasnt passed)
		exit( status == 0 || status == 1 ? status : 0);
	}

