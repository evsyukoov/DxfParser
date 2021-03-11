cmake_minimum_required(VERSION 3.16)
project(DxfParser)

set(CMAKE_CXX_STANDARD 14)
link_directories(/usr/local/Cellar/dxflib/2.5.0.0-1/lib)
add_executable(DxfParser main.cpp
        DXFParser.cpp
                        DXFBlock.cpp
                        Point.cpp
        DXFPline.cpp)

target_link_libraries(DxfParser dxflib)