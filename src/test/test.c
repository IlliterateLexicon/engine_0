// engine test
#include <engine_0.h>

int main() {
	engine.init();

	engine_vector position = engine.vector.init();
	engine.vector.add(&position, (void *)123);

	engine.sleep(1);
	engine.debug("hello engine 0");
	engine.debug("hello engine %i", engine_vector_get(&position, 0));
	engine.debug("hello engine %i", engine_vector_sub(&position));
	engine.sleep(1);
	
	engine.vector.free(&position);

	engine.exit();
}
