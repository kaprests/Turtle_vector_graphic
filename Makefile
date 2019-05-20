EXECUTABLE = Turtle_yo # programnavn

INCLUDE_DIR = ../include
GRAPH_LIB_DIR = ../Graph_lib
GRAPH_LIB = $(GRAPH_LIB_DIR)/Graph_lib.a

CXX = clang++
DEBUG = -g -Og
RELEASE = -O2
CXXFLAGS = -std=c++14 -Wall -I$(INCLUDE_DIR) -I$(GRAPH_LIB_DIR)
LDFLAGS = $(GRAPH_LIB)
LINK = $(CXX)

CXXFLAGS += $(shell fltk-config --use-gl --use-images --cxxflags)
LDFLAGS  += $(shell fltk-config --use-gl --use-images --ldflags)
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags)

SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)

.SUFFIXES: .o .cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $<

$(EXECUTABLE): $(OBJECTS)
	$(LINK) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE)
	$(RM) $(OBJECTS)
