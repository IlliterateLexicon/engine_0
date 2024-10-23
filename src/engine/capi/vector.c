// memeory functions
	engine_vector engine_vector_init() {
		engine_vector vector;

		vector.num_elements = 0;
		vector.max_elements = 4;
		vector.elements = malloc(sizeof(void *) * vector.max_elements);

		return vector;
	}

	void engine_vector_resize(engine_vector * vector, int size) {
		void ** elements = realloc(vector -> elements, sizeof(void *) * size);
		engine_assert(elements, "reallocation failed");
		vector -> elements = elements;
		vector -> max_elements = size;
	}

	void engine_vector_free(engine_vector * vector) {
		// free vector
		free(vector -> elements);
	}

// info functions
	size_t engine_vector_len(engine_vector * vector) {
		int i = 1;
		while ( vector -> elements[vector -> max_elements - i] == NULL ) i++;
		return vector -> max_elements - i;
	}

// assignment functions
	void engine_vector_set(engine_vector * vector, int index,void * value ) {
		engine_assert(index >= 0, "cannot engine_vector_set at a negative index");
		
		//  resize vector if neccicary
			if ( index > vector -> max_elements ) {
				engine_vector_resize(vector, vector -> max_elements * 2);	
				engine_vector_set(vector, index, value);
				return; 
			}

		vector -> elements[index] = value; // assign value
	}

	void * engine_vector_get(engine_vector * vector, int index) {
		engine_assert(index >= 0, "cannot get a negative index");
		if ( index > vector -> max_elements ) return NULL;
		return vector -> elements[index];
	}

	void engine_vector_add(engine_vector * vector, void * value) {
		engine_vector_set(vector, engine_vector_len(vector)+1, value);
	}
	
	void * engine_vector_sub(engine_vector * vector) {
		void * value = engine_vector_get(vector, engine_vector_len(vector));
		engine_vector_set(vector, engine_vector_len(vector), NULL);
		return value;
	}




