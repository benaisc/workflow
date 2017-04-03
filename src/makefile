CXX = gcc
#FLAGS =  -std=c++0x -Wall -pedantic
SRC = domParser_exemple.c
MAIN = DOMPARSER

all: $(MAIN)

domParser_exemple.o:$(SRC)
	$(CXX) -c $^ `xml2-config --cflags --libs` -o $@

$(MAIN):domParser_exemple.o
	$(CXX) $^ -lxml2 -o $@

clean:
	rm domParser_exemple.o $(MAIN)
