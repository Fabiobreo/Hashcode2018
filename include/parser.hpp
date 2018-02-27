#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Parser
{

public:
    /**
     * Constructor for the Parser class
     * @param fileName: the path of the file to open
     */
    explicit Parser(std::string fileName);

    /**
     * Destructor
     */
    ~Parser();

    /**
     * Get next element between whitespaces and put it into first
     * @tparam T: template parameter
     * @tparam Args: template parameter pack
     * @param first: the element to set
     * @param args: the rest of the elements
     */
    template<typename T, typename... Args>
    void getNext(T& first, Args&... args)
    {
        if (inputFile.is_open())
        {

            // Get new line
            if (currentLine.length() == 0)
            {
                if (!std::getline(inputFile, currentLine))
                {
                    std::cerr << "End Of File" << std::endl;
                    return;
                }
            }

            // Put next characters, till whitespace, in temp
            std::istringstream stringStream(currentLine);
            std::string temp;
            stringStream >> temp;

            // Resize current line and save variable
            currentLine = currentLine.length() > temp.length() + 1 ? currentLine.substr(temp.length() + 1) : "";
            stringStream = std::istringstream(temp);
            stringStream >> first;
        }
        else
        {
            std::cerr << "Unable to open file" << std::endl;
        }

        // Recursion
        getNext(args...);
    }

    /**
     * Base class for recursion
     */
    void getNext() {}

    /**
     * Get next lines_to_read and put them into vector
     * @tparam T: template parameter
     * @tparam A: template parameter for allocation
     * @param vector: the vector to fill
     * @param lines_to_read: how many lines to read from file
     */
    template<typename T, typename A>
    void getNextLines(std::vector<T, A> &vector, int lines_to_read)
    {
        if (inputFile.is_open())
        {
            T line;
            int read_lines = 0;
            while (std::getline(inputFile, line) && read_lines < lines_to_read)
            {
                read_lines++;
                vector.push_back(line);
            }

            if (read_lines < lines_to_read)
            {
                std::cerr << "Lines read: " << read_lines << "/" << lines_to_read << std::endl;
            }
        } else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

private:
    std::ifstream inputFile;
    std::string currentLine;

};

#endif //PARSER_HPP
