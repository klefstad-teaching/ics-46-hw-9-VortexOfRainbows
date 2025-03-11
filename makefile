CXX=g++
CXXFLAGS=-g -std=c++20 -I include/
all: ladder ladder_main
ladder_main: 
	$(CXX) src/$@.cpp -o $@ ladder.o $(CXXFLAGS) 
ladder:
	$(CXX) -c src/$@.cpp -o $@.o $(CXXFLAGS)
clean:
	rm *.o main