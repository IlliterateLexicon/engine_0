/* header definitions */
	#if defined HEADER
	// engine_vector type ( a vector object )
	typedef struct {
		bool allocated;
		int max_elements;
		void ** elements;
	} engine_vector;
	
	// vector memory functions
	void engine_vector_alloc(engine_vector *);
	void engine_vector_realloc(engine_vector *, size_t);
	size_t engine_vector_size(engine_vector *);
	void engine_vector_free(engine_vector *);

	// set / get
	void   engine_vector_set(engine_vector *, size_t, void *);
	void * engine_vector_get(engine_vector *, size_t);

	// add / rem
	void   engine_vector_add(engine_vector *, void *);
	void * engine_vector_rem(engine_vector *);

	// other
	size_t engine_vector_length(engine_vector *);

	// engine_vector
	struct engine_vector {
		// memeory 
			void (* alloc)();
			void (* realloc)();
			size_t (* size)();
			void (* free)();

		// set / get
			void   (* set)();
			void * (* get)();

		// add / rem 
			void   (* add)();
			void * (* rem)();
		
		// other	
			size_t (* length)();
	};

	const struct engine_vector engine_vector_struct = { 
		// memory
		engine_vector_alloc,
		engine_vector_realloc,
		engine_vector_size,
		engine_vector_free,
	
		// set / get
		engine_vector_set,
		engine_vector_get,
		
		// add / rem 
		engine_vector_add,
		engine_vector_rem,

		// other
		engine_vector_length,
	};

/* struct definitions */
	#elif defined STRUCT
	const struct engine_vector vector; // engine.vector

/*| struct initalization |*/
	#elif defined STRUCT_INIT
		.vector = engine_vector_struct,	// engine.vector

/*| definitions |*/
	#else
		// memory functions
			// engine.vector.alloc()
			void engine_vector_alloc(engine_vector * vector) {
				engine.assert(!vector -> allocated, "vector allready allocated");
				vector -> max_elements = 4;
				vector -> elements = malloc(sizeof(void *) * vector -> max_elements);
				vector -> allocated = true;
			}

			// engine.vector.realloc()
			void engine_vector_realloc(engine_vector * vector, size_t new_max) {
				printf("reallocating vector from %i to %i", vector -> max_elements, new_max);
				vector -> elements = realloc(vector -> elements, sizeof(void *) * new_max);
				vector -> max_elements = new_max;
			}

			// engine.vector.size()
			size_t engine_vector_size(engine_vector * vector) {
				return sizeof(vector);
			}
		
			// engine.vector.length()
			size_t engine_vector_length(engine_vector * vector) {
				if ( ! vector -> allocated ) { engine.error("cannot return length, vector unallocated"); } // vector unallocated
				size_t i = 1;
				while ( vector -> elements[ vector -> max_elements -i ] == NULL ) i++;
				return (vector -> max_elements - i) + 1;
			}
			
			// engine.vector.free()
			void engine_vector_free(engine_vector * vector) {
				free(vector -> elements);
			}

		// set / get
			void engine_vector_set(engine_vector * vector, size_t index, void * value) {
				size_t new_max = vector -> max_elements;
				while (new_max -1 < index) { new_max = new_max * 2; }
				if ( new_max != vector -> max_elements ) { engine_vector_realloc(vector, new_max); }
				vector -> elements[index] = value;
			}
			
			void * engine_vector_get(engine_vector * vector, size_t index) {
				return vector -> elements[index];
			}
		
		// add / rem 
			void engine_vector_add(engine_vector * vector, void * value) {
				engine.vector.set(vector, engine.vector.length(vector), value);
			}
			
			void * engine_vector_rem(engine_vector * vector) {
				void * ret = engine.vector.get(vector, engine.vector.length(vector));
				engine.vector.set(vector, engine.vector.length(vector)-1, NULL);
				return ret;
			}
	#endif
