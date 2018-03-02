#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <ride.hpp>

class Vehicle
{
public:
    explicit Vehicle(int _id) :
            id(_id),
            current_row(0),
            current_col(0),
            going_to_start_point(false),
            going_to_destination(false),
            moving_counter(0),
            current_ride(Ride(-1, 0, 0, 0, 0, 0, 0)){}

    void addRide(Ride aRide);

    void update(int step);

    bool operator == (const Vehicle& vec) const
    {
        return (id == vec.id);
    }

    std::vector<Ride> rides;
    Ride current_ride;
    int id;
    int current_row;
    int current_col;
    int moving_counter;
    bool going_to_start_point;
    bool going_to_destination;
};

#endif //VEHICLE_HPP
