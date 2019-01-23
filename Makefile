CXX=g++
CXXFLAGS= -g -Wall -pedantic -std=c++17

Distance: distance.o geocoord.o
	${CXX} ${CXXFLAGS} -o Distance distance.o

distance.o: geocoord.hpp
geocoord.o: geocoord.hpp 

