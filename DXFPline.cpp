//
// Created by Денис on 11/03/2021.
//

#include "DXFPline.hpp"

void 	DXFPline::addVertex(Point &point) {
	polyline.push_back(point);
}

DXFPline::DXFPline() {
	closedLine = false;
}

const std::list<Point> &DXFPline::getPolyline() const {
	return polyline;
}

