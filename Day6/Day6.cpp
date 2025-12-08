#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream MyReadFile("input.txt");
    vector<vector<string>> data = {};
    long long counter = 0;

    while (true)
    {
        string input;
        getline(MyReadFile, input);

        if (input == "")
        {
            break;
        }

        vector<string> row = {};
        string newValueToAdd = "";

        // Do for each input value.
        for (int i = 0; i < input.length(); i++)
        {
            char inputChar = input[i];

            if (inputChar == ' ')
            {
                if (newValueToAdd != "")
                {
                    row.push_back(newValueToAdd);
                }
                newValueToAdd = "";
            }
            else // part of the number
            {
                newValueToAdd += inputChar;
            }

        }
        if (newValueToAdd != "")
        {
            row.push_back(newValueToAdd);
        }
        newValueToAdd = "";

        // End of row
        data.push_back(row);
    }
    long long rowsAmount = data.size() - 1;
    long long columnAmount = data[0].size() - 1;

    // Print the thing
    //for (long long r = 0; r < rowsAmount;r++)
    //{
    //    for (long long c = 0; c <= columnAmount; c++)
    //    {
    //        cout << data[r][c] << " ";
    //    }
    //    cout << "\n";
    //}

    // Calculate the result.
    // Loop thorough values
    // Loop through the rows
    // vector<vector<string>> data = {};

    //for (long long row_i = 0; row_i < rowsAmount; row_i++)
    //{
    //    long long tempCounter = 1;

    //    for (long long column_i = 0; column_i <= columnAmount; column_i++)
    //    {
    //        bool plus = false;
    //        // Then take the operator type
    //        auto operatorAsString = data[rowsAmount][column_i];

    //        if (operatorAsString == "+")
    //        {
    //            plus = true;
    //            tempCounter = 0;
    //        }

    //        long long valueAsInt = std::stoll(data[row_i][column_i]);

    //        cout << "Order of printing: " << valueAsInt << "\n";

    //        if (plus)
    //        {
    //            tempCounter = tempCounter + valueAsInt;
    //        }
    //        else
    //        {
    //            tempCounter = tempCounter * valueAsInt;
    //        }
    //    }
    //    counter += tempCounter;
    //}

    for (long long column_i = 0; column_i <= columnAmount; column_i++)
    {
        long long tempCounter = 0;

        for (long long row_i = 0; row_i < rowsAmount; row_i++)
        {
            bool plus = false;
            // Then take the operator type
            auto operatorAsString = data[rowsAmount][column_i];

            if (operatorAsString == "+")
            {
                plus = true;
            }

            long long valueAsInt = std::stoll(data[row_i][column_i]);

            //cout << "Order of printing: " << valueAsInt << "\n";

            if (plus)
            {
                tempCounter = tempCounter + valueAsInt;
            }
            else
            {
                if (tempCounter == 0)
                {
                    tempCounter = 1;
                }

                tempCounter = tempCounter * valueAsInt;
            }
        }
        //cout << tempCounter << "\n";
        counter += tempCounter;
    }

    cout << counter;
}