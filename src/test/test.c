// engine test
#include <engine_0.h>

int main() {
	engine.init();

	engine_vector position = engine.vector.init();

	engine.vector.set(&position, 1, (void *)"testing");

	engine.sleep(1);
	engine.debug("hello engine 0");
	engine.sleep(1);
	
	engine.vector.free(&position);

	engine.exit();
}
