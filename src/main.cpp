#include <iostream>
#include <parser.hpp>
#include <serializer.hpp>
#include <log.hpp>

Log logger;

int calculatePriority(Vehicle* vec, Ride* ride)
{
    int prio = std::abs(ride->start_row - vec->current_row) + std::abs(ride->start_col - vec->current_col) + std::abs(ride->start_row - ride->end_row) + std::abs(ride->start_col - ride->end_col);
    return (ride->latest_finish - ride->early_start) - prio;
}

class Priority
{
public:

    Priority(int _priority, Vehicle* _vec, Ride* _ride) :
    priority(_priority),
    vec(_vec),
    ride(_ride)
    {}

    bool operator < (const Priority& prio) const
    {
        return (priority < prio.priority);
    }

    int priority;
    Vehicle* vec;
    Ride* ride;

};

int main(int argc, char *argv[])
{
    // Get the path of the file input where we can change the true input file
    Parser path_parser(argv[1]);
    std::string input_path, output_path;
    path_parser.getNext(input_path);
    path_parser.getNext(output_path);

    // Parse input
    Parser input_file(input_path);

    int rows, cols, n_vehicles, n_rides, bonus, steps;
    std::vector<std::vector<int>> tmp_rides;

    input_file.getNext(rows, cols, n_vehicles, n_rides, bonus, steps);

    input_file.getNextLines(tmp_rides, n_rides);
//    logger.log(rows, cols, n_vehicles, n_rides, bonus, steps);
//    logger.log(tmp_rides);


    // Create vehicles
    std::vector<Vehicle> vehicles;
    for (int i = 0; i < n_vehicles; ++i)
    {
        Vehicle vec(i);
        vehicles.push_back(vec);
    }

    // Create rides

    std::vector<Ride> rides;
    int n_ride = 0;

    for (std::vector<int> a_ride : tmp_rides)
    {
        Ride yolo(n_ride, a_ride.at(0), a_ride.at(1), a_ride.at(2), a_ride.at(3), a_ride.at(4), a_ride.at(5));
        rides.push_back(yolo);
        n_ride++;
    }

    std::sort(rides.begin(), rides.end());

    for (int t = 0; t < steps; t++)
    {
        std::vector<Priority> priorities;
        for (Vehicle& vec : vehicles)
        {
            if (!vec.going_to_start_point && !vec.going_to_destination)
            {
                for (Ride &ride : rides)
                {
                    Priority prio(calculatePriority(&vec, &ride), &vec, &ride);
                    priorities.push_back(prio);
                }
            }
        }

        std::vector<Priority> admissible_priorities;
        for (Priority& prio : priorities)
        {
            if (prio.priority >= 0)
            {
                admissible_priorities.push_back(prio);
            }
        }

        std::sort(admissible_priorities.begin(), admissible_priorities.end());

        while (!admissible_priorities.empty())
        {
            size_t i = 0;

            for (i; i < vehicles.size(); ++i)
            {
                if (!(vehicles.at(i)).going_to_start_point && !(vehicles.at(i)).going_to_destination)
                {
                    if (admissible_priorities.at(0).vec->id == vehicles.at(i).id)
                    {
                        break;
                    }
                }
            }

            if (i < vehicles.size())
            {
                int rideId = admissible_priorities.at(0).ride->id;
                int vecId = admissible_priorities.at(0).vec->id;
                vehicles.at(i).addRide(*admissible_priorities.at(0).ride);
                for (size_t j = 0; j < admissible_priorities.size(); j++)
                {
                    if (admissible_priorities.at(j).ride->id == rideId ||
                            admissible_priorities.at(j).vec->id == vecId)
                    {
                        admissible_priorities.erase(admissible_priorities.begin() + j);
                        j--;
                    }
                }

                size_t k = 0;
                for (k; k < rides.size(); k++)
                {
                    if (rides.at(k).id == rideId)
                        break;
                }

                if (k < rides.size())
                {
                    rides.erase(rides.begin() + k);
                }

            }
        }

        for (Vehicle& vec: vehicles)
        {
            vec.update(t);
        }


        if (rides.empty())
        {
            break;
        }

        logger.log("Time:", t);

    }


    Serializer output_file(output_path);
    output_file.printVehicle(vehicles);

    return 0;
}