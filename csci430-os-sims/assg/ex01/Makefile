# source files in this project (for beautification)
PROJECT_NAME=ex01
sources = $(PROJECT_NAME)-tests.cpp \
					$(PROJECT_NAME)-sim.cpp \
					ex01-functions.hpp \
					ex01-functions.cpp


# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template-files =

# object file targets used for both testing and simulation
assg-objects = ex01-functions.o


# common targets and variables used for all assignments/projects
include ../../include/Makefile.inc


## system-info.txt : gather system information
.PHONY : system-info.txt
system-info.txt :
	./system-info > system-info.txt

## submit       : Create a tared and compressed file of
##                assignment files for submission
##
.PHONY : submit
submit :: beautify system-info.txt
	tar cvfz $(PROJECT_NAME).tar.gz $(sources) system-info.txt

