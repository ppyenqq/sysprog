# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/patrickkoenig/Documents/Systemprog/sysprog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/patrickkoenig/Documents/Systemprog/sysprog/build

# Include any dependencies generated for this target.
include src/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include src/lib/googletest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include src/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make
src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: ../src/lib/googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patrickkoenig/Documents/Systemprog/sysprog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o"
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o -c /Users/patrickkoenig/Documents/Systemprog/sysprog/src/lib/googletest/googletest/src/gtest-all.cc

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i"
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patrickkoenig/Documents/Systemprog/sysprog/src/lib/googletest/googletest/src/gtest-all.cc > CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s"
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patrickkoenig/Documents/Systemprog/sysprog/src/lib/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires:

.PHONY : src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f src/lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build
.PHONY : src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o


src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make
src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../src/lib/googletest/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patrickkoenig/Documents/Systemprog/sysprog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /Users/patrickkoenig/Documents/Systemprog/sysprog/src/lib/googletest/googlemock/src/gmock-all.cc

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patrickkoenig/Documents/Systemprog/sysprog/src/lib/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patrickkoenig/Documents/Systemprog/sysprog/src/lib/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:

.PHONY : src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f src/lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

src/lib/googletest/googlemock/libgmock.a: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o
src/lib/googletest/googlemock/libgmock.a: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
src/lib/googletest/googlemock/libgmock.a: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make
src/lib/googletest/googlemock/libgmock.a: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/patrickkoenig/Documents/Systemprog/sysprog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgmock.a"
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lib/googletest/googlemock/CMakeFiles/gmock.dir/build: src/lib/googletest/googlemock/libgmock.a

.PHONY : src/lib/googletest/googlemock/CMakeFiles/gmock.dir/build

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/requires: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
src/lib/googletest/googlemock/CMakeFiles/gmock.dir/requires: src/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

.PHONY : src/lib/googletest/googlemock/CMakeFiles/gmock.dir/requires

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : src/lib/googletest/googlemock/CMakeFiles/gmock.dir/clean

src/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /Users/patrickkoenig/Documents/Systemprog/sysprog/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/patrickkoenig/Documents/Systemprog/sysprog /Users/patrickkoenig/Documents/Systemprog/sysprog/src/lib/googletest/googlemock /Users/patrickkoenig/Documents/Systemprog/sysprog/build /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock /Users/patrickkoenig/Documents/Systemprog/sysprog/build/src/lib/googletest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend
