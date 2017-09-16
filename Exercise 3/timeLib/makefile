CXX = g++
CXXFLAGS = -Wall
SRCS = calendar.cpp clock.cpp clockCalendar.cpp timer.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

linux: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe
	chmod +x main.exe

calendar: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

clock: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

clockCalendar: $@.cpp $@.h model.o
	$(CXX) $(CXXFLAGS) $@.cpp -c

timer: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

main: $@.cpp $@.h node.h model.o
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o main.exe