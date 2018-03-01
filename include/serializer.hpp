#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "vehicle.hpp"

class Serializer
{
public:
    /**
     * Constructor for the Serializer class
     * @param fileName: the path of the file to write in.
     */
    explicit Serializer(std::string fileName);

    /**
     * Destructor
     */
    ~Serializer();

    /**
     * Print the elements given in the argument.
     * @tparam T: template parameter
     * @tparam Args: template parameter pack
     * @param first: the element to print first
     * @param args: the rest of the elements
     */
    template<typename T, typename... Args>
    void printNext(T &first, Args &... args)
    {
        if (outputFile.is_open())
        {
            outputFile << first << " ";
        } else
        {
            std::cerr << "Unable to open file" << std::endl;
        }

        // Recursion
        printNext(args...);
    }

    /**
     * Print the element in the file and go to next line.
     * @tparam T: template parameter
     * @tparam Args: template parameter pack
     * @param element: the element to print
     */
    template<typename T>
    void printNext(T &element)
    {
        if (outputFile.is_open())
        {
            outputFile << element << std::endl;
        } else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

    /**
     * Print a vector of elements
     * @tparam T: template parameter
     * @tparam A: vector template parameter
     * @param vector: the vector to print
     */
    template<typename T, typename A>
    void printVector(std::vector<std::vector<T, A>> &vector)
    {
        if (outputFile.is_open())
        {
            for (std::vector<T> row : vector)
            {
                for (T column : row)
                {
                    outputFile << column;
                }
                outputFile << std::endl;
            }
        } else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

    void printVehicle(std::vector<Vehicle>& vehicles);

private:
    std::ofstream outputFile;
};

#endif //SERIALIZER_HPP
