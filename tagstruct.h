//
// Created by Gregg Finn on 2021/03/26.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#include <cstdlib>
#include <streambuf>

#ifndef TAG_STRUCT_H
#define TAG_STRUCT_H

namespace FNNGRE002{
    struct TagStruct{
        std::string name;
        int pairs;
        std::string plain_text;
    };
}

#endif 