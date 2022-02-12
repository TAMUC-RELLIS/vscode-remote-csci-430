# source files in this project (for beautification)
PROJECT_NAME=assg03
sources = $(PROJECT_NAME)-tests.cpp \
					$(PROJECT_NAME)-sim.cpp \
					State.hpp \
					State.cpp


# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template-files =


# object file targets used for both testing and simulation
assg-objects = State.o


 # common targets and variables used for all assignments/projects
include ../../include/Makefile.inc


# specify additional prerequisites, augments the default rule
assg03-tests.o: assg03-tests.cpp State.hpp
assg03-sim.o: assg03-sim.cpp State.hpp
State.o: State.hpp State.cpp
