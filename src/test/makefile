CXX = g++ -std=c++0x
SRC = domGetter.c
MAIN = DOMGETTER

all: $(MAIN)

domGetter.o:$(SRC)
	$(CXX) -std=C++11 -c $^ `xml2-config --cflags --libs` -o $@

$(MAIN):domGetter.o
	$(CXX) $^ -lxml2 -o $@

clean:
	rm domGetter.o $(MAIN)
