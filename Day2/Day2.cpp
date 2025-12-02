#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    string input;
    int charIterator = 0;
    int rangesIterator = 0;

    long long resultCounter = 0;

    ifstream MyReadFile("input.txt");
    getline(MyReadFile, input);

    vector<string> rangesList = {};

    rangesList.push_back("");

    while (input[charIterator] != '\0')
    {
        auto inputAsChar = input[charIterator];
        string inputAsString = string{ inputAsChar };

        if (inputAsString == ",")
        {
            rangesIterator++;
            rangesList.push_back("");
        }
        else
        {
            rangesList[rangesIterator] += inputAsString;
        }
        charIterator++;
    }
    cout << "Before first loop \n";

    // each range
    for (int i = 0; i < rangesList.size(); i++)
    {
        cout << "Processing range " << i << "\n";
        string startValueAsString = "";
        string endValueAsString = "";
        bool firstValue = true;

        auto s = rangesList[i];
        auto length = s.size();
        for (int j = 0; j < length; j++)
        {
            auto myChar = rangesList[i][j];
            string inputAsString = string{myChar};

            if (inputAsString == "-")
            {
                firstValue = false;
            }
            else if (firstValue)
            {
                startValueAsString += inputAsString;
            }
            else
            {
                endValueAsString += inputAsString;
            }
        }

        // I thought the second number might be smaller.
        //int smaller = 0;
        //int bigger = 0;
        //
        //int first = atoi(startValueAsString.c_str());
        //int second = atoi(endValueAsString.c_str());
        //
        //if (first <= second)
        //{
        //    smaller = first;
        //    bigger = second;
        //}
        //else
        //{
        //    smaller = second;
        //    bigger = first;
        //}

        // Seek replicating numbers between values
        // Iterate all values between those values

        auto temp1 = startValueAsString.c_str();
        auto temp2 = endValueAsString.c_str();

        long long smaller = std::stoll(temp1);
        long long bigger = std::stoll(temp2);

        for (long long valueGettingChecked = smaller; valueGettingChecked <= bigger; valueGettingChecked++)
        {
            string valueAsString = to_string(valueGettingChecked);
            string firstHalf = "";

            // Iterate halfway of the string
            for (long long i = 0; i < valueAsString.size() / 2; i++)
            {
                firstHalf += valueAsString[i];
            }

            if (firstHalf + firstHalf == valueAsString)
            {
                cout << "Found one! --> " << valueGettingChecked << "\n";
                resultCounter += valueGettingChecked;
            }
        }

        cout << "After outer loop\n";
    }
    cout << "Result: " << resultCounter;

    return 0;
}