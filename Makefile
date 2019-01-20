CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++17

Distance: distance.o
	${CXX} ${CXXFLAGS} -o Distance distance.o

distance.o:
 
