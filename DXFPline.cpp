//
// Created by Денис on 11/03/2021.
//

#include "DXFPline.hpp"

bool 	DXFPline::addVertex(Point &point) {
	if (!polyline.empty() && point.x == polyline.begin()->x && point.y == polyline.begin()->y)
		return false;
	polyline.push_back(point);
	return true;
}

DXFPline::DXFPline() {
	closedLine = true;
}

void DXFPline::setClosedLine(bool closedLine) {
	this->closedLine = closedLine;
}

bool DXFPline::isClosedLine() const {
	return closedLine;
}

const std::list<Point> &DXFPline::getPolyline() const {
	return polyline;
}

