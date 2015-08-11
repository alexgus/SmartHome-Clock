CXX=g++

LPATH=.
LIBS=-lpaho-mqtt3a -lpaho-mqtt3c
IPATH=./org.eclipse.paho.mqtt.c/src

CXXFLAGS=-g -std=c++11 -Wall -I $(IPATH) $(LIBS)
BIN=TO52

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)



all: $(OBJ)
	$(CXX) -o $(BIN) -L $(LPATH) $(LIBS) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)

