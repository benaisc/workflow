CXX = gcc
SRC = treeParser_exemple.c
MAIN = testParser

all: $(MAIN)

.o:$(SRC)
	$(CXX) -c $^ `xml2-config --cflags --libs` -o $@

$(MAIN):.o
	$(CXX) $^ -lxml2 -o $@

clean:
	rm treeParser_exemple.o testParser
