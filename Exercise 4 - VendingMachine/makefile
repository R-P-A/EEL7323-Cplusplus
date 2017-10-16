CXX = g++
CXXFLAGS = -Wall
SRCS = product.cpp vendingMachine.cpp interface.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

linux: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe
	chmod +x main.exe

product: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

vendingMachine: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

interface: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

main: $@.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o main.exe