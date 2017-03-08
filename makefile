CXX = gcc
SRC = treeGetter.c
MAIN = TreeGetter

all: $(MAIN)

treeGetter.o:$(SRC)
	$(CXX) -c $^ `xml2-config --cflags --libs` -o $@

$(MAIN):treeGetter.o
	$(CXX) $^ -lxml2 -o $@

clean:
	rm treeGetter.o $(MAIN)
