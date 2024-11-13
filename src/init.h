#define HEADER 
	#ifdef DEPENDENCIES 
		// this section is appended to the top of the header file as plain text
		#include <stdio.h>
		#include <stdlib.h>
		#include <stddef.h>
		#include <stdarg.h>
		#include <stdbool.h>
		#include <math.h>
		#include <time.h>
		#include <unistd.h>
	#else
		#include "init.c"
	#endif
#undef HEADER 

#define STRUCT
	#include "init.c"
#undef STRUCT

#define STRUCT_INIT
	#include "init.c"
#undef STRUCT_INIT
