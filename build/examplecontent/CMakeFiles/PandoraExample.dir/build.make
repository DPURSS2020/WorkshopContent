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
CMAKE_COMMAND = /cvmfs/dune.opensciencegrid.org/products/dune/cmake/v3_14_3/Linux64bit+3.10-2.17/bin/cmake

# The command to remove a file.
RM = /cvmfs/dune.opensciencegrid.org/products/dune/cmake/v3_14_3/Linux64bit+3.10-2.17/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build

# Include any dependencies generated for this target.
include examplecontent/CMakeFiles/PandoraExample.dir/depend.make

# Include the progress variables for this target.
include examplecontent/CMakeFiles/PandoraExample.dir/progress.make

# Include the compile flags for this target's objects.
include examplecontent/CMakeFiles/PandoraExample.dir/flags.make

examplecontent/CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.o: examplecontent/CMakeFiles/PandoraExample.dir/flags.make
examplecontent/CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.o: ../examplecontent/Test/PandoraExample.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examplecontent/CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.o"
	cd /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent && /cvmfs/dune.opensciencegrid.org/products/dune/gcc/v8_2_0/Linux64bit+3.10-2.17/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.o -c /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/examplecontent/Test/PandoraExample.cc

examplecontent/CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.i"
	cd /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent && /cvmfs/dune.opensciencegrid.org/products/dune/gcc/v8_2_0/Linux64bit+3.10-2.17/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/examplecontent/Test/PandoraExample.cc > CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.i

examplecontent/CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.s"
	cd /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent && /cvmfs/dune.opensciencegrid.org/products/dune/gcc/v8_2_0/Linux64bit+3.10-2.17/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/examplecontent/Test/PandoraExample.cc -o CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.s

# Object files for target PandoraExample
PandoraExample_OBJECTS = \
"CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.o"

# External object files for target PandoraExample
PandoraExample_EXTERNAL_OBJECTS =

examplecontent/bin/PandoraExample: examplecontent/CMakeFiles/PandoraExample.dir/Test/PandoraExample.cc.o
examplecontent/bin/PandoraExample: examplecontent/CMakeFiles/PandoraExample.dir/build.make
examplecontent/bin/PandoraExample: /storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib/libPandoraSDK.so
examplecontent/bin/PandoraExample: /storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib/libPandoraMonitoring.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libCore.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libImt.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libRIO.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libNet.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libHist.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libGraf.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libGraf3d.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libGpad.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libROOTDataFrame.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libTree.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libTreePlayer.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libRint.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libPostscript.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libMatrix.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libPhysics.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libMathCore.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libThread.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libMultiProc.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libEve.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libGeom.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libRGL.so
examplecontent/bin/PandoraExample: /cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib/libEG.so
examplecontent/bin/PandoraExample: examplecontent/lib/libExampleContent.so.03.00.03
examplecontent/bin/PandoraExample: /storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib/libPandoraSDK.so
examplecontent/bin/PandoraExample: /storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib/libPandoraMonitoring.so
examplecontent/bin/PandoraExample: examplecontent/CMakeFiles/PandoraExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/PandoraExample"
	cd /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PandoraExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examplecontent/CMakeFiles/PandoraExample.dir/build: examplecontent/bin/PandoraExample

.PHONY : examplecontent/CMakeFiles/PandoraExample.dir/build

examplecontent/CMakeFiles/PandoraExample.dir/clean:
	cd /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent && $(CMAKE_COMMAND) -P CMakeFiles/PandoraExample.dir/cmake_clean.cmake
.PHONY : examplecontent/CMakeFiles/PandoraExample.dir/clean

examplecontent/CMakeFiles/PandoraExample.dir/depend:
	cd /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/examplecontent /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent/CMakeFiles/PandoraExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examplecontent/CMakeFiles/PandoraExample.dir/depend

