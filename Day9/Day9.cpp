#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void first()
{
    ifstream MyReadFile("input.txt");
    tuple <long long, long long> point;
    vector<tuple<long long, long long>> points = {};
    long long highestArea = 0;

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
            //cout << "First: " << firstAsString << " , Second: " << secondAsString << "\n";

            auto temp1 = firstAsString.c_str();
            auto temp2 = secondAsString.c_str();

            long long firstAsLongLong = std::stoll(temp1);
            long long secondAsLongLong = std::stoll(temp2);

            point = make_tuple(firstAsLongLong, secondAsLongLong);
            points.push_back(point);
        }

    }
    
    // Then compare every point to each other and save the highest area

    // First point
    for (long long firstPointIterator = 0; firstPointIterator < points.size(); firstPointIterator++)
    {
        auto firstPoint = points[firstPointIterator];
        auto x = get<0>(firstPoint);
        auto y = get<1>(firstPoint);

        // Second point
        for (long long secondPointIterator = 0; secondPointIterator < points.size(); secondPointIterator++)
        {
            auto secondPoint = points[secondPointIterator];
            auto x2 = get<0>(secondPoint);
            auto y2 = get<1>(secondPoint);

            // bigger value minus the other for x and y and then multiply
            auto biggerX = x;
            auto smallerX = x2;
            if (x2 > x)
            {
                biggerX = x2;
                smallerX = x;
            }
            auto biggerY = y;
            auto smallerY = y2;
            if (y2 > y)
            {
                biggerY = y2;
                smallerY = y;
            }

            auto differenceInX = biggerX - smallerX;
            auto differenceInY = biggerY - smallerY;

            differenceInX++;
            differenceInY++;

            auto area = differenceInX * differenceInY;
            if (area > highestArea)
            {
                highestArea = area;
            }
        }
    }

    cout << highestArea << "\n";
}

int main()
{
    first();
}