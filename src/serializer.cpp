#include <serializer.hpp>

Serializer::Serializer(std::string fileName)
{
    outputFile.open(fileName);
}

Serializer::~Serializer()
{
    outputFile.close();
}