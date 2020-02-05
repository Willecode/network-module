#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <vector>

//debugging
#include <QDebug>
#include <iostream>

/**
 * @brief The Parser class to get variables from html´
 */
class Parser
{
public:
    Parser();
    std::map<std::string, std::string> parseVariables(std::string data, std::vector<std::string> variables);
};

#endif // PARSER_H
