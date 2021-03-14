//
// Created by Денис on 10/03/2021.
//

#include "DXFParser.hpp"

void DXFParser::addInsert(const DL_InsertData &data) {
	//невидимые блоки попадают в начало чертежа, убираем
	if ((data.ipx <= 10 && data.ipx >= -10) && (data.ipy <= 10 && data.ipy >= -10))
		return ;
	block = new DXFBlock();
	Point p(data.ipx, data.ipy, data.ipz);
	block->setBlockName(data.name);
	block->setCoords(p);
	blocks.push_back(block);
}

void DXFParser::addAttribute(const DL_AttributeData &data) {
	if ((data.ipx <= 10 && data.ipx >= -10 && data.ipy <= 10 && data.ipy >= -10) || !block)
		return ;
	if (data.text.empty())
		return ;
	if (isBlockAttribute(data.ipx, data.ipy) && block->getPointName().empty())
		block->setPointName(data.text);
}

const list<DXFBlock*> &DXFParser::getBlocks() const {
	return blocks;
}

void DXFParser::addVertex(const DL_VertexData &data) {
	if ((data.x <= 100 && data.x >= -100) && (data.y <= 100 && data.y >= -100))
		return;
	if (!polyline || polyline->isClosedLine()) {
		polyline = new DXFPline();
		polyline->setClosedLine(false);
	}
	Point point(data.x, data.y, data.z);
	if (!polyline->addVertex(point)) {
		lines.push_back(polyline);
		polyline->setClosedLine(true);
	}
}

std::string DXFParser::createStringToJavaProgram() {
	std::string result;
	if (blocks.size() == 0 && lines.size() == 0)
		return "";
	if (!blocks.empty())
	{
		result.append("blocks:true{");
		int i = 1;
		for(auto it = blocks.begin(); it != blocks.end(); it++)
		{
			if ((*it)->getPointName().empty())
				(*it)->setPointName((*it)->getBlockName());
			result.append((*it)->getPointName() + "," + std::to_string((*it)->getCoords().x)
			+ "," + std::to_string((*it)->getCoords().y) + "," + std::to_string((*it)->getCoords().z));
			if (it != --(blocks.end()))
				result += ";";
		}
		result.append("}");
		result.append("\n");
	} else
		result.append("blocks:false\n");
	if (!lines.empty()) {
		result.append("plines:true{");
		for (auto it = lines.begin(); it != lines.end(); it++) {
			auto line = (*it)->getPolyline();
			int i = 1;
			for (auto itt = line.begin(); itt != line.end(); itt++)
			{
				result.append(std::to_string(i++) + "," + std::to_string(itt->x) + "," + std::to_string(itt->y) +
				+ "," + std::to_string(itt->z));
				if (itt != --line.end())
					result.append(";");
			}
			if (it != --lines.end())
				result.append(" ");
		}
		result.append("}");
	} else
		result.append("plines:false");;
	return result;
}

bool DXFParser::isBlockAttribute(double xAttr, double yAttr) {
	return pow(xAttr - block->getCoords().x, 2) + pow(yAttr - block->getCoords().y, 2) < 9;
}











