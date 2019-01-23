#ifndef __GEOCOORD_HPP__
#define __GEOCOORD_HPP__

namespace geocoord
{
	class Coordinate
	{
	public:
		/**
		* Initializes coordinate at longitude 0.0 deg, latitude 0.0 deg
		*/
		Coodinate();
		
		/**
		* Initializes coordinate at longitude x, latitude y
		* Arguments  are strings to handle Deg:Min:Sec form
		*/
		Coordinate(string x, string y);
		
		/**
		* Computes the distance of two coordinates on earth given longitude and latitute of two points
		*/
		double geo_distance(Coordinate start, Coordinate end);

	private:
		/**
		* Latitude of coordinate
		*/
		double lat;

		/**
		* Longitude of coordinate
		*/
		double lon;
		
		/**
		* Changes a singular coordinate from Deg:Min:Sec to decimal form
		*/
		double coordinate_converter(string coord_in);
	};
}

#endif
