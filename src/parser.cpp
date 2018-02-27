#include <parser.hpp>

Parser::Parser(std::string fileName)
{
    inputFile.open(fileName);
}

Parser::~Parser()
{
    inputFile.close();
}