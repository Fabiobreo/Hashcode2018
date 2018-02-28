#include <iostream>
#include <parser.hpp>
#include <serializer.hpp>

int main(int argc, char *argv[])
{
    // Get the path of the file input where we can change the true input file
    Parser path_parser(argv[1]);
    std::string input_path, output_path;
    path_parser.getNext(input_path);
    path_parser.getNext(output_path);

    // Parse input
    Parser input_file(input_path);

    /*
    // Usage example
    int first;
    double second;
    std::string third;
    std::string fourth;
    input_file.getNext(first, second, third, fourth);
    std::vector<std::vector<std::string>> vec;
    input_file.getNextLines(vec, first);
    Serializer output_file(output_path);
    output_file.printNext(first, second, third, fourth);
    output_file.printVector(vec);
    */

    return 0;
}