CC=g++
CFLAGS=-w -O2 -c -std=c++11
LDFLAGS=
SOURCES=test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=test.exe

all: $(SOURCES) $(EXE)

build:
	make all && ./$(EXE)

run:
	./$(EXE)

$(EXE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXE)
