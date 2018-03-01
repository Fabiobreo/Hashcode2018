#include <iostream>
#include <parser.hpp>
#include <serializer.hpp>
#include <log.hpp>
#include <ride.hpp>

Log logger;

int main(int argc, char *argv[])
{
    // Get the path of the file input where we can change the true input file
    Parser path_parser(argv[1]);
    std::string input_path, output_path;
    path_parser.getNext(input_path);
    path_parser.getNext(output_path);

    // Parse input
    Parser input_file(input_path);

    int rows, cols, fleets, n_rides, bonus, steps;
    std::vector<std::vector<int>> tmp_rides;

    input_file.getNext(rows, cols, fleets, n_rides, bonus, steps);

    input_file.getNextLines(tmp_rides, n_rides);
    logger.log(rows, cols, fleets, n_rides, bonus, steps);
    logger.log(tmp_rides);

    std::vector<Ride> rides;
    int n_ride = 0;
    for (std::vector<int> a_ride : tmp_rides)
    {
        rides.push_back(Ride(n_ride, a_ride.at(0), a_ride.at(1), a_ride.at(2), a_ride.at(3), a_ride.at(4), a_ride.at(5)));
        n_ride++;
    }

    for (int t = 0; t < steps; t++)
    {

    }
    /*
    // Usage example
    int first;
    double second;
    std::string third;
    std::string fourth;
    input_file.getNext(first, second, third, fourth);
    std::vector<std::vector<std::string>> vec;
    input_file.getNextLines(vec, first);

    logger.log("First:", first);
    logger.log("Second:", second);
    logger.log("Third:", third);
    logger.log("Fourth", fourth);
    logger.log("Vec:");
    logger.log(vec);

    Serializer output_file(output_path);
    output_file.printNext(first, second, third, fourth);
    output_file.printVector(vec);
    */

    return 0;
}