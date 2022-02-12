# source files in this project (for beautification)
PROJECT_NAME=assg02
sources = $(PROJECT_NAME)-tests.cpp \
					$(PROJECT_NAME)-sim.cpp \
					ProcessSimulator.hpp \
					ProcessSimulator.cpp \
					Process.hpp \
					Process.cpp \
					ProcessState.hpp \
					ProcessState.cpp


# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template-files =


# object file targets used for both testing and simulation
assg-objects = ProcessSimulator.o \
							 Process.o \
							 ProcessState.o


 # common targets and variables used for all assignments/projects
include ../../include/Makefile.inc


# specify additional prerequisites, augments the default rule
assg02-tests.o: assg02-tests.cpp ProcessSimulator.hpp ProcessState.hpp
assg02-sim.o: assg02-sim.cpp ProcessSimulator.hpp ProcessState.hpp
ProcessSimulator.o: ProcessSimulator.cpp ProcessSimulator.hpp ProcessState.hpp Process.hpp
ProcessState.o: ProcessState.cpp ProcessState.hpp
Process.o: ProcessSimulator.cpp Process.hpp ProcessState.hpp
