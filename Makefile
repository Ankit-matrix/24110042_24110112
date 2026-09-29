CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = program

OBJECTS = main.o mathfuncs.o rand_func.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp mathfuncs.h rand_func.h
	$(CXX) $(CXXFLAGS) -c main.cpp

mathfuncs.o: mathfuncs.cpp mathfuncs.h
	$(CXX) $(CXXFLAGS) -c mathfuncs.cpp

randfuncs.o: rand_func.cpp rand_func.h
	$(CXX) $(CXXFLAGS) -c rand_func.cpp

clean:
	rm -f $(OBJECTS) $(TARGET)
