#include <vehicle.hpp>

void Vehicle::addRide(Ride* aRide)
{
    rides.push_back(aRide);
    current_ride = aRide;
    moving_counter = std::abs(current_ride->startRow - current_row) + std::abs(current_ride->startCol - current_col);
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
            moving_counter = std::abs(current_ride->endRow - current_ride->startRow) + std::abs(current_ride->endCol - current_ride->startCol);
        }
    }
    else if (going_to_destination)
    {
        if (step >= current_ride->earlyStart)
        {
            moving_counter--;
            if (moving_counter == 0)
            {
                current_row = current_ride->endRow;
                current_col = current_ride->endCol;
                current_ride = nullptr;
                going_to_destination = false;
            }
        }
    }
}