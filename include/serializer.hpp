#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <fstream>
#include <vector>

class Serializer
{
public:
    explicit Serializer(std::string fileName);

    ~Serializer();

    template<typename T, typename... Args>
    void printNext(T& first, Args&... args)
    {
        if (outputFile.is_open())
        {
            outputFile << first << " ";
        }
        else
        {
            std::cerr << "Unable to open file" << std::endl;
        }

        // Recursion
        printNext(args...);
    }

    template<typename T, typename... Args>
    void printNext(T& element)
    {
        if (outputFile.is_open())
        {
            outputFile << element << std::endl;
        }
        else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

    template<typename T, typename A>
    void printVector(std::vector<T, A> &vector)
    {
        if (outputFile.is_open())
        {
            for(T line: vector)
            {
                outputFile << line << std::endl;
            }
        }
        else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

private:
    std::ofstream outputFile;
};
#endif //SERIALIZER_HPP
