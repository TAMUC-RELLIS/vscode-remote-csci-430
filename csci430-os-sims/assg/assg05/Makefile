# source files in this project (for beautification)
PROJECT_NAME=assg05
sources = $(PROJECT_NAME)-tests.cpp \
					$(PROJECT_NAME)-sim.cpp \
					SchedulingSystem.hpp \
					SchedulingSystem.cpp \
					SchedulingPolicy.hpp \
					SchedulingPolicy.cpp \
					FCFSSchedulingPolicy.hpp \
					FCFSSchedulingPolicy.cpp
# when adding new scheduling policy, add .hpp and .cpp files to sources
# like this for example
#	  			RRSchedulingPolicy.hpp \
#					RRSchedulingPolicy.cpp


# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template-files =


# object file targets used for both testing and simulation
assg-objects = SchedulingSystem.o \
               SchedulingPolicy.o \
							 FCFSSchedulingPolicy.o
# when adding new scheduling policy, add new .o file like this for example
#							 RRSchedulingPolicy.o


 # common targets and variables used for all assignments/projects
include ../../include/Makefile.inc


# specify additional prerequisites, augments the default rule
assg05-tests.o: assg05-tests.cpp SchedulingSystem.hpp SchedulingPolicy.hpp FCFSSchedulingPolicy.hpp
assg05-sim.o: assg05-sim.cpp SchedulingSystem.hpp SchedulingPolicy.hpp FCFSSchedulingPolicy.hpp
SchedulingSystem.o: SchedulingSystem.cpp SchedulingSystem.hpp SchedulingPolicy.hpp
SchedulingPolicy.o: SchedulingPolicy.cpp SchedulingPolicy.cpp SchedulingSystem.hpp
FCFSSchedulingPolicy.o: FCFSSchedulingPolicy.cpp FCFSSchedulingPolicy.cpp SchedulingPolicy.hpp
