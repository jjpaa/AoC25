#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    int charIterator = 0;
    int rangesIterator = 0;

    int resultCounter = 0;

    ifstream MyReadFile("input2.txt");
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
    for (size_t i = 0; i < rangesList.size(); i++)
    {
        string startValueAsString = "";
        string endValueAsString = "";
        int startValue = 0;
        int endValue = 0;
        bool firstValue = true;

        // each char in range
        for (size_t j = 0; j < rangesList[i].size(); j++)
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

        int start = atoi(startValueAsString.c_str());
        int end = atoi(endValueAsString.c_str());
        
        // I did not notice earlier but the second number might be bigger. Lets sort them.


        // Seek replicating numbers between values
        // Iterate all values between those values
        for (int valueGettingChecked = start; valueGettingChecked <= end; valueGettingChecked++)
        {
            string valueAsString = to_string(valueGettingChecked);
            
            string firstHalf = "";

            // Iterate halfway of the string
            for (size_t i = 0; i < valueAsString.size() / 2; i++)
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
    cout << "End";

    return 0;
}