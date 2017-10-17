CXX = g++
CXXFLAGS = -Wall
SRCS = product.cpp vendingMachine.cpp interface.cpp myString.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

leon: $(SRCS)
	F:\bcc-2.0.1-gcc\bin\sparc-gaisler-elf-g++.exe -std=c++11 $(SRCS) -o main.exe
	chmod +x main.exe

linux: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe
	chmod +x main.exe

product: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

vendingMachine: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

interface: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

myString: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

main: $@.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o main.exe