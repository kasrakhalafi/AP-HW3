CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o dVector.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
dVector.o: dVector.cpp dVector.h
	$(CXX) $(CXXFLAGS) dVector.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
