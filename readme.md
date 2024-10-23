# engine_0
### a game engine written in c and lua

## compile the project
to compile simply run the following commands
```bash
	git clone https://github.com/illiterateLexicon/engine_0
	cd engine_0	
	lua make lib 
```

## how to use 

### NOTE
the capi is what is being made first the lua api will then be wrapped around the capi

### CAPI
```c
	// load declarations
	#include "engine_0.h" // load the definitions 
		
	int main() {
		engine.init();
		
		engine.sleep(1);
		engine.debug("hello engine 0");
		engine.sleep(1);

		engine.exit();
	}
```

TODO: ADD API LIST


