# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zirael/Проекты/C++/cppLab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zirael/Проекты/C++/cppLab2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cppLab2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cppLab2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppLab2.dir/flags.make

CMakeFiles/cppLab2.dir/main.cpp.o: CMakeFiles/cppLab2.dir/flags.make
CMakeFiles/cppLab2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zirael/Проекты/C++/cppLab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppLab2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cppLab2.dir/main.cpp.o -c /Users/zirael/Проекты/C++/cppLab2/main.cpp

CMakeFiles/cppLab2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppLab2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zirael/Проекты/C++/cppLab2/main.cpp > CMakeFiles/cppLab2.dir/main.cpp.i

CMakeFiles/cppLab2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppLab2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zirael/Проекты/C++/cppLab2/main.cpp -o CMakeFiles/cppLab2.dir/main.cpp.s

# Object files for target cppLab2
cppLab2_OBJECTS = \
"CMakeFiles/cppLab2.dir/main.cpp.o"

# External object files for target cppLab2
cppLab2_EXTERNAL_OBJECTS =

cppLab2: CMakeFiles/cppLab2.dir/main.cpp.o
cppLab2: CMakeFiles/cppLab2.dir/build.make
cppLab2: CMakeFiles/cppLab2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zirael/Проекты/C++/cppLab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cppLab2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppLab2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppLab2.dir/build: cppLab2

.PHONY : CMakeFiles/cppLab2.dir/build

CMakeFiles/cppLab2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppLab2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppLab2.dir/clean

CMakeFiles/cppLab2.dir/depend:
	cd /Users/zirael/Проекты/C++/cppLab2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zirael/Проекты/C++/cppLab2 /Users/zirael/Проекты/C++/cppLab2 /Users/zirael/Проекты/C++/cppLab2/cmake-build-debug /Users/zirael/Проекты/C++/cppLab2/cmake-build-debug /Users/zirael/Проекты/C++/cppLab2/cmake-build-debug/CMakeFiles/cppLab2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppLab2.dir/depend
