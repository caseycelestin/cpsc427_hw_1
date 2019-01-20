#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::istringstream;

double coordinate_converter(string coord_in);

int main(int argc, char **argv)
{
	//double lat1, lon1, lat2, lon2;
	//double deg, min, sec;
	string line;
	
	getline(cin, line);
	
	cout << coordinate_converter(line);	
	
	//cout << line.length() << endl;		
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
	//cout << deg << endl << min << endl << sec << endl;	
	
	return coord_out;
}

