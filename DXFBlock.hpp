//
// Created by Денис on 10/03/2021.
//
#ifndef DXFPARSER_DXFBLOCK_HPP
#define DXFPARSER_DXFBLOCK_HPP

#include "Point.hpp"
#include <list>
#include <string>

class DXFBlock {
	std::string blockName;
	std::string pointName;
	Point coords;
	std::list<std::string> description;

public:
	DXFBlock();

	const std::string &getBlockName() const;

	void setBlockName(const std::string &blockName);

	void setPointName(const std::string &pointName);

	void setCoords(const Point &coords);

	const std::string &getPointName() const;

	const Point &getCoords() const;

	const std::list<std::string> &getDescription() const;

};


#endif //DXFPARSER_DXFBLOCK_HPP
