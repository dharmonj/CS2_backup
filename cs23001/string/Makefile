###############################################################
# String & Oracle
#
# CS II Kent State University
# Make file for string class and testing oracle 
# J. Maletic Fall 2016
#
#

###############################################################
# Variables
CPP     = clang++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11


# Names of your test files - add them in as you build them.
# Names must start with "test_"
MYTESTS = test_default_ctor test_ctor_charArray test_ctor_char test_comparison test_subscripts test_length test_capacity test_concat_member test_lessthan_member test_free_relationals test_free_concat test_swap test_copy_ctor test_substr test_find_char test_find_string test_split
DEBUGGER = valgrind

# Names of test oracle files 
CTOR = testoracle_ctor_default testoracle_ctor_char testoracle_ctor_charArray
REL  = testoracle_equal testoracle_lessThan
COPY = testoracle_ctor_copy testoracle_assign
OPS  = testoracle_concat

###############################################################
# Compile just the string
# Compile and run all provided test oracles on string
# Compile and run all your tests on string
# Compile and run the project
msg:
	@echo 'Targets are:'
	@echo '  string'
	@echo '  tests'
	@echo '  oracle'
	@echo '  logview'
	@echo '  clean'



###############################################################
# Compile string 
#
string: string.o
	@echo "String class built"

string.o: string.hpp string.cpp
	$(CPP) -c $(OPTIONS) string.cpp -o string.o

###############################################################
# Run all of your tests
# 
# You will need to ADD your other below:
# For example: ./test_plus
#
tests: $(MYTESTS)
	$(DEBUGGER) ./test_default_ctor
	$(DEBUGGER) ./test_ctor_charArray
	$(DEBUGGER) ./test_ctor_char
	$(DEBUGGER) ./test_comparison
	$(DEBUGGER) ./test_subscripts
	$(DEBUGGER) ./test_length
	$(DEBUGGER) ./test_capacity
	$(DEBUGGER) ./test_concat_member
	$(DEBUGGER) ./test_lessthan_member
	$(DEBUGGER) ./test_free_relationals
	$(DEBUGGER) ./test_free_concat
	$(DEBUGGER) ./test_copy_ctor
	$(DEBUGGER) ./test_swap
	$(DEBUGGER) ./test_substr
	$(DEBUGGER) ./test_find_char
	$(DEBUGGER) ./test_find_string
	$(DEBUGGER) ./test_split

###############################################################
# Compile all test programs
#
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.hpp test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp



###############################################################
# Run test oracle
# Comment out one's you don't want to run.
#
oracle: $(CTOR) $(REL) $(COPY) $(OPS)
	./testoracle_ctor_default
	./testoracle_ctor_char 
	./testoracle_ctor_charArray
	./testoracle_equal 
	./testoracle_lessThan
	./testoracle_ctor_copy 
	./testoracle_assign
	./testoracle_concat

###############################################################
# Compile all test programs
#
testoracle_%: string.o testoracles/testoracle_%.o
	$(CPP) string.o testoracles/testoracle_$*.o -o testoracle_$*



###############################################################
# Compile Project 
#

logview.o: logview.cpp logentry.hpp string.hpp
	$(CPP) -c $(OPTIONS) logview.cpp -o logview.o

logentry.o: logentry.cpp logentry.hpp string.hpp
	$(CPP) -c $(OPTIONS) logentry.cpp -o logentry.o

logview: logview.o string.o logentry.o 
	$(CPP) $(OPTIONS) logview.o string.o logentry.o -o logview


###############################################################
# clean 
# Removes all .o files and all executables
#
clean:
	rm -f *.o
	rm -f $(CTOR) $(REL) $(COPY) $(OPS)
	rm -f $(MYTESTS)
	rm -f logview


