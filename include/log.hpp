#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <vector>

class Log
{

public:

    /**
     * Constructor for the Log class
     */
    Log() = default;

    /**
     * Destructor
     */
    ~Log() = default;

    /**
     * Print to log the arguments, divided by whitespaces
     * @tparam T: template parameter
     * @tparam Args: template parameter pack
     * @param first: the first element to log
     * @param args: the rest of the elements
     */
    template<typename T, typename... Args>
    void log(T &first, Args &... args)
    {
        std::cout << first << " ";
        log(args...);
    };

    /**
     * Print to log the argument and end the line
     * @tparam T: template parameter
     * @param element: the element to log
     */
    template<typename T>
    void log(T &element)
    {
        std::cout << element << std::endl;
    };

    /**
     * Print to log a vector of vector
     * @tparam T: template parameter
     * @tparam A: template parameter for allocation
     * @param matrix: the vector to log
     */
    template<typename T, typename A>
    void log(std::vector<std::vector<T, A>> &matrix)
    {
        for (std::vector<T> row : matrix)
        {
            for (T col : row)
            {
                std::cout << col;
            }
            std::cout << std::endl;
        }
    };
};

#endif //LOG_HPP
