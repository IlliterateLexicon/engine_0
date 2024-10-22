# engine_0
### a game engine written in c heavily utilizeing the lua capi

## compile the project
to compile simply run the following commands
```bash
	git clone https://github.com/illiterateLexicon/engine_0
	cd engine_0	
	lua make test
```

or this combinded command
```bash
	git clone https://github.com/illiterateLexicon/engine_0; cd engine_0; lua make test
```

## how to use 
### LuaAPI
```lua
	-- replace './' with the folder containing the shared object file (possibly engine_0/build)
	package.cpath = package.cpath .. ";;./?.so"

	local engine = require("engine_0") -- require the engine table
	
	engine.init() -- initalize the engine 
	engine.exit() -- exit the engine
```

### CAPI
```c
	#include "engine_0.h" // load the definitions 
		
	int main() {
		engine.init();
		engine.exit();
	}
```

TODO: ADD API LIST


