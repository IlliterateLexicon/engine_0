#ifndef ENGINE_0
#define ENGINE_0

// dependencies
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <math.h>
#include <time.h>

// capi declarations
	// initalizeation
		void engine_init();
		void engine_exit();

	// io 
		void engine_debug();
		void engine_warning();
		void engine_error();

	// sleep
		void engine_sleep();

// struct declaration 
	static struct {
		void (*init)();
		void (*exit)();

		void (*debug)(const char * message);
		void (*warning)(const char * message);
		void (*error)(const char * message);

		void (*sleep)(long double seconds);
	} 

// struct  initalization (struct engine)
	engine = {
		engine_init,
		engine_exit,

		engine_debug,
		engine_warning,
		engine_error,

		engine_sleep
	};
#endif
