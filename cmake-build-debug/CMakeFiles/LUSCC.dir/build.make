# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /manual_sorce/usr/local/bin/cmake

# The command to remove a file.
RM = /manual_sorce/usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jrinder/LUSCC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jrinder/LUSCC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LUSCC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LUSCC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LUSCC.dir/flags.make

CMakeFiles/LUSCC.dir/main.c.o: CMakeFiles/LUSCC.dir/flags.make
CMakeFiles/LUSCC.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jrinder/LUSCC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LUSCC.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LUSCC.dir/main.c.o -c /home/jrinder/LUSCC/main.c

CMakeFiles/LUSCC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LUSCC.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jrinder/LUSCC/main.c > CMakeFiles/LUSCC.dir/main.c.i

CMakeFiles/LUSCC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LUSCC.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jrinder/LUSCC/main.c -o CMakeFiles/LUSCC.dir/main.c.s

CMakeFiles/LUSCC.dir/scanner.c.o: CMakeFiles/LUSCC.dir/flags.make
CMakeFiles/LUSCC.dir/scanner.c.o: ../scanner.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jrinder/LUSCC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LUSCC.dir/scanner.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LUSCC.dir/scanner.c.o -c /home/jrinder/LUSCC/scanner.c

CMakeFiles/LUSCC.dir/scanner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LUSCC.dir/scanner.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jrinder/LUSCC/scanner.c > CMakeFiles/LUSCC.dir/scanner.c.i

CMakeFiles/LUSCC.dir/scanner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LUSCC.dir/scanner.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jrinder/LUSCC/scanner.c -o CMakeFiles/LUSCC.dir/scanner.c.s

# Object files for target LUSCC
LUSCC_OBJECTS = \
"CMakeFiles/LUSCC.dir/main.c.o" \
"CMakeFiles/LUSCC.dir/scanner.c.o"

# External object files for target LUSCC
LUSCC_EXTERNAL_OBJECTS =

LUSCC: CMakeFiles/LUSCC.dir/main.c.o
LUSCC: CMakeFiles/LUSCC.dir/scanner.c.o
LUSCC: CMakeFiles/LUSCC.dir/build.make
LUSCC: CMakeFiles/LUSCC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jrinder/LUSCC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable LUSCC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LUSCC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LUSCC.dir/build: LUSCC

.PHONY : CMakeFiles/LUSCC.dir/build

CMakeFiles/LUSCC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LUSCC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LUSCC.dir/clean

CMakeFiles/LUSCC.dir/depend:
	cd /home/jrinder/LUSCC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jrinder/LUSCC /home/jrinder/LUSCC /home/jrinder/LUSCC/cmake-build-debug /home/jrinder/LUSCC/cmake-build-debug /home/jrinder/LUSCC/cmake-build-debug/CMakeFiles/LUSCC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LUSCC.dir/depend

