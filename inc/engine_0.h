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

	// vector
		// declare engine_vector type
			typedef struct {
				void ** elements; // array of elements
				size_t num_elements; // current #elements
				size_t max_elements; // maximum #elements
			} engine_vector;
		
		// declare vector methods
			engine_vector engine_vector_init();
			void engine_vector_free(engine_vector *);
		
			void		engine_vector_set(engine_vector *, int, void *);
			void *	engine_vector_get(engine_vector *, int);
			void *	engine_vector_del(engine_vector *);
			void		engine_vector_add(engine_vector *, int);
			void *	engine_vector_sub(engine_vector *, void *);
			size_t	engine_vector_len(engine_vector *);
	
// struct declaration (engine)
	// engine.vector struct declaration
		struct vector{
			engine_vector (*init)();											// create engine_vector
			void		(*free)(engine_vector *);							// free allocated mem
			void		(*set)(engine_vector *, int, void *); // set index
			void *	(*get)(engine_vector *, int, void *); // get index and return
			void *	(*pop)(engine_vector *, int);					// get index and remove
			void		(*add)(engine_vector *, void *);			// add to end
			void *	(*sub)(engine_vector *, void *);			// remove from end
		};
			

	// engine struct declaration 
		struct engine {
			void (*init)();
			void (*exit)();

			void (*debug)(const char * message);
			void (*warning)(const char * message);
			void (*error)(const char * message);

			void (*sleep)(long double seconds);
			struct vector vector;
		};

// struct initalization (engine)
	// vector initalization
		const struct vector engine_vector_struct = {
			.init = engine_vector_init,
			.free = engine_vector_free
		};

	// engine initalization	
		const struct engine engine = {
			.init = engine_init,
			.exit = engine_exit,

			.debug = engine_debug,
			.warning = engine_warning,
			.error = engine_error,

			.sleep = engine_sleep,
			.vector = engine_vector_struct
		};

#endif
