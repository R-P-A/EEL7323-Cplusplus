# CXX = g++
CXX = ../../../Atlys/bcc-2.0.1-gcc/bin/sparc-gaisler-elf-g++
CXXFLAGS = -Wall -std=c++11
SRCS = product.cpp vendingMachine.cpp interface.cpp gpio.cpp oled.cpp myString.cpp readInput.cpp myTime.cpp main.cpp
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

gpio: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

oled: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

myString: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

readInput: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

myTime: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

main: $@.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o *.exe *.out