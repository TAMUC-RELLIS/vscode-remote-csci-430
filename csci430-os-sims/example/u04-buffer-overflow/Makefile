# compiler flags, tools and include variables
# NOTE: using plain vanilla c compiler for this example
GCC=gcc
GCC_FLAGS=-Wall -pedantic -fno-stack-protector -g -std=c99
INCLUDES=-I../../include
LINKS=

BEAUTIFIER=uncrustify
BEAUTIFIER_FLAGS=-c ../../config/.uncrustify.cfg --replace --no-backup

DOC=doxygen
DOC_FLAGS=../../config/Doxyfile

RM=rm -rf

# source files in this project (for beautification)
PROJECT_NAME=u04-buffer-overflow
sources = u04-buffer-overflow.c


## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##
##
.PHONY : all
all : buff

## buff         : Build and link together buffer overflow example
##
buff : u04-buffer-overflow.o
	$(GCC) $(GCC_FLAGS) u04-buffer-overflow.o $(LINKS) -o $@


%.o: %.c
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
	$(RM) buff *.exe *.o *.gch *~


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $^
