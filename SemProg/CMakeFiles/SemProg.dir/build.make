# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/antag0nist/Programming/SysProg/curs_4/SemProg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antag0nist/Programming/SysProg/curs_4/SemProg

# Include any dependencies generated for this target.
include CMakeFiles/SemProg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SemProg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SemProg.dir/flags.make

CMakeFiles/SemProg.dir/src/main.c.o: CMakeFiles/SemProg.dir/flags.make
CMakeFiles/SemProg.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antag0nist/Programming/SysProg/curs_4/SemProg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SemProg.dir/src/main.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SemProg.dir/src/main.c.o   -c /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/main.c

CMakeFiles/SemProg.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SemProg.dir/src/main.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/main.c > CMakeFiles/SemProg.dir/src/main.c.i

CMakeFiles/SemProg.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SemProg.dir/src/main.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/main.c -o CMakeFiles/SemProg.dir/src/main.c.s

CMakeFiles/SemProg.dir/src/core.c.o: CMakeFiles/SemProg.dir/flags.make
CMakeFiles/SemProg.dir/src/core.c.o: src/core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antag0nist/Programming/SysProg/curs_4/SemProg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SemProg.dir/src/core.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SemProg.dir/src/core.c.o   -c /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/core.c

CMakeFiles/SemProg.dir/src/core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SemProg.dir/src/core.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/core.c > CMakeFiles/SemProg.dir/src/core.c.i

CMakeFiles/SemProg.dir/src/core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SemProg.dir/src/core.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/core.c -o CMakeFiles/SemProg.dir/src/core.c.s

CMakeFiles/SemProg.dir/src/log.c.o: CMakeFiles/SemProg.dir/flags.make
CMakeFiles/SemProg.dir/src/log.c.o: src/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antag0nist/Programming/SysProg/curs_4/SemProg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SemProg.dir/src/log.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SemProg.dir/src/log.c.o   -c /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/log.c

CMakeFiles/SemProg.dir/src/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SemProg.dir/src/log.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/log.c > CMakeFiles/SemProg.dir/src/log.c.i

CMakeFiles/SemProg.dir/src/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SemProg.dir/src/log.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antag0nist/Programming/SysProg/curs_4/SemProg/src/log.c -o CMakeFiles/SemProg.dir/src/log.c.s

# Object files for target SemProg
SemProg_OBJECTS = \
"CMakeFiles/SemProg.dir/src/main.c.o" \
"CMakeFiles/SemProg.dir/src/core.c.o" \
"CMakeFiles/SemProg.dir/src/log.c.o"

# External object files for target SemProg
SemProg_EXTERNAL_OBJECTS =

bin/SemProg: CMakeFiles/SemProg.dir/src/main.c.o
bin/SemProg: CMakeFiles/SemProg.dir/src/core.c.o
bin/SemProg: CMakeFiles/SemProg.dir/src/log.c.o
bin/SemProg: CMakeFiles/SemProg.dir/build.make
bin/SemProg: CMakeFiles/SemProg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/antag0nist/Programming/SysProg/curs_4/SemProg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable bin/SemProg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SemProg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SemProg.dir/build: bin/SemProg

.PHONY : CMakeFiles/SemProg.dir/build

CMakeFiles/SemProg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SemProg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SemProg.dir/clean

CMakeFiles/SemProg.dir/depend:
	cd /home/antag0nist/Programming/SysProg/curs_4/SemProg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antag0nist/Programming/SysProg/curs_4/SemProg /home/antag0nist/Programming/SysProg/curs_4/SemProg /home/antag0nist/Programming/SysProg/curs_4/SemProg /home/antag0nist/Programming/SysProg/curs_4/SemProg /home/antag0nist/Programming/SysProg/curs_4/SemProg/CMakeFiles/SemProg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SemProg.dir/depend

