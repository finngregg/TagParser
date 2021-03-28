#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#include "tagstruct.h"
#include "parser.h"
#include "parser.cpp"

void clear(void);

void clear(void) {
    system("clear");
}

int main(int argc, char * argv[]) {

    std::string fileName = "edge_cases.txt";

    std::vector<FNNGRE002::TagStruct> tags;
    tags = parse_data(fileName, tags);

    std::string in = "Start";

    while(in.compare("q")!=0) {
        in = "Start";
        cout << "Choose an option from the following:"
                "\nr: Read and parse file"
                "\np: Print all tags"
                "\nd: Write tags and data"
                "\nl: List tag data"
                "\nq: Quit\n\n";

        cin >> in;
        cout << "\n";

        switch (in[0]) {
            case 'r': {
                
                break;
            }
            case 'p': {
                
                break;
            }
            case 'd': {
                
                break;
            }
            case 'l': {
                
                break;
            }
          
            case 'q': {
                break;
            }
            default: {
                cout << "Invalid option. Please try again.\n\n";
            }
        }

    }
    clear();
    return 0;