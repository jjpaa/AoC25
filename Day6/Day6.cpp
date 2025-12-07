#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream MyReadFile("input2.txt");
    vector<vector<string>> data = {};

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

            if (inputChar == '*')
            {

            }
            else if (inputChar == '+')
            {

            }
            else if (inputChar == ' ')
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
        // End of row
        data.push_back(row);
    }

    // Calculate the result.
}

//int inputAsInt = inputChar - '0';