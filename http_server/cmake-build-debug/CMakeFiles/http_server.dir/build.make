# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/valery/Projects/repo/C_Playground/http_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valery/Projects/repo/C_Playground/http_server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/http_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/http_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/http_server.dir/flags.make

CMakeFiles/http_server.dir/main.c.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valery/Projects/repo/C_Playground/http_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/http_server.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/http_server.dir/main.c.o   -c /home/valery/Projects/repo/C_Playground/http_server/main.c

CMakeFiles/http_server.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_server.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/valery/Projects/repo/C_Playground/http_server/main.c > CMakeFiles/http_server.dir/main.c.i

CMakeFiles/http_server.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_server.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/valery/Projects/repo/C_Playground/http_server/main.c -o CMakeFiles/http_server.dir/main.c.s

CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.o: /home/valery/Projects/repo/C_Playground/memory_alloc/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valery/Projects/repo/C_Playground/http_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.o   -c /home/valery/Projects/repo/C_Playground/memory_alloc/main.c

CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/valery/Projects/repo/C_Playground/memory_alloc/main.c > CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.i

CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/valery/Projects/repo/C_Playground/memory_alloc/main.c -o CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.s

# Object files for target http_server
http_server_OBJECTS = \
"CMakeFiles/http_server.dir/main.c.o" \
"CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.o"

# External object files for target http_server
http_server_EXTERNAL_OBJECTS =

http_server: CMakeFiles/http_server.dir/main.c.o
http_server: CMakeFiles/http_server.dir/home/valery/Projects/repo/C_Playground/memory_alloc/main.c.o
http_server: CMakeFiles/http_server.dir/build.make
http_server: CMakeFiles/http_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/valery/Projects/repo/C_Playground/http_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable http_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/http_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/http_server.dir/build: http_server

.PHONY : CMakeFiles/http_server.dir/build

CMakeFiles/http_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/http_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/http_server.dir/clean

CMakeFiles/http_server.dir/depend:
	cd /home/valery/Projects/repo/C_Playground/http_server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valery/Projects/repo/C_Playground/http_server /home/valery/Projects/repo/C_Playground/http_server /home/valery/Projects/repo/C_Playground/http_server/cmake-build-debug /home/valery/Projects/repo/C_Playground/http_server/cmake-build-debug /home/valery/Projects/repo/C_Playground/http_server/cmake-build-debug/CMakeFiles/http_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/http_server.dir/depend
