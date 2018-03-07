CC=armclang++
CFLAGS=-c -mcpu=native -Wall -pedantic -Wfloat-equal -Wshadow -DLINUX
LDFLAGS=
SOURCES=calculate_b.c calculate_u.c MPC_qpOASES.cpp
OBJECTS=$(SOURCES:.c=.o)
OBJECTS+=$(SOURCES:.cpp=.o)
EXECUTABLE=MPC_qpOASES

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
   -rm -f *.o core *.core

.cpp.o:
    $(CC) $(CFLAGS) $< -o $@