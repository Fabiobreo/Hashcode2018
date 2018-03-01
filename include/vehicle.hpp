#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <vector>
#include <ride.hpp>

class Vehicle
{
public:
    Vehicle() :
            current_row(0),
            current_col(0) {}

    void addRide(Ride &aRide);

    void update();

    std::vector<Ride> rides;
    int current_row;
    int current_col;
};

#endif //VEHICLE_HPP
