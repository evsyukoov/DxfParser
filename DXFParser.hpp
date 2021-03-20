//
// Created by Денис on 10/03/2021.
//


#ifndef DXFPARSER_DXFPARSER_HPP
#define DXFPARSER_DXFPARSER_HPP

#include "main.h"
#include "DXFBlock.hpp"
#include "DXFPline.hpp"
#include <unistd.h>
class DXFParser : public DL_CreationAdapter {

	DXFBlock *block;

	std::list<DXFBlock*> blocks;

	DXFPline *polyline;

	std::list<DXFPline*> lines;

	std::list<std::string> description;

public:
	const std::list<DXFBlock*> &getBlocks() const;

	DXFParser();

public:

	void addInsert(const DL_InsertData &data) override;

	void addVertex(const DL_VertexData &data) override;

	void	 printToJavaChannel();

	void addAttribute(const DL_AttributeData &data) override;

	bool isBlockAttribute(double xAttr, double yAttr);

	void addPolyline(const DL_PolylineData &data) override;


};


#endif //DXFPARSER_DXFPARSER_HPP
