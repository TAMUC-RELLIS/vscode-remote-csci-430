# source files in this project (for beautification)
PROJECT_NAME=assg04
sources = $(PROJECT_NAME)-tests.cpp \
					$(PROJECT_NAME)-sim.cpp \
					ClockPageReplacementScheme.hpp \
					ClockPageReplacementScheme.cpp \
					FifoPageReplacementScheme.hpp \
					FifoPageReplacementScheme.cpp \
					PageReplacementScheme.hpp \
					PageReplacementScheme.cpp \
					PagingSystem.hpp \
					PagingSystem.cpp


# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template-files =


# object file targets used for both testing and simulation
assg-objects = ClockPageReplacementScheme.o \
               FifoPageReplacementScheme.o \
							 PageReplacementScheme.o \
							 PagingSystem.o


 # common targets and variables used for all assignments/projects
include ../../include/Makefile.inc


# specify additional prerequisites, augments the default rule
assg04-tests.o: assg04-tests.cpp PagingSystem.hpp PageReplacementScheme.hpp FifoPageReplacementScheme.hpp
assg04-sim.o: assg04-sim.cpp PagingSystem.hpp PageReplacementScheme.hpp FifoPageReplacementScheme.hpp
PagingSystem.o: PagingSystem.cpp PagingSystem.hpp
PageReplacementScheme.o: PageReplacementScheme.cpp PageReplacementScheme.hpp PagingSystem.hpp
FifoPageReplacementScheme.o: FifoPageReplacementScheme.cpp FifoPageReplacementScheme.hpp PageReplacementScheme.hpp PagingSystem.hpp
ClockPageReplacementScheme.o: ClockPageReplacementScheme.cpp ClockPageReplacementScheme.hpp PageReplacementScheme.hpp PagingSystem.hpp
