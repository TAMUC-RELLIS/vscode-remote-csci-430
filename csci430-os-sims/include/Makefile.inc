# compiler flags, tools and include variables
GCC=g++
GCC_FLAGS=-Wall -Werror -pedantic -O2 -g
INCLUDES=-I../../include
LINKS=

FORMATTER=clang-format
FORMATTER_FLAGS=-i

DOC=doxygen
DOC_FLAGS=../../config/Doxyfile

RM=rm -rf

TEST_TARGET=test
SIM_TARGET=sim


# objects needed to be linked together for unit test executable
test-objects = $(PROJECT_NAME)-tests.o \
	       $(assg-objects)

# objects needed to be linked together for the full simulation
sim-objects = $(PROJECT_NAME)-sim.o \
	      $(assg-objects)

catch2-test-object = ../../libs/catch2-main.o
simulator-exception-object = ../../libs/SimulatorException.o

## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##
.PHONY : all
all : $(TEST_TARGET) $(SIM_TARGET)


## test         : Build and link together unit test executable
##
$(TEST_TARGET) : $(test-objects) $(template-files) $(catch2-test-object) $(simulator-exception-object)
	$(GCC) $(GCC_FLAGS) $(test-objects) $(catch2-test-object) $(simulator-exception-object)  $(LINKS) -o $@

## sim          : Build and link together command line simulation
##                executable for this assignment
##
$(SIM_TARGET) : $(sim-objects) $(template-files) $(simulator-exception-object)
	$(GCC) $(GCC_FLAGS) $(sim-objects) $(simulator-exception-object) $(LINKS) -o $@

%.o: %.cpp
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -c $< -o $@

../../libs/%.o: ../../libs/%.cpp
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -c $< -o $@

## tests        : Run both the unit tests and the system tests together
##
.PHONY : tests
tests : unit-tests system-tests

## unit-tests   : Run the unit tests showing successful tests
##
unit-tests : $(TEST_TARGET)
	./$(TEST_TARGET) --use-colour yes

## system-tests : Run the system tests testing full simulation
##
system-tests : $(SIM_TARGET)
	./run-system-tests


## format       : Run the code formatter/beautifier by hand if needed
##
.PHONY : format
format :
	$(FORMATTER) $(FORMATTER_FLAGS) $(sources)


## docs         : Create doygen reference documentation from
##                doc comments.
##
.PHONY : docs
docs :
		@echo "Generating doxygen documentation..."
		$(DOC) $(DOC_FLAGS) 2>&1 | grep -A 1 warning | grep -v "\file statement" | grep -v "\pagebreak" | grep -v "Searching for include" | sed -e "s|${PWD}/||g"


## submit       : Create a tared and compressed file of
##                assignment files for submission
##
.PHONY : submit
submit :: format
	tar cvfz $(PROJECT_NAME).tar.gz $(sources)

## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) $(TEST_TARGET) $(SIM_TARGET) *.o *.gch *~
	$(RM) output html latex


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile ../../include/Makefile.inc
	@sed -n 's/^##//p' $^
