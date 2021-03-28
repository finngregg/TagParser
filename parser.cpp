//
// Created by Gregg Finn on 2021/03/26.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <streambuf>

#include "tagstruct.h"

std::vector<FNNGRE002::TagStruct> FNNGRE002::readFile(std::string fileName, std::vector<TagStruct> data){
    std::ifstream t(fileName);
    std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());

}