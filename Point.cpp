//
// Created by Денис on 10/03/2021.
//

#include "Point.hpp"

Point::Point() {}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

bool Point::operator==(const Point &rhs) const {
	return x == rhs.x &&
		   y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const {
	return !(rhs == *this);
}
