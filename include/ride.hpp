#ifndef RIDE_HPP
#define RIDE_HPP

class Ride
{
public:
    Ride(int _rideId,
         int _startRow,
         int _startCol,
         int _endRow,
         int _endCol,
         int _earlyStart,
         int _latestFinish) :
            rideId(_rideId),
            startRow(_startRow),
            startCol(_startCol),
            endRow(_endRow),
            endCol(_endCol),
            earlyStart(_earlyStart),
            latestFinish(_latestFinish)
    {}

    int rideId;
    int startRow;
    int startCol;
    int endRow;
    int endCol;
    int earlyStart;
    int latestFinish;
};

#endif //RIDE_HPP
