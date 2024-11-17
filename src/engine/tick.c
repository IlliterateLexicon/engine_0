/*| header |*/
	#if defined HEADER
	void engine_tick();

/*| struct |*/
	#elif defined STRUCT
	bool ticking;	
	void (*tick)();

/*| struct init |*/
	#elif defined STRUCT_INIT 
	.ticking = false,
	.tick = engine_tick,

/*| definitions |*/
	#else
		
	void engine_tick() {
		if ( ! engine.ticking ) goto end;
		printf("tick\n");
		end:
		engine_tick();
	}

	#endif
