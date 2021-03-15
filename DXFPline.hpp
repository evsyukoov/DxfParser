//
// Created by Денис on 11/03/2021.
//

#ifndef DXFPARSER_DXFPLINE_HPP
#define DXFPARSER_DXFPLINE_HPP
#include "Point.hpp"
#include <list>

class DXFPline {
	std::list<Point> polyline;

	bool closedLine;

public:

	void 	addVertex(Point &point);

	DXFPline();

	const std::list<Point> &getPolyline() const;
};


#endif //DXFPARSER_DXFPLINE_HPP
