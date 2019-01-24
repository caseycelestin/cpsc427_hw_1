CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++17

Distance: distance.o geocoord.o
	${CXX} ${CXXFLAGS} -o Distance distance.o geocoord.o

distance.o: geocoord.hpp
geocoord.o: geocoord.hpp 

