#include <serializer.hpp>

Serializer::Serializer(std::string fileName)
{
    outputFile.open(fileName);
}

Serializer::~Serializer()
{
    outputFile.close();
}


void Serializer::printVehicle(std::vector<Vehicle>& vehicles)
{
    for (Vehicle vec : vehicles)
    {
        if (outputFile.is_open())
        {
            outputFile << vec.rides.size();
            for (Ride ride : vec.rides)
            {
                outputFile << " " << ride.id;
            }
            outputFile << std::endl;
        }
        else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }
}