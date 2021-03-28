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
                    std::string plain_text;
                    for(int i=0; i<line.length();i++) {
                        char ch = line[i];

                        if (text_flag || !tag_flag ) {
                            if (ch == '<') {
                                tag_flag = true;
                                text_flag = false;
                            }
                            
                        }
                        if (tag_flag) {
                            if (ch == '<' || ch == '/'){
                                continue;
                            }
                            if (ch != '>' ) {
                                name.push_back(ch);
                            }
                            else {
                                tag_flag = false;
                                text_flag = true;
                                if (find_pos(name, data) == -1){
                                    FNNGRE002::TagStruct temp = {name, 1, ""};
                                }
                                else {
                                    int pos = find_pos(name, data);
                                    data[pos].pairs += 1;
                                }
                            }
                        }
                        if (text_flag) {
                            if (ch != '<') {
                                plain_text.push_back(ch);
                            }
                            else {
                                tag_flag = true;
                                text_flag = false;
                                int pos = find_pos(name, data);
                                data[pos].plain_text += ':' + plain_text;
                                }
                            }
                        }
                    }
                }
            return data;
            }   


        }
    
    int find_pos(std::string name, std::vector<TagStruct> data){
        for (int i=0; i < data.size(); i++){
            if (name == data[i].name){
                return i;
            }
        }
        return -1;
    }

}
