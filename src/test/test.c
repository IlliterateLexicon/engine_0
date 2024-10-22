// engine test

#include <engine.h>
#include <stdio.h>

int main() {
	engine.init();
	engine.sleep(1);
	engine.warning("warn");
	engine.sleep(1);
	engine.exit();
}
