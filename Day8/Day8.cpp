#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include <windows.h>
#include <cmath>
//#include <algorithm>

using namespace std;

struct point
{
        int x, y, z = 0;
};

struct circuit
{
        vector<point> points = {};
};

double CalculateDistance(point one, point two)
{
    // Formula
    //    ________________________________________
    // --v (x1 - x2)^2 + (y1 - y2)^2 + (z1-z2)^2)

    auto temp = pow((one.x - two.x), 2);
    auto temp2 = pow((one.y - two.y), 2);
    auto temp3 = pow((one.z - two.z), 2);

    return sqrt(temp + temp2 + temp3);
}

void First()
{
    const int numOfConnectionsNeeded = 1000;
    int connectionCounter = 0;

    ifstream MyReadFile("input2.txt");

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

            int x = std::stoi(temp1);
            int y = std::stoi(temp2);
            int z = std::stoi(temp3);

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

    std::cout << "Setup done\n";

    while (true)
    {
        int circuitIndexA;
        int circuitIndexB;

        double smallestDistance = 999999999999;

        auto circuitsSize = circuits.size();

        // Start iterating over junctions
        for (int circuitIndex = 0; circuitIndex < circuitsSize; circuitIndex++)
        {
            auto circuit = circuits[circuitIndex];
            for (int pointsIndex = 0; pointsIndex < circuit.points.size(); pointsIndex++)
            {
                auto point = circuit.points[pointsIndex];

                // Start iterating over junctions again and skip current circuit index
                for (int cI = 0; cI < circuitsSize; cI++)
                {
                    if (cI != circuitIndex)
                    {
                        auto c = circuits[cI];
                        for (int pI = 0; pI < c.points.size(); pI++)
                        {
                            auto point2 = c.points[pI];
                            auto distance = CalculateDistance(point, point2);

                            if (distance < smallestDistance)
                            {
                                smallestDistance = distance;
                                circuitIndexA = circuitIndex;
                                circuitIndexB = cI;
                            }
                        }
                    }
                }
            }
        }

        //std::cout << "Combining started\n";

        // Combine circuitIndexA and circuitIndexB
        // Iterate over circuit b and add them to circuitA
        for (int p = 0; p < circuits[circuitIndexB].points.size(); p++)
        {
            auto point = circuits[circuitIndexB].points[p];
            circuits[circuitIndexA].points.push_back(point);
        }

        // Remove circuit B
        circuits.erase(circuits.begin() + circuitIndexB);

        connectionCounter++;

        std::cout << "Connection counter: " << connectionCounter << "\n";

        if (connectionCounter < numOfConnectionsNeeded -1)
        {

        }
        else
        {
            // job done
            break;
        }
    }

    // Print result
    // Multiply the size of 3 largest circuits

    // Find out which are largest

    size_t largest = 0;
    size_t secondLargest = 0;
    size_t thirdLargest = 0;

    for (int i = 0; i < circuits.size(); i++)
    {
        auto size = circuits[i].points.size();

        if (size > largest)
        {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = size;
        }
        else if (size > secondLargest)
        {
            thirdLargest = secondLargest;
            secondLargest = size;
        }
        else if (size > thirdLargest)
        {
            thirdLargest = size;
        }
    }

    std::cout << largest << "\n";
    std::cout << secondLargest << "\n";
    std::cout << thirdLargest << "\n";

    long long result = largest * secondLargest * thirdLargest;
    std::cout << result;

    string pause;
    cin >> pause;
}

int main()
{
    First();
}

