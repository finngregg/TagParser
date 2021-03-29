//
// Created by Gregg Finn on 2021/03/26.
//

#ifndef _PARSER_H
#define _PARSER_H

#include "tagstruct.h"

namespace FNNGRE002{
    std::vector<TagStruct> parse_data(std::string fileName, std::vector<TagStruct> data);
    int find_pos(std::string name, std::vector<TagStruct> data);
    std::string print_tags(std::vector<TagStruct> data);
    std::string print_tag(std::string name, std::vector<TagStruct> data);
}

#endif