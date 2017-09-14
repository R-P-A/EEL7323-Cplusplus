CXX = g++
CFLAGS = 
DEPS = *.h
CPPS = *.cpp
TARGET = main.exe
OBJS = *.o

all: main.exe

main.exe: $(CPPS) $(DEPS)
	$(CXX) -o $(TARGET) $(CPPS) $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJS)