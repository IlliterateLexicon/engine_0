#ifndef ENGINE_0
#define ENGINE_0

// dependencies
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// capi declarations
	// initalizeation
		void engine_init();
		void engine_exit();

	// io 
		void engine_debug(const char *, ...);
		void engine_warning(const char *, ...);
		void engine_error(const char *, ...);
		void engine_assert(bool, const char *, ...);

	// sleep
		void engine_sleep(long double);

	// vector
		// declare engine_vector type
			typedef struct {
				void ** elements; // array of elements
				size_t num_elements; // current #elements
				size_t max_elements; // maximum #elements
			} engine_vector;
		
		// declare vector methods
			engine_vector engine_vector_init(); // allocate new vector
			void engine_vector_free(engine_vector *); // unallocate vector
			void engine_vector_resize(engine_vector *, int); // reallocate vector
		
			void		engine_vector_set(engine_vector *, int, void *); // set index, increase size if index doesnt exist
			void *	engine_vector_get(engine_vector *, int); // get index return NULL if index doesnt exist
			void  	engine_vector_add(engine_vector *, void *); // get index return NULL if index doesnt exist
			void *	engine_vector_sub(engine_vector *); // set index, increase size if index doesnt exist
			size_t	engine_vector_len(engine_vector *); // return current highest index (that has a value)
	
// struct declaration (engine)
	// engine.vector struct declaration
		struct vector{
			engine_vector (*init)();											// create engine_vector
			void		(*free)(engine_vector *);							// free allocated mem
			void		(*set)(engine_vector *, int, void *); // set index
			void *	(*get)(engine_vector *, int);					// get index and return
			void		(*add)(engine_vector *, void *); // add to end of vector
			void *	(*sub)(engine_vector *);					// remove from end of vector 
			size_t	(*len)(engine_vector *);							// return highest set index
		};

	// engine struct declaration 
		struct engine {
			void (*init)();
			void (*exit)();

			void (*debug)(const char *, ...);
			void (*error)(const char *, ...);
			void (*warning)(const char *, ...);
			void (*assert)(bool, const char *, ...);

			void (*sleep)(long double seconds);
			struct vector vector;
		};

// struct initalization (engine)
	// vector initalization
		const struct vector engine_vector_struct = {
			.init = engine_vector_init,
			.free = engine_vector_free,

			.set = engine_vector_set,
			.get = engine_vector_get,
			.add = engine_vector_add,
			.sub = engine_vector_sub,
			.len = engine_vector_len
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
