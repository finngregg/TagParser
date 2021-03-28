//
// Created by Gregg Finn on 2021/03/26.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "tagstruct.h"

#include <cstdlib>
#include <streambuf>


#ifndef _PARSER_H
#define _PARSER_H

#include "tagstruct.h"

namespace FNNGRE002{
    std::vector<TagStruct> parse_data(std::string fileName, std::vector<TagStruct> data);
    int find_pos(std::string name, std::vector<TagStruct> data);
}

#endif