CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=6_tuple.cpp my_functions.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: 6_tuple

6_tuple: $(OBJS)
    $(CXX) $(LDFLAGS) -o 6_tuple $(OBJS) $(LDLIBS)

6_tuple.o: 6_tuple.cpp my_functions.o

my_functions.o: my_functions.h my_functions.cpp

clean:
    $(RM) $(OBJS)

distclean: clean
    $(RM) 6_tuple