# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/build"

# Include any dependencies generated for this target.
include ../comm/build/CMakeFiles/send_recv_fd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ../comm/build/CMakeFiles/send_recv_fd.dir/compiler_depend.make

# Include the progress variables for this target.
include ../comm/build/CMakeFiles/send_recv_fd.dir/progress.make

# Include the compile flags for this target's objects.
include ../comm/build/CMakeFiles/send_recv_fd.dir/flags.make

../comm/build/CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o: ../comm/build/CMakeFiles/send_recv_fd.dir/flags.make
../comm/build/CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o: ../comm/send_recv_fd.cpp
../comm/build/CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o: ../comm/build/CMakeFiles/send_recv_fd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ../comm/build/CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o"
	cd "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ../comm/build/CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o -MF CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o.d -o CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o -c "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/send_recv_fd.cpp"

../comm/build/CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.i"
	cd "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/send_recv_fd.cpp" > CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.i

../comm/build/CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.s"
	cd "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/send_recv_fd.cpp" -o CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.s

# Object files for target send_recv_fd
send_recv_fd_OBJECTS = \
"CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o"

# External object files for target send_recv_fd
send_recv_fd_EXTERNAL_OBJECTS =

../comm/build/libsend_recv_fd.so: ../comm/build/CMakeFiles/send_recv_fd.dir/send_recv_fd.cpp.o
../comm/build/libsend_recv_fd.so: ../comm/build/CMakeFiles/send_recv_fd.dir/build.make
../comm/build/libsend_recv_fd.so: ../comm/build/CMakeFiles/send_recv_fd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libsend_recv_fd.so"
	cd "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/build" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/send_recv_fd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
../comm/build/CMakeFiles/send_recv_fd.dir/build: ../comm/build/libsend_recv_fd.so
.PHONY : ../comm/build/CMakeFiles/send_recv_fd.dir/build

../comm/build/CMakeFiles/send_recv_fd.dir/clean:
	cd "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/build" && $(CMAKE_COMMAND) -P CMakeFiles/send_recv_fd.dir/cmake_clean.cmake
.PHONY : ../comm/build/CMakeFiles/send_recv_fd.dir/clean

../comm/build/CMakeFiles/send_recv_fd.dir/depend:
	cd "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src" "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm" "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/build" "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/build" "/media/tsungbao/琮1/files/Interview/Interview 2/群聯/竹南/src/comm/build/CMakeFiles/send_recv_fd.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : ../comm/build/CMakeFiles/send_recv_fd.dir/depend

