//
// Created by Денис on 10/03/2021.
//

#ifndef DXFPARSER_POINT_HPP
#define DXFPARSER_POINT_HPP


class Point {
public:
	double x;
	double y;
	double z;

	Point(double x, double y, double z);

	Point();

	bool operator==(const Point &rhs) const;

	bool operator!=(const Point &rhs) const;
};


#endif //DXFPARSER_POINT_HPP
