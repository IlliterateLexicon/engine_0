// header
	#if defined HEADER 
	void engine_sleep(long double seconds_nanoseconds);

// struct declarations
	#elif defined STRUCT
	void (*sleep)(long double);

// struct initalizations
	#elif defined STRUCT_INIT
	.sleep = engine_sleep,

// definitions
	#else
	
	void engine_sleep(long double seconds_nanoseconds) {
		// convert from seconds_nanoseconds (e.g 1.231233123L) to seconds and nanoseconds then run nanosleep
		struct timespec engine_time = { (long unsigned int) floor(seconds_nanoseconds), (long unsigned int) floor(fmod(seconds_nanoseconds, 1) * 1000000000) };
		nanosleep(&engine_time, &engine_time);
	}

	#endif
