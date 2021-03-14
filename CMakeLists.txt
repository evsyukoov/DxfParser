cmake_minimum_required(VERSION 3.16)
project(DxfParser)

set(CMAKE_CXX_STANDARD 14)
link_directories(/Users/denis/Denis/DxfParser/dxflib-3.17.0-src/src)
add_executable(DxfParser main.cpp
        DXFParser.cpp
                        DXFBlock.cpp
                        Point.cpp
        DXFPline.cpp)

target_link_libraries(DxfParser dxflib)