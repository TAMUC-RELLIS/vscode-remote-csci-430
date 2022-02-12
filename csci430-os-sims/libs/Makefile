GCC=g++
GSS_FLAGS=-Wall -Werror -g -fPIC
INCLUDES=../include
ARCHIVE=ar
RM=rm -f # linux/MacOS command to delete files for make clean


# list of library targets to build
libraries=libSimulatorException.a catch2-main.a


## List of all valid targets in this project:
## ------------------------------------------
## all   : by default generate all linkable libraries
.PHONY : all
all: ${libraries}

## libSimulatorException.a : The SimulatorException linkable library
libSimulatorException.a: SimulatorException.o
	${ARCHIVE} rcs $@ $<

## catch2-main.a : The catch2 testing framework main function hook
catch2-main.a: catch2-main.o
	${ARCHIVE} rcs $@ $<

# default rule to compile intermediate object files from source for libraries
%.o: %.cpp
	${GCC} -c ${GCC_FLAGS} -I${INCLUDES} $< -o $@


## clean : Remove auto-generated files for a completely clean rebuild
.PHONY : clean
clean:
	${RM} ${libraries} *.o *~


## help  : Get all build targets supported by this build.
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $<
