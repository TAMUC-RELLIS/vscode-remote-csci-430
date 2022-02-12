# compiler flags, tools and include variables
GCC=g++
GCC_FLAGS=-Wall -Werror -pedantic -g
INCLUDES=-I../../include
LINKS=-lpthread

BEAUTIFIER=uncrustify
BEAUTIFIER_FLAGS=-c ../../config/.uncrustify.cfg --replace --no-backup

DOC=doxygen
DOC_FLAGS=../../config/Doxyfile

RM=rm -rf

# source files in this project (for beautification)
PROJECT_NAME=amdhals-law
sources = amdhals-law.cpp


## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##                 ps02semaphorestrong Uses posix signals and doesn't build on
##                 windows, so we removed from default build.  Do
##                 make ps02semaphorestrong explicitly to build that target.
##
.PHONY : all
all : ex

## ps02         : Build and link together Amdhal's law example
##
ex : amdhals-law.o
	$(GCC) $(GCC_FLAGS) amdhals-law.o $(LINKS) -o $@



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
	$(RM) ex *.exe *.o *.gch *~


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $^
