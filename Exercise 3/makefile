CXX = g++
CXXFLAGS = -Wall
SRCS = readInput.cpp model.cpp student.cpp sortedList.cpp menu.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

linux: $(OBJS) node.h
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe
	chmod +x main.exe

readInput: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

model: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

student: $@.cpp $@.h model.o
	$(CXX) $(CXXFLAGS) $@.cpp -c

sortedList: $@.cpp $@.h node.h model.o
	$(CXX) $(CXXFLAGS) $@.cpp -c

menu: $@.cpp $@.h sortedList.o student.o readInput.o
	$(CXX) $(CXXFLAGS) $@.cpp -c

main: $@.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o main.exe