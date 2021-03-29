#include "parser.cpp"

void clear(void);

void clear(void) {
    system("clear");
}

int main(int argc, char * argv[]) {

    std::string fileName;
    std::string tag_name;

    std::vector<FNNGRE002::TagStruct> tags;

    std::string in = "Start";

    while(in.compare("q")!=0) {
        in = "Start";
        std::cout << "Choose an option from the following:"
                "\nr: Read and parse file"
                "\np: Print all tags"
                "\nd: Write tags and data"
                "\nl: List tag data"
                "\nq: Quit\n\n";

        std::cin >> in;
        std::cout << "\n";

        switch (in[0]) {
            case 'r': {
                std::cout << "Enter the filename: ";
                std::cin >> fileName;
                tags = parse_data(fileName, tags);
                break;
            }
            case 'p': {
                std::string out = print_tags(tags);
                std::cout << out;
                break;
            }
            case 'd': {
                std::ofstream myfile ("tag.txt");
                if (myfile.is_open())
                {
                    myfile << print_tags(tags);
                    myfile.close();
                }
                else {
                    std::cout << "Unable to open file";
                    return 0;
                }
                break;
            }
            case 'l': {
                std::cout << "Enter the tag: ";
                std::cin >> tag_name;
                std::cout << print_tag(tag_name, tags);
                break;
            }
          
            case 'q': {
                break;
            }
            default: {
                std::cout << "Invalid option. Please try again.\n\n";
            }
        }

    }
    clear();
    return 0;
}