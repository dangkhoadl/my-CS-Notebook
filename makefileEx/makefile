CC=g++
CFLAGS=-c -Wall -std=c++11 -O2
LDFLAGS=
SOURCES=main.cpp lib.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=program

all: $(SOURCES) $(EXE)

run:
	make all && ./$(EXE)

$(EXE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXE)
