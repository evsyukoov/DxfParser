#include <iostream>
#include "main.h"
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv) {
	auto *dxf = new DL_Dxf();
	auto *parser = new DXFParser();
	if (!dxf->in(std::string(argv[1]), parser)) {
		std::cout << "Error reading" << std::endl;
		return (0);
	}
	parser->printToJavaChannel();
	//если нет блоков и замкнутых полилиний
	return (1);
}
