#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::istringstream;
using std::acos;
using std::cos;
using std::sin;

double coordinate_converter(string coord_in);
double geo_distance(double, double, double, double);

int main(int argc, char **argv)
{
	string line1, line2, line3, line4;
	double lat1, lon1, lat2, lon2, dist;
	
	getline(cin, line1);
	getline(cin, line2);
	getline(cin, line3);
	getline(cin, line4);
	
	lat1 = coordinate_converter(line1);
	lon1 = coordinate_converter(line2);
	lat2 = coordinate_converter(line3);
	lon2 = coordinate_converter(line4);
	
	dist = geo_distance(lat1, lon1, lat2, lon2);

	cout << dist << endl;
}

double geo_distance(double la1, double lo1, double la2, double lo2)
{
	double a, b, C, angle, d;
	
	a = 1.570796 - la1;
	b = 1.570796 - la2;
	C = lo2 - lo1;
	
	angle = acos( cos(a) * cos(b) + sin(a) * sin(b) * cos(C) );
	d = angle * 3959;
	
	return d;
}

double coordinate_converter(string coord_in)
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
	coord_out = coord_out * 3.14159 / 180;
	
	return coord_out;
}

