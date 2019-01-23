#include "geocoord.hpp"

#include <cmath>
#include <string>
#include <sstream>

using std::string;
using std::istringstream;
using std::acos;
using std::cos;
using std::sin;

namespace geocoord
{
	Coordinate::Coordinate()
	{
		lat = 0.0;
		lon = 0.0;
	}

	Coordinate::Coordinate(string x, string y)	
	{
		lat = coordinate_converter(x);
		lon = coordinate_converter(y);
	}

	double Coordinate::geo_distance(Coordinate end)
	{
		double a, b, C, angle, d;
		a = 1.570796 - lat;
		b = 1.570796 - end.lat;
		C = lon - end.lon;
		
		angle = acos( cos(a) * cos(b) + sin(a) * sin(b) * cos(C) );
		d = angle * 3959;
		
		return d;
	}

	double Coordinate::coordinate_converter(string coord_in)
	{
		double coord_out;
		double deg, min, sec;
		
		istringstream sin{coord_in};
		
		sin >> deg >> min >> sec;
		
		if(coord_in.front() == '-')
		{
			min = min * -1;
			sec = sec * -1;
		}
		
		coord_out = deg + min / 60 + sec / 3600;
		coord_out = coord_out * 3.14159 / 180; //Converts degrees to radians
		
		return coord_out;
	}
}
