#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

struct point
{
    public:
        int x, y, z = 0;
};

struct circuit
{
    public:
        vector<point> points = {};
};

void First()
{
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
    cout << "";
}

int main()
{
    First();
}

