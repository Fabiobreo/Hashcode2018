#include <vehicle.hpp>

void Vehicle::addRide(Ride aRide)
{
    rides.push_back(aRide);
    current_ride = aRide;
    moving_counter = std::abs(current_ride.start_row - current_row) + std::abs(current_ride.start_col - current_col);
    going_to_start_point = true;
}

void Vehicle::update(int step)
{
    if (going_to_start_point)
    {
        moving_counter--;
        if (moving_counter == 0)
        {
            going_to_start_point = false;
            going_to_destination = true;
            moving_counter = std::abs(current_ride.end_row - current_ride.start_row) + std::abs(current_ride.end_col - current_ride.start_col);
        }
    }
    else if (going_to_destination)
    {
        if (step >= current_ride.early_start)
        {
            moving_counter--;
            if (moving_counter == 0)
            {
                current_row = current_ride.end_row;
                current_col = current_ride.end_col;
                going_to_destination = false;
            }
        }
    }
}