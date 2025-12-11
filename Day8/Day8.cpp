#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <cmath>

using namespace std;

struct point
{
        int x, y, z = 0;
};

struct circuit
{
        vector<point> points = {};
};

double CalculateDistance(long long x, long long y, long long z)
{
    // Formula
    //    ____________________
    // --v (x^2 + y^2 + z^2)
    return sqrt(x * x + y * y + z * z);
}

void First()
{
    const int numOfConnectionsNeeded = 10;
    int connectionCounter = 0;

    ifstream MyReadFile("input.txt");

    vector<circuit> circuits = {};

    while (true)
    {
        string input;
        getline(MyReadFile, input);

        // Empty line handle
        if (input == "")
        {
            break;
        }
        else
        {
            string delimiter = ",";
            string firstAsString = input.substr(0, input.find(delimiter));
            string secondAsString = input;
            secondAsString.erase(0, secondAsString.find(delimiter) + delimiter.length());
            string thirdAsString = secondAsString;
            thirdAsString.erase(0, thirdAsString.find(delimiter) + delimiter.length());
            auto temp1 = firstAsString.c_str();
            auto temp2 = secondAsString.c_str();
            auto temp3 = thirdAsString.c_str();

            long long x = std::stoll(temp1);
            long long y = std::stoll(temp2);
            long long z = std::stoll(temp3);

            point p = {};
            p.x = x;
            p.y = y;
            p.z = z;

            circuit c = {};
            c.points.push_back(p);
            circuits.push_back(c);
        }
    }
    // Setup done
    // Compare each value to each other one and save the details of the two closest.
    // Note that the two values should not be part of the same junction.

    while (true)
    {
        long long circuitIndexA;
        long long circuitIndexB;

        // Start iterating over junctions
        for (long long circuitIndex = 0; circuitIndex < circuits.size(); circuitIndex++)
        {
            auto circuit = circuits[circuitIndex];
            for (long long pointsIndex = 0; pointsIndex < circuit.points.size(); pointsIndex++)
            {
                auto point = circuit.points[pointsIndex];

                // Start iterating over junctions again and skip current circuit index
                for (long long cI = 0; cI < circuits.size(); cI++)
                {
                    if (cI != circuitIndex)
                    {
                        auto c = circuits[cI];
                        for (long long pI = 0; pI < c.points.size(); pI++)
                        {
                            auto point2 = c.points[pI];

                            // TODO add here the calculation call and comparison etc.

                        }
                    }
                }
            }
        }
        // Combine circuitIndexA and circuitIndexB
        // Iterate over circuit b and add them to circuitA
        for (size_t p = 0; p < circuits[circuitIndexB].points.size(); p++)
        {
            auto point = circuits[circuitIndexB].points[p];
            circuits[circuitIndexA].points.push_back(point);
        }
        // Remove circuit B
        circuits.erase(circuits.begin() + circuitIndexB);

        connectionCounter++;

        if (connectionCounter < numOfConnectionsNeeded)
        {
        }
        else
        {
            // job done
            break;
        }
    }

    // Print result

}

int main()
{
    First();
}

