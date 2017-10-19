# CXX = g++
CXX = ../../../../Atlys/bcc-2.0.1-gcc/bin/sparc-gaisler-elf-g++
CXXFLAGS = -Wall -std=c++11
SRCS = oled.cpp myTime.cpp oledTest.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

linux: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe
	chmod +x main.exe

oled: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

myTime: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

oledTest: $@.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o *.exe *.out