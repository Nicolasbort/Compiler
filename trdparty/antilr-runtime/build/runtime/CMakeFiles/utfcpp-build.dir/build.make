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
CMAKE_SOURCE_DIR = /home/nicolas/Desktop/compilador/trdparty/antilr-runtime

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build

# Utility rule file for utfcpp-build.

# Include the progress variables for this target.
include runtime/CMakeFiles/utfcpp-build.dir/progress.make

runtime/CMakeFiles/utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-build


runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Performing build step for 'utfcpp'"
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-build && $(MAKE)
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-build && /usr/bin/cmake -E touch /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-build

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure: runtime/utfcpp-prefix/tmp/utfcpp-cfgcmd.txt
runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-skip-update
runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing configure step for 'utfcpp'"
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-build && /usr/bin/cmake -DCMAKE_INSTALL_PREFIX=/home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/thirdparty/utfcpp/install -Dgtest_force_shared_crt=ON "-GUnix Makefiles" /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/thirdparty/utfcpp
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-build && /usr/bin/cmake -E touch /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-skip-update: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Skipping update step for 'utfcpp'"
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/thirdparty/utfcpp && /usr/bin/cmake -E echo_append

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No patch step for 'utfcpp'"
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E echo_append
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E touch /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-gitinfo.txt
runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing download step (git clone) for 'utfcpp'"
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/thirdparty && /usr/bin/cmake -P /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/tmp/utfcpp-gitclone.cmake
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/thirdparty && /usr/bin/cmake -E touch /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'utfcpp'"
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E make_directory /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/thirdparty/utfcpp
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E make_directory /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-build
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E make_directory /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E make_directory /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/tmp
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E make_directory /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-stamp
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E make_directory /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E make_directory /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-stamp
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && /usr/bin/cmake -E touch /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-mkdir

utfcpp-build: runtime/CMakeFiles/utfcpp-build
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-build
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-skip-update
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-mkdir
utfcpp-build: runtime/CMakeFiles/utfcpp-build.dir/build.make

.PHONY : utfcpp-build

# Rule to build all files generated by this target.
runtime/CMakeFiles/utfcpp-build.dir/build: utfcpp-build

.PHONY : runtime/CMakeFiles/utfcpp-build.dir/build

runtime/CMakeFiles/utfcpp-build.dir/clean:
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime && $(CMAKE_COMMAND) -P CMakeFiles/utfcpp-build.dir/cmake_clean.cmake
.PHONY : runtime/CMakeFiles/utfcpp-build.dir/clean

runtime/CMakeFiles/utfcpp-build.dir/depend:
	cd /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nicolas/Desktop/compilador/trdparty/antilr-runtime /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/runtime /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime /home/nicolas/Desktop/compilador/trdparty/antilr-runtime/build/runtime/CMakeFiles/utfcpp-build.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : runtime/CMakeFiles/utfcpp-build.dir/depend
