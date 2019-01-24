#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "geocoord.hpp"

using coord = geocoord::Coordinate;

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main(int argc, char **argv)
{
	string line1, line2, line3, line4;	

	getline(cin, line1);
	getline(cin, line2);
	getline(cin, line3);
	getline(cin, line4);	

	coord point1{line1, line2};
	coord point2{line3, line4};
	
	cout << point1.geo_distance(point2) << endl;
}

