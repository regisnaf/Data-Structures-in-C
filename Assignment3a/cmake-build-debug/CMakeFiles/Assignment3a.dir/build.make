# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\back\CLionProjects\Assignment3a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\back\CLionProjects\Assignment3a\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Assignment3a.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\Assignment3a.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Assignment3a.dir\flags.make

CMakeFiles\Assignment3a.dir\main.c.obj: CMakeFiles\Assignment3a.dir\flags.make
CMakeFiles\Assignment3a.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\back\CLionProjects\Assignment3a\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assignment3a.dir/main.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Assignment3a.dir\main.c.obj /FdCMakeFiles\Assignment3a.dir\ /FS -c C:\Users\back\CLionProjects\Assignment3a\main.c
<<

CMakeFiles\Assignment3a.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment3a.dir/main.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\Assignment3a.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\back\CLionProjects\Assignment3a\main.c
<<

CMakeFiles\Assignment3a.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment3a.dir/main.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Assignment3a.dir\main.c.s /c C:\Users\back\CLionProjects\Assignment3a\main.c
<<

# Object files for target Assignment3a
Assignment3a_OBJECTS = \
"CMakeFiles\Assignment3a.dir\main.c.obj"

# External object files for target Assignment3a
Assignment3a_EXTERNAL_OBJECTS =

Assignment3a.exe: CMakeFiles\Assignment3a.dir\main.c.obj
Assignment3a.exe: CMakeFiles\Assignment3a.dir\build.make
Assignment3a.exe: CMakeFiles\Assignment3a.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\back\CLionProjects\Assignment3a\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Assignment3a.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Assignment3a.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\10.0.18362.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\10.0.18362.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Assignment3a.dir\objects1.rsp @<<
 /out:Assignment3a.exe /implib:Assignment3a.lib /pdb:C:\Users\back\CLionProjects\Assignment3a\cmake-build-debug\Assignment3a.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Assignment3a.dir\build: Assignment3a.exe
.PHONY : CMakeFiles\Assignment3a.dir\build

CMakeFiles\Assignment3a.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment3a.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Assignment3a.dir\clean

CMakeFiles\Assignment3a.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\back\CLionProjects\Assignment3a C:\Users\back\CLionProjects\Assignment3a C:\Users\back\CLionProjects\Assignment3a\cmake-build-debug C:\Users\back\CLionProjects\Assignment3a\cmake-build-debug C:\Users\back\CLionProjects\Assignment3a\cmake-build-debug\CMakeFiles\Assignment3a.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Assignment3a.dir\depend

