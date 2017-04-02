CXX = gcc
SRC = xmlGetter.c
MAIN = XMLGETTER

all: $(MAIN)

xmlGetter.o:$(SRC)
	$(CXX) -c $^ `xml2-config --cflags --libs` -o $@

$(MAIN):treeParser_exemple.o
	$(CXX) $^ -lxml2 -o $@

clean:
	rm xmlGetter.o $(MAIN)
