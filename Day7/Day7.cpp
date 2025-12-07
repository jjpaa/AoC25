#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream MyReadFile("input.txt");  
    long long splitCounter = 0;
    string lastLine = "";

    while (true)
    {
        string input;
        getline(MyReadFile, input);

        if (input == "")
        {
            break;
        }

        if (lastLine != "")
        {
            string replacementLine = input;

            // Do for each input value
            for (int i = 0; i < input.length(); i++)
            {
                char inputChar = input[i];

                char above = lastLine[i];

                if (above == 'S' || above == '|')
                {
                    if (inputChar == '^')
                    {
                        splitCounter++;
                        replacementLine[i - 1] = '|';
                        replacementLine[i + 1] = '|';
                    }
                    else
                    {
                        replacementLine[i] = '|';
                    }
                }

            }
            lastLine = replacementLine;
        }
        else
        {
            lastLine = input;
        }

        cout << lastLine << "\n";
    }

    cout << splitCounter << "\n";
}