# engine_0
### a game engine written in c and lua

## dependencies
	c lua5.4 gcc

## compile and test the project
to compile and test run the following in a bash terminal
```bash
	git clone --recursive https://github.com/illiterateLexicon/engine_0
	cd engine_0	
	lua make test
```

### Then  
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


