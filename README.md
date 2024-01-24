# Parser

Parser is a program capable of parsing a text ﬁle which contains XML-like tags and storing the data. 

## Usage

tagstruct.h initilaizes a named struct type which is used throughout the code for storing a tags name, number of pairs and the text found betwene said pairs.
parser.h is the header file used to declare the namespace and any methods to be used within parser.cpp
parser.cpp deals with the string processing of a file once it has been read in, making sure tags and their respective data are stored correctly. 
driver.cpp is where the menu is created. The menu asks the users for input such as what file they want to parse, where the data shoudl be stored etc. 





