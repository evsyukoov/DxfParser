//
// Created by Денис on 10/03/2021.
//


#ifndef DXFPARSER_DXFPARSER_HPP
#define DXFPARSER_DXFPARSER_HPP

#include "main.h"
#include "DXFBlock.hpp"
#include "DXFPline.hpp"

class DXFParser : public DL_CreationAdapter {

	DXFBlock *block;

	std::list<DXFBlock*> blocks;

	DXFPline *polyline;

	std::list<DXFPline*> lines;

	std::list<std::string> description;

public:
	const std::list<DXFBlock*> &getBlocks() const;

	void 	addPointName();

public:

	void addInsert(const DL_InsertData &data) override;

	void addText(const DL_TextData &data) override;

	void addVertex(const DL_VertexData &data) override;

	std::string	createStringToJavaProgram();

};


#endif //DXFPARSER_DXFPARSER_HPP