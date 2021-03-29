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
                int curr_pos;
                while(getline(file, line)){
                    bool text_flag = true;
                    bool tag_flag = false;
                    std::string name;
                    std::string plain_text;
                    for(int i=0; i<line.length();i++) {
                        char ch = line[i];
                        char next = line[i+1];

                        if (tag_flag) {
                            if (ch == '>' ) {
                                if (find_pos(name, data) == -1){
                                    FNNGRE002::TagStruct temp = {name, 0, ""};
                                    data.push_back(temp);
                                    curr_pos = data.size() - 1;
                                }
                                else {
                                    int pos = find_pos(name, data);
                                    curr_pos = pos;
                                    data[curr_pos].plain_text += ":";
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
                                if (next == ' '){
                                    plain_text.push_back(ch);
                                    continue;
                                }
                                else if (next == '/'){
                                    curr_pos -= 1;
                                    std::string tag_close;
                                    for(int j=i+2; j<line.length();j++) {
                                        if (line[j] != '>') {
                                            tag_close.push_back(line[j]);
                                        }
                                        else {
                                            int pos = find_pos(tag_close, data);
                                            data[pos].pairs += 1;
                                            data[pos].plain_text += plain_text;
                                            /*if (data[pos].plain_text == "") {
                                                data[pos].plain_text += plain_text;
                                            }
                                            else {
                                                data[pos].plain_text += plain_text;
                                            }*/
                                            i = j;
                                            break;
                                        }
                                    }
                                }
                                else {
                                    if (plain_text.length() != 0) {
                                        if (data[curr_pos].plain_text == "") {
                                            data[curr_pos].plain_text += plain_text;
                                        }
                                        else {
                                        data[curr_pos].plain_text += ":" + plain_text;
                                        }
                                    }
                                    tag_flag = true;
                                    text_flag = false;
                                }
                            }
                            else {
                                if (i == line.length()-1) {
                                    plain_text.push_back(ch);
                                    data[curr_pos].plain_text += plain_text;
                                    /*if (data[curr_pos].plain_text == "") {
                                        data[curr_pos].plain_text += plain_text;
                                    }
                                    else {
                                        data[curr_pos].plain_text += plain_text;
                                    }*/
                                }
                                else {
                                    plain_text.push_back(ch);
                                }
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

    std::string print_tag(std::string name, std::vector<TagStruct> data){
        std::string out = "";
        if (find_pos(name, data) != -1){
            int pos = find_pos(name, data);
            out += data[pos].name + ", ";
            out += std::to_string(data[pos].pairs) + ", ";
            out += data[pos].plain_text + '\n';
        }
        else {
            out = "Tag does not exist";
        }
        return out;
    }
}
