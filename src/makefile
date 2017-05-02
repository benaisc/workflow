CXX = g++
FLAGS = -std=c++11 -Wall -pedantic
#SRC = STCMAssembly.cpp Declare.cpp Component.cpp InPort.cpp OutPort.cpp Port.cpp Instance.cpp ConfigPort.cpp InOut.cpp SetPort.cpp
TARGET = TEST

all: $(TARGET)

main.o: main.cpp
	$(CXX) `xml2-config --cflags --libs` $(FLAGS) -c $^

LibParser.o: LibParser.cpp
	$(CXX) `xml2-config --cflags --libs` $(FLAGS) -c $^

STCMAssembly.o: STCMAssembly.cpp
	$(CXX) $(FLAGS) -c $^

Declare.o: Declare.cpp
	$(CXX) $(FLAGS) -c $^

Component.o: Component.cpp
	$(CXX) $(FLAGS) -c $^

InPort.o: InPort.cpp
	$(CXX) $(FLAGS) -c $^

OutPort.o: OutPort.cpp
	$(CXX) $(FLAGS) -c $^

Port.o: Port.cpp
	$(CXX) $(FLAGS) -c $^

Instance.o: Instance.cpp
	$(CXX) $(FLAGS) -c $^

ConfigPort.o: ConfigPort.cpp
	$(CXX) $(FLAGS) -c $^

InOut.o: InOut.cpp
	$(CXX) $(FLAGS) -c $^

SetPort.o: SetPort.cpp
	$(CXX) $(FLAGS) -c $^

$(TARGET): main.o LibParser.o STCMAssembly.o Declare.o Component.o InPort.o OutPort.o Port.o Instance.o ConfigPort.o InOut.o SetPort.o
	$(CXX) $^ -lxml2 -o $@

clean:
	rm *.o $(TARGET)

#usage:
# make
# ./TEST test/prod_cons.xml
