#! /bin/lua5.4

require("lib.make")

-- set vars
	-- directories
		src_dir = "./src"
		build_dir = "./build/"
		test_dir = src_dir .."/test/"
	
	-- files
		lib = build_dir .. "engine_0.so"
		header = build_dir .. "engine_0.h"
		test = test_dir .. "init.c"
		test_executable = build_dir .. "test"
		test_lib = "engine_0.so"

	-- compiler
		compiler = "gcc"
		
		compiler_flags =
			" -shared" ..
			" -fPIC" ..
			" -I".. build_dir

		compiler_libs = "-lm"

		compiler_test_flags =
			" -I" .. build_dir ..
			" -L" .. build_dir 

		compiler_test_libs =
			compiler_libs .. 
			" -l:" .. test_lib

-- targets
	-- build dir
		function make_build_dir()
			cmd("[ -d %s ] || mkdir %s", build_dir, build_dir)
		end

	-- header
		function make_header()
			make_build_dir()

			task("makeing header")
				-- parse depencies in plain text
					cmd("cat %s/init.h | sed -n '/#ifdef DEPENDENCIES/,/#else/{/#ifdef DEPENDENCIES/b;/#else/b;p}' | tr -d '\t' > %s",
						src_dir, header
					)	

				-- get header content from all files
					cmd("%s -E -P -x c src/init.h -o /dev/stdout | awk '{$1=$1};1' >> %s",
						compiler, header
					)	
			task_done()
		end

	-- lib
		function make_lib()
			make_build_dir()
			make_header()

			-- get modules (folders in src dir)
				modules = "" -- src/*/
				for dir in io.popen("ls -d ".. src_dir .."*/"):lines() do 
					if dir == test_dir then goto done end
					modules = modules .. string.format("%sinit.c ", dir)
					::done::
				end

			task("compileing shared object")
				cmd("%s %s %s -o %s %s",
					compiler, compiler_flags, compiler_libs, lib, modules
				)	
			task_done()
		end

	-- test
		function make_test()
			make_lib()
			task("compileing test")
				cmd("%s %s %s -o %s %s",
					compiler, compiler_test_flags, compiler_test_libs, test_executable, test
				)
			task_done()
					
			io.write("running test: \n")
			cmd("export LD_LIBRARY_PATH=%s/%s; %s", 
				os.getenv("PWD"),
				build_dir,
				test_executable
			)
		end

	-- clean
		function make_clean()
			task("cleaning build dir")
				cmd("[ -d %s ] && rm -dr %s",
				build_dir, build_dir
				)
			task_done()
		end

	-- git
		function make_git()
			io.write("input commit message: ")
			local msg = io.read()
			task("making commit")
				cmd("git add --all")
				cmd("git commit -am \"%s\"", msg)
			task_done()
		end

	-- make default target 
		make_default = make_lib
