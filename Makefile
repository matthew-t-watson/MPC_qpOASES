CC = armclang++
CFLAGS = -c -mcpu=native -Wall -pedantic -Wfloat-equal -Wshadow -DLINUX
LDFLAGS =
CSOURCES = $(*.c) $(src/*.c)
CPPSOURCES = $(*.cpp) $(src/*.cpp)
		
OBJECTS=$(CSOURCES:.c=.o) $(CPPSOURCES:.cpp=.o)
INCLUDE=$(CURDIR)/include:$(CURDIR)/include/MPC_qpOASES
EXECUTABLE=MPC_qpOASES

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) -I $(INCLUDE) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	-rm -f *.o core *.core

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@