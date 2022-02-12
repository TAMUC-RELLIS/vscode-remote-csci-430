# compiler flags, tools and include variables
GCC=g++
GCC_FLAGS=-Wall -Werror -pedantic -g
INCLUDES=-I../../include -I../../assg/assg02
LINKS=-L../../libs -lSimulatorException

BEAUTIFIER=uncrustify
BEAUTIFIER_FLAGS=-c ../../config/.uncrustify.cfg --replace --no-backup

DOC=doxygen
DOC_FLAGS=../../config/Doxyfile

RM=rm -rf

# source files in this project (for beautification)
PROJECT_NAME=stl
sources = vector-example.cpp


## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##                 ps02semaphorestrong Uses posix signals and doesn't build on
##                 windows, so we removed from default build.  Do
##                 make ps02semaphorestrong explicitly to build that target.
##
.PHONY : all
all : vector-example queue-stack

## vector-example : Build and link together vector example
##
vector-example : vector-example.o ../../assg/assg02/Process.o ../../assg/assg02/ProcessState.o
	$(GCC) $(GCC_FLAGS) vector-example.o ../../assg/assg02/Process.o ../../assg/assg02/ProcessState.o $(LINKS) -o $@

## queue-stack    : Build and link together queue/stack example
##
queue-stack : queue-stack.o
	$(GCC) $(GCC_FLAGS) queue-stack.o $(LINKS) -o $@



%.o: %.cpp
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -c $< -o $@

## beautify     : Run the code beautifier by hand if needed
##
.PHONY : beautify
beautify :
	$(BEAUTIFIER) $(BEAUTIFIER_FLAGS) $(sources)


## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) vector-example queue-stack *.exe *.o *.gch *~


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $^
