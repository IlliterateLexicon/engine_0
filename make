#! /bin/lua5.4

local build_dir = "build/"
local shared_object = "engine.so"

local header_dir = "inc/"
local header = "engine.h"

local test_source = "test.c"
local test_dir = "src/test/"
local test_executable = "test"
local test_script = "test.lua"

local compiler = "gcc"
local compiler_libs = 
	" -ldl"..
	" -llua"..
	" -lepoxy"..
	" -lglfw"
local compiler_flags =
	" -shared"..
	" -fPIC"..
	" -I"..header_dir

-- file size
	function fsize(file)
		local position = file:seek()
		local size = file:seek("end")
		file:seek("set", position)
		return size
	end
	
	function toend(file)
		return fsize(file) - file:seek()
	end

-- run command
	function run_command(format, ...)
		local cmd_str = string.format(format, ...)

		-- clear files
		io.open("/tmp/stdout", "w+"):close()
		io.open("/tmp/stderr", "w+"):close()
	
		-- get std handles
		local stdout = io.open("/tmp/stdout", "r")
		local stderr = io.open("/tmp/stderr", "r")

		-- run command 
		local cmd = io.popen(cmd_str .. " >> /tmp/stdout && echo -en LUA_MAKE_COMMAND_DONE >> /tmp/stderr")
		local error = "";

		-- read from files
			local exiting = false
			while true do
				if toend(stdout) > 0 then
					io.write(stdout:read(exiting and "*a" or  1))
				end
			
				if toend(stderr) > 0 then
					error = error .. stderr:read(exiting and "*a" or  1)
				end

				-- if exiting read rest of file and exit
				if exiting then break end
				exiting = (error == "LUA_MAKE_COMMAND_DONE")
			end
		
		stdout:close()
		stderr:close()
	end

-- define targets
	-- build:
		function make_build(cmd_fmt, ... )
			os.execute(string.format("[ -d %s ] || mkdir %s", build_dir, build_dir))
		end

	-- test:
		function make_ctest()
			make_lib()

			io.write("compileing c test: \n")
				run_command( "gcc -Iinc -L%s -l:%s %s %s%s -o %s%s",
					build_dir, 
					shared_object,
					compiler_libs,
					test_dir, test_source,
					build_dir, test_executable
				);

			io.write("running c test: \n")
				run_command("export LD_LIBRARY_PATH="..os.getenv("PWD").."/%s; %s./%s",
						build_dir, 
						build_dir, 
						test_executable 
				);
		end
		
		function make_test()
			make_lib()
			
			io.write("running lua test: \n")
				run_command( "export LUA_CPATH=\""..os.getenv("PWD").."/%s?.so\";lua5.4 %s%s",
					build_dir, test_dir, test_script
				)
		end

	-- lib:
		function make_lib()
			make_build()
			
			-- get modules
				modules = "" -- src/*/
				for dir in io.popen("ls -d src/*/"):lines() do 
					if dir == test_dir then goto done end
					modules = modules .. string.format("%sinit.c ", dir)
					::done::
				end

			io.write("compileing shared object: \n")
				run_command( "%s %s %s -o %s%s %s",
					compiler, compiler_libs, compiler_flags, build_dir, shared_object, modules
				)
		end

	-- clean:
		function make_clean()
			print("cleaning build dir: \n")
			os.execute(string.format("rm -dr %s", build_dir))
			make_build()
			make_test()
		end

-- identify targets
	case = {}
	for k,v in pairs(_G) do
		if type(v) == "function" and k:sub(1,5) == "make_" then
			case[k:sub(6)] = v
		end
	end

-- parse arguments
	local target_string = ""
	for k,v in pairs(case) do
		target_string = target_string .. "\n\t\t".. k
	end

	assert(#arg>0, "no targets passed.\n\tplease pass one of the following targets" .. target_string)
	for i,argument in ipairs(arg) do
		assert(case[argument], "\"" .. argument .. "\" is not a valid target.")
		case[argument]()
	end
