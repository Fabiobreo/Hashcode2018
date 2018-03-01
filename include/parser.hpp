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
    void getNext(T &first, Args &... args)
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
            std::istringstream tmpStream(currentLine);
            std::string temp;
            tmpStream >> temp;

            // Resize current line and save variable
            currentLine = currentLine.length() > temp.length() + 1 ? currentLine.substr(temp.length() + 1) : "";
            std::istringstream stringStream(temp);
            stringStream >> first;
        } else
        {
            std::cerr << "Unable to open file" << std::endl;
        }

        // Recursion
        getNext(args...);
    }

    /**
     * Base class for recursion
     */
    void getNext()
    {}

    /**
     * Get next lines_to_read and put them into vector
     * @tparam T: template parameter
     * @tparam A: template parameter for allocation
     * @param vector: the vector to fill
     * @param lines_to_read: how many lines to read from file
     */
    template<typename T, typename A>
    void getNextLines(std::vector<std::vector<T, A>> &vector, int lines_to_read)
    {
        if (inputFile.is_open())
        {
            std::string line;
            int read_lines = 0;
            // Get lines and breaks them into atomic pieces
            while (std::getline(inputFile, line) && read_lines < lines_to_read)
            {
                std::vector<T> row;
                for (size_t i = 0; i < line.length(); ++i)
                {
                    T column;
                    // Exclude last character, that is a new line
                    if (line.at(i) != '\r' && line.at(i) != '\n' && line.at(i) != ' ')
                    {
                        // Convert character into T type
                        std::string character(std::string(1, line.at(i)));
                        std::istringstream stringStream(character);
                        stringStream >> column;
                        row.push_back(column);
                    }
                }
                vector.push_back(row);
                read_lines++;
            }

            // The file has less lines than expected
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
