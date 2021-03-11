//
// Created by Денис on 10/03/2021.
//

#include "DXFParser.hpp"

void DXFParser::addInsert(const DL_InsertData &data) {
	//невидимые блоки попадают в начало чертежа, убираем
	if ((data.ipx <= 10 && data.ipx >= -10) || (data.ipy <= 10 && data.ipy >= -10))
		return ;
	//std::cout << "INSERT " << data.name << " " <<  data.ipx << " , " << data.ipy << std::endl;
	block = new DXFBlock();
	Point p(data.ipx, data.ipy);
	block->setBlockName(data.name);
	block->setCoords(p);
	blocks.push_back(block);
}

void DXFParser::addText(const DL_TextData &data) {
	if ((data.ipx <= 10 && data.ipx >= -10) || (data.ipy <= 10 && data.ipy >= -10))
		return ;
	if (!data.text.empty() && data.text[0] != '\\')
		block->addDescription(data.text);
}

const list<DXFBlock*> &DXFParser::getBlocks() const {
	return blocks;
}

void DXFParser::addPointName() {
	//будем считать что первое описание блока и есть его имя
	std::list<std::string> blockDescr;
	for(auto it = blocks.begin(); it != blocks.end(); it++)
	{
		blockDescr = (*it)->getDescription();
		(*it)->setPointName(*blockDescr.begin());
	}
}

void DXFParser::addVertex(const DL_VertexData &data) {
	if ((data.x <= 100 && data.x >= -100) || (data.y <= 100 && data.y >= -100))
		return;
	if (!polyline || polyline->isClosedLine()) {
		polyline = new DXFPline();
		polyline->setClosedLine(false);
	}
	Point point(data.x, data.y);
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
			std::string name = (*it)->getPointName().empty() ? std::to_string(i++) : (*it)->getPointName();
			result.append(name + "," + std::to_string((*it)->getCoords().x)
			+ "," + std::to_string((*it)->getCoords().y));
			if (it != --(blocks.end()))
				result.append(";");
		}
		result.append("}");
		result.append("\n");
	} else
		result.append("blocks:false");
	if (!lines.empty()) {
		result.append("plines:true{");
		for (auto it = lines.begin(); it != lines.end(); it++) {
			auto line = (*it)->getPolyline();
			int i = 1;
			for (auto itt = line.begin(); itt != line.end(); itt++)
			{
				result.append(std::to_string(i++) + "," + std::to_string(itt->x) + "," + std::to_string(itt->y));
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











