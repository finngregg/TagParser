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
                while(getline(file, line)){
                    bool text_flag = true;
                    bool tag_flag = false;
                    std::string name;
                    std::string plain_text;
                    for(int i=0; i<line.length();i++) {
                        char ch = line[i];
                        char next = line[i+1];

                        /*if (!tag_flag) {
                            if (ch == '<') {
                                tag_flag = true;
                                text_flag = false;
                            }
                            continue;
                        } */
                        if (tag_flag) {
                            if (ch == '>' ) {
                                if (find_pos(name, data) == -1){
                                    FNNGRE002::TagStruct temp = {name, 0, ""};
                                    data.push_back(temp);
                                }
                                tag_flag = false;
                                text_flag = true;
                                continue;
                            }
                            else {
                                name.push_back(ch);
                                
                            }
                        }
                        if (text_flag) {
                            if (ch == '<') {
                                if (next == '/'){
                                    std::string tag_close;
                                    for(int j=i+2; j<line.length();j++) {
                                        if (line[j] != '>') {
                                            tag_close.push_back(line[j]);
                                        }
                                        else {
                                            int pos = find_pos(tag_close, data);
                                            data[pos].pairs += 1;
                                            if (data[pos].plain_text == "") {
                                                data[pos].plain_text += plain_text;
                                            }
                                            else {
                                                data[pos].plain_text += ":" + plain_text;
                                            }
                                            i = j;
                                            break;
                                        }
                                    }
                                }
                                else {
                                    tag_flag = true;
                                    text_flag = false;
                                }
                            }
                            else {
                                plain_text.push_back(ch);
                            }
                        }
                    }
                }
            }
        
        }   
        return data;

    }
    
    int find_pos(std::string name, std::vector<TagStruct> data){
        for (int i=0; i < data.size(); i++){
            if (name == data[i].name){
                return i;
            }
        }
        return -1;
    }

    std::string print_tags(std::vector<TagStruct> data){
        std::string out = "";
        for (int i=0; i < data.size(); i++){
            out += data[i].name + ", ";
            out += std::to_string(data[i].pairs) + ", ";
            out += data[i].plain_text + '\n';
        }
        return out;
    }
}
