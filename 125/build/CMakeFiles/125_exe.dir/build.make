# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/fade0329/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/fade0329/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fade0329/leetcode/125

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fade0329/leetcode/125/build

# Include any dependencies generated for this target.
include CMakeFiles/125_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/125_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/125_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/125_exe.dir/flags.make

CMakeFiles/125_exe.dir/main.cpp.o: CMakeFiles/125_exe.dir/flags.make
CMakeFiles/125_exe.dir/main.cpp.o: /home/fade0329/leetcode/125/main.cpp
CMakeFiles/125_exe.dir/main.cpp.o: CMakeFiles/125_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fade0329/leetcode/125/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/125_exe.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/125_exe.dir/main.cpp.o -MF CMakeFiles/125_exe.dir/main.cpp.o.d -o CMakeFiles/125_exe.dir/main.cpp.o -c /home/fade0329/leetcode/125/main.cpp

CMakeFiles/125_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/125_exe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fade0329/leetcode/125/main.cpp > CMakeFiles/125_exe.dir/main.cpp.i

CMakeFiles/125_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/125_exe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fade0329/leetcode/125/main.cpp -o CMakeFiles/125_exe.dir/main.cpp.s

CMakeFiles/125_exe.dir/helpers.cpp.o: CMakeFiles/125_exe.dir/flags.make
CMakeFiles/125_exe.dir/helpers.cpp.o: /home/fade0329/leetcode/125/helpers.cpp
CMakeFiles/125_exe.dir/helpers.cpp.o: CMakeFiles/125_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fade0329/leetcode/125/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/125_exe.dir/helpers.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/125_exe.dir/helpers.cpp.o -MF CMakeFiles/125_exe.dir/helpers.cpp.o.d -o CMakeFiles/125_exe.dir/helpers.cpp.o -c /home/fade0329/leetcode/125/helpers.cpp

CMakeFiles/125_exe.dir/helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/125_exe.dir/helpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fade0329/leetcode/125/helpers.cpp > CMakeFiles/125_exe.dir/helpers.cpp.i

CMakeFiles/125_exe.dir/helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/125_exe.dir/helpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fade0329/leetcode/125/helpers.cpp -o CMakeFiles/125_exe.dir/helpers.cpp.s

# Object files for target 125_exe
125_exe_OBJECTS = \
"CMakeFiles/125_exe.dir/main.cpp.o" \
"CMakeFiles/125_exe.dir/helpers.cpp.o"

# External object files for target 125_exe
125_exe_EXTERNAL_OBJECTS =

125_exe: CMakeFiles/125_exe.dir/main.cpp.o
125_exe: CMakeFiles/125_exe.dir/helpers.cpp.o
125_exe: CMakeFiles/125_exe.dir/build.make
125_exe: CMakeFiles/125_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/fade0329/leetcode/125/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 125_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/125_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/125_exe.dir/build: 125_exe
.PHONY : CMakeFiles/125_exe.dir/build

CMakeFiles/125_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/125_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/125_exe.dir/clean

CMakeFiles/125_exe.dir/depend:
	cd /home/fade0329/leetcode/125/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fade0329/leetcode/125 /home/fade0329/leetcode/125 /home/fade0329/leetcode/125/build /home/fade0329/leetcode/125/build /home/fade0329/leetcode/125/build/CMakeFiles/125_exe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/125_exe.dir/depend

