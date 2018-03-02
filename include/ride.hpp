#ifndef RIDE_HPP
#define RIDE_HPP

class Ride
{
public:
    explicit Ride(int _id,
         int _start_row,
         int _start_col,
         int _end_row,
         int _end_col,
         int _early_start,
         int _latest_finish) :
            id(_id),
            start_row(_start_row),
            start_col(_start_col),
            end_row(_end_row),
            end_col(_end_col),
            early_start(_early_start),
            latest_finish(_latest_finish)
    {}

    bool operator < (const Ride& ride) const
    {
        return (priority < ride.priority);
    }

    int id;
    int start_row;
    int start_col;
    int end_row;
    int end_col;
    int early_start;
    int latest_finish;
    int priority;
};

#endif //RIDE_HPP
