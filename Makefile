CC = armclang++
CFLAGS = -c -mcpu=native -Wall -pedantic -Wfloat-equal -Wshadow -DLINUX
LDFLAGS =
CSOURCES = $(patsubst %.c, %.o, $(wildcard *.c))
CPPSOURCES = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
		
OBJECTS=$(CSOURCES:.c=.o) $(CPPSOURCES:.cpp=.o)
INCLUDE=-I $(CURDIR)/include	\
	-I $(CURDIR)/include/MPC_qpOASES
EXECUTABLE=MPC_qpOASES

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(INCLUDE) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	-rm -f *.o core *.core

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@