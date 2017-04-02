CXX = g++ -std=c++0x -Wall -pedantic
SRC = treeParser_exemple.c
MAIN = DOMGETTER

all: $(MAIN)

treeParser_exemple.o:$(SRC)
	$(CXX) -c $^ `xml2-config --cflags --libs` -o $@

$(MAIN):treeParser_exemple.o
	$(CXX) $^ -lxml2 -o $@

clean:
	rm treeParser_exemple.o $(MAIN)
