//
// Created by Денис on 10/03/2021.
//

#include "DXFBlock.hpp"

void DXFBlock::setPointName(const std::string &pointName) {
	DXFBlock::pointName = pointName;
}

void DXFBlock::setCoords(const Point &coords) {
	DXFBlock::coords = coords;
}


const std::string &DXFBlock::getPointName() const {
	return pointName;
}

const Point &DXFBlock::getCoords() const {
	return coords;
}

const std::list<std::string> &DXFBlock::getDescription() const {
	return description;
}

DXFBlock::DXFBlock() {}

void DXFBlock::setBlockName(const std::string &blockName) {
	DXFBlock::blockName = blockName;
}

const std::string &DXFBlock::getBlockName() const {
	return blockName;
}
