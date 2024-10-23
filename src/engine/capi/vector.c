engine_vector engine_vector_init() {
	engine_vector vector;

	vector.num_elements = 0;
	vector.max_elements = 4;
	vector.elements = malloc(sizeof(void *) * vector.max_elements);

	return vector;
}

void engine_vector_free(engine_vector * vector) {
	// free vector
	free(vector -> elements);
}

