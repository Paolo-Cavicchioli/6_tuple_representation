CXX=g++
RM=rm -f
CPPFLAGS=-g -O3
LDFLAGS=-g 

SRCS=6_tuple.cpp my_functions.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: 6_tuple

6_tuple: $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o 6_tuple $(OBJS)

6_tuple.o: 6_tuple.cpp my_functions.o

my_functions.o: my_functions.h my_functions.cpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) 6_tuple
