//
// Created by Gregg Finn on 2021/03/26.
//


#include "parser.h"

namespace FNNGRE002{

std::vector<TagStruct> parse_data(std::string fileName, std::vector<TagStruct> data){
    std::ifstream file(fileName.c_str()); 
    std::string line;

    if(file){
        while(!file.eof()){
            bool text_flag = false;
            bool tag_flag = false;
            while(getline(file, line)){
                std::string name;
                for(int i=0; i<line.length();i++) {
                    char ch = line[i];

                    if (text_flag || !tag_flag ) {
                        if (ch == '<') {
                            tag_flag = true;
                        }
                        
                    }
                    if (tag_flag) {
                        if (ch != '>') {
                            name.push_back(ch);
                        }
                        else {
                            tag_flag = false;
                            text_flag = true;
                            if (std::find(data.begin(), data.end(), name) != data.end()){

                            }
                        }
                    }
                    switch (i) {
                        case 0: {
                            instance.Name = temps[i];
                            break;
                        }
                        case 1: {
                            instance.Surname = temps[i];
                            break;
                        }
                        case 2: {
                            instance.StudentNumber = temps[i];
                            break;
                        }

                        default: {
                            if (i == temps.size() - 1) {
                                results += temps[i];
                            } else {
                                results += temps[i] + " ";
                            }
                        }
                    }
                FNNGRE002::TagStruct temp_tag = {"", 0, ""};
                
            }
        }
        return data;
    }


}

int find_pos(std::string name){

}
}