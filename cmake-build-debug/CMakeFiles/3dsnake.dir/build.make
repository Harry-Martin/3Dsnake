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
CMAKE_COMMAND = /snap/clion/114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/114/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/harry/dev/me/3dsnake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/harry/dev/me/3dsnake/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3dsnake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3dsnake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3dsnake.dir/flags.make

CMakeFiles/3dsnake.dir/src/main.cpp.o: CMakeFiles/3dsnake.dir/flags.make
CMakeFiles/3dsnake.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/dev/me/3dsnake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3dsnake.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3dsnake.dir/src/main.cpp.o -c /home/harry/dev/me/3dsnake/src/main.cpp

CMakeFiles/3dsnake.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3dsnake.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/dev/me/3dsnake/src/main.cpp > CMakeFiles/3dsnake.dir/src/main.cpp.i

CMakeFiles/3dsnake.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3dsnake.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/dev/me/3dsnake/src/main.cpp -o CMakeFiles/3dsnake.dir/src/main.cpp.s

CMakeFiles/3dsnake.dir/src/Window.cpp.o: CMakeFiles/3dsnake.dir/flags.make
CMakeFiles/3dsnake.dir/src/Window.cpp.o: ../src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/dev/me/3dsnake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/3dsnake.dir/src/Window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3dsnake.dir/src/Window.cpp.o -c /home/harry/dev/me/3dsnake/src/Window.cpp

CMakeFiles/3dsnake.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3dsnake.dir/src/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/dev/me/3dsnake/src/Window.cpp > CMakeFiles/3dsnake.dir/src/Window.cpp.i

CMakeFiles/3dsnake.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3dsnake.dir/src/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/dev/me/3dsnake/src/Window.cpp -o CMakeFiles/3dsnake.dir/src/Window.cpp.s

CMakeFiles/3dsnake.dir/src/Shader.cpp.o: CMakeFiles/3dsnake.dir/flags.make
CMakeFiles/3dsnake.dir/src/Shader.cpp.o: ../src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/dev/me/3dsnake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/3dsnake.dir/src/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3dsnake.dir/src/Shader.cpp.o -c /home/harry/dev/me/3dsnake/src/Shader.cpp

CMakeFiles/3dsnake.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3dsnake.dir/src/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/dev/me/3dsnake/src/Shader.cpp > CMakeFiles/3dsnake.dir/src/Shader.cpp.i

CMakeFiles/3dsnake.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3dsnake.dir/src/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/dev/me/3dsnake/src/Shader.cpp -o CMakeFiles/3dsnake.dir/src/Shader.cpp.s

# Object files for target 3dsnake
3dsnake_OBJECTS = \
"CMakeFiles/3dsnake.dir/src/main.cpp.o" \
"CMakeFiles/3dsnake.dir/src/Window.cpp.o" \
"CMakeFiles/3dsnake.dir/src/Shader.cpp.o"

# External object files for target 3dsnake
3dsnake_EXTERNAL_OBJECTS =

3dsnake: CMakeFiles/3dsnake.dir/src/main.cpp.o
3dsnake: CMakeFiles/3dsnake.dir/src/Window.cpp.o
3dsnake: CMakeFiles/3dsnake.dir/src/Shader.cpp.o
3dsnake: CMakeFiles/3dsnake.dir/build.make
3dsnake: /usr/lib/x86_64-linux-gnu/libglfw.so.3.2
3dsnake: /usr/lib/x86_64-linux-gnu/libGLX.so
3dsnake: /usr/lib/x86_64-linux-gnu/libOpenGL.so
3dsnake: CMakeFiles/3dsnake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/harry/dev/me/3dsnake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable 3dsnake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3dsnake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3dsnake.dir/build: 3dsnake

.PHONY : CMakeFiles/3dsnake.dir/build

CMakeFiles/3dsnake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3dsnake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3dsnake.dir/clean

CMakeFiles/3dsnake.dir/depend:
	cd /home/harry/dev/me/3dsnake/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/harry/dev/me/3dsnake /home/harry/dev/me/3dsnake /home/harry/dev/me/3dsnake/cmake-build-debug /home/harry/dev/me/3dsnake/cmake-build-debug /home/harry/dev/me/3dsnake/cmake-build-debug/CMakeFiles/3dsnake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3dsnake.dir/depend

