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
PROJECT_NAME=ps02
sources = ps02-race.cpp ps02-semaphore.cpp ps02-semaphore-strong.cpp


## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##                 ps02semaphorestrong Uses posix signals and doesn't build on
##                 windows, so we removed from default build.  Do
##                 make ps02semaphorestrong explicitly to build that target.
##
.PHONY : all
all : ps02 ps02semaphore ps02semaphorecond

## ps02         : Build and link together ps02 example
##
ps02 : ps02-race.o
	$(GCC) $(GCC_FLAGS) ps02-race.o $(LINKS) -o $@


## ps02semaphore : Build and link together ps02 example using semaphores
##                  to protect critical section.
ps02semaphore : ps02-semaphore.o
	$(GCC) $(GCC_FLAGS) ps02-semaphore.o $(LINKS) -o $@

## ps02semaphorestrong : Build and link together ps02 example using semaphores
##                  to protect critical section.  This is a strong semaphore
##                  using posix signals for signaling.
ps02semaphorestrong : ps02-semaphore-strong.o
	$(GCC) $(GCC_FLAGS) ps02-semaphore-strong.o $(LINKS) -o $@

## ps02semaphorcond     : Build and link together ps02 example using semaphores
##                  This is a strong semaphore using condition variables for
##                  signaling.
ps02semaphorecond   : ps02-semaphore-cond.o
	$(GCC) $(GCC_FLAGS) ps02-semaphore-cond.o $(LINKS) -o $@


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
	$(RM) ps02 ps02semaphore ps02semaphorecond ps02semaphorestrong *.exe *.o *.gch *~


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $^
