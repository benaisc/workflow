CXX = g++
FLAGS = -std=c++11
# -Wall -pedantic
#SRC = STCMAssembly.cpp Declare.cpp Component.cpp
TARGET = TEST

all: $(TARGET)

MainTest.o: MainTest.cpp
	$(CXX) `xml2-config --cflags --libs` $(FLAGS) -c $^

LibParser.o: LibParser.cpp
	$(CXX) `xml2-config --cflags --libs` $(FLAGS) -c $^

STCMAssembly.o: STCMAssembly.cpp
	$(CXX) $(FLAGS) -c $^

Declare.o: Declare.cpp
	$(CXX) $(FLAGS) -c $^

Component.o: Component.cpp
	$(CXX) $(FLAGS) -c $^

$(TARGET): MainTest.o LibParser.o STCMAssembly.o Declare.o Component.o
	$(CXX) $^ -lxml2 -o $@

clean:
	rm *.o $(TARGET)

# à la main :
#g++ -std=c++11 -Wall -pedantic -c STCMAssembly.cpp Declare.cpp Component.cpp
#g++ `xml2-config --cflags --libs` -std=c++11 -Wall -pedantic -c MainTest.cpp
#g++ *.o -o TEST
# ./TEST test/prod_cons.xml
