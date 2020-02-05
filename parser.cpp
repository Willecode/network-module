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

    // look for all variables in data
    for (unsigned int i = 0; i < variables.size(); i++) {
        varPosition = data.find(variables.at(i));
        if (varPosition != std::string::npos) {
            // string found in data, parse value
            valuePosition = data.find("value=", varPosition);
            sliceStart = data.find("\"", valuePosition);
            sliceEnd = data.find("\"", sliceStart + 1);
            value = data.substr(sliceStart + 1, sliceEnd - sliceStart - 1);

            // add variable and value to map
            returnVariables[variables.at(i)] = value;
        }
        else {
            qDebug() << "not found!";
        }

    }

    return returnVariables;
}
