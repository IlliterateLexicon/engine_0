// header declaration
	#if defined HEADER 
	#include "engine/init.c"

// struct declaration
	#elif defined STRUCT
	struct engine { 
		#include "engine/init.c"
	};

// struct initalization
	#elif defined STRUCT_INIT

	struct engine engine = {
		#include "engine/init.c"
	};

// definition
	#else
		#include <engine_0.h>
		#include "engine/init.c"
	#endif
