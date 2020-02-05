#include "parser.h"
Parser::Parser()
{

}

std::map<std::string, std::string> Parser::parseVariables(std::string data, std::vector<std::string> variables)
{
    std::map<std::string, std::string> returnVariables;
    size_t varPosition;
    size_t valuePosition;
    size_t sliceStart;
    size_t sliceEnd;
    std::string value;
    for (unsigned int i = 0; i < variables.size(); i++) {
        varPosition = data.find(variables.at(i));
        if (varPosition != std::string::npos) {
            // string found in data
            valuePosition = data.find("value=", varPosition);
            sliceStart = data.find("\"", valuePosition);
            sliceEnd = data.find("\"", sliceStart + 1);
            value = data.substr(sliceStart + 1, sliceEnd - sliceStart - 1);

            std::cout << variables.at(i) + " found: " << value << std::endl;

        }
        else {
            qDebug() << "not found!";
        }

    }

    return returnVariables;
}
