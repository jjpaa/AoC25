#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    bool seekRanges = true;
    ifstream MyReadFile("input.txt");
    tuple <long long, long long> rangeTuple;
    vector<tuple<long long, long long>> ranges = {};

    long long counter = 0;

    while (true)
    {
        string input;
        getline(MyReadFile, input);

        // Empty line handle
        if (input == "")
        {
            if (seekRanges)
            {
                seekRanges = false;
                cout << "Switch modes\n";
            }
            else
            {
                cout << "Exit loop\n";
                break;
            }
        }
        else
        {
            if (seekRanges)
            {
                //cout << "Range processing\n";
                string delimiter = "-";
                string firstAsString = input.substr(0, input.find(delimiter));
                string secondAsString = input;
                secondAsString.erase(0, secondAsString.find(delimiter) + delimiter.length());
                cout << "First: " << firstAsString << " , Second: " << secondAsString << "\n";

                auto temp1 = firstAsString.c_str();
                auto temp2 = secondAsString.c_str();

                long long firstAsLongLong = std::stoll(temp1);
                long long secondAsLongLong = std::stoll(temp2);

                rangeTuple = make_tuple(firstAsLongLong, secondAsLongLong);
                ranges.push_back(rangeTuple);
            }
            else
            {
                // input --> is string and is a large number 
                auto constCharPtr = input.c_str();
                long long inputAsLongLong = std::stoll(constCharPtr);

                bool fitsRange = false;
                // Go through each range and if value fits any --> exit and increment counter

                for (long long t = 0; t < ranges.size(); t++)
                {
                    // Check input falls in between the tuple
                    auto myTuple = ranges[t];
                    auto first = get<0>(myTuple);
                    auto second = get<1>(myTuple);

                    if (inputAsLongLong >= first && inputAsLongLong <= second)
                    {
                        fitsRange = true;
                        cout << "Fits range " << input << "\n";
                        break;
                    }
                }

                // Match found
                if (fitsRange)
                {
                    counter++;
                }
            }
        }
    }

    cout << counter;
}
