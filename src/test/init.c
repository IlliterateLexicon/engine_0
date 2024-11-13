// engine test
#include <engine_0.h>

// main
int main() {
	engine.init();
	
	engine_vector position;

	engine.vector.alloc(&position);
	engine.vector.set(&position, 3, "this is very cool");

	engine.debug("%s", engine.vector.get(&position, 3));
	engine.debug("hello engine 0");

	engine.vector.free(&position);
	
	engine.exit();
}
