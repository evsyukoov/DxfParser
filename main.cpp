#include <iostream>
#include "main.h"

int main(int argc, char **argv) {
	(void)argc;
	auto *dxf = new DL_Dxf();
	auto *parser = new DXFParser();
	if (!dxf->in(argv[1], parser)) {
		std::cout << "Error reading" << std::endl;
		return (0);
	}
	parser->addPointName();
	std::string toJAVA = parser->createStringToJavaProgram();
	//если нет блоков и замкнутых полилиний
	if (toJAVA.empty())
		return (2);
	std::cout << toJAVA << std::endl;
	return 1;
}
