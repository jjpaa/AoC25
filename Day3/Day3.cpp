#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void first()
{
    signed long long resultCounter = 0;
    ifstream MyReadFile("input.txt");
    while (true)
    {
        string input;
        getline(MyReadFile, input);

        if (input == "")
        {
            break;
        }

        int first = 0;
        int second = 0;

        // Do for each input value. Except last
        for (int i = 0; i < input.length() - 1; i++)
        {
            char inputChar = input[i];
            int inputAsInt = inputChar - '0';
            if (inputAsInt > first)
            {
                second = 0;
                first = inputAsInt;
            }
            else if (inputAsInt > second)
            {
                second = inputAsInt;
            }
        }

        char lastInputChar = input[input.length() - 1];
        int lastInput = lastInputChar - '0';

        if (lastInput > second)
        {
            second = lastInput;
        }

        string firstAsString = "";
        string secondAsString = "";

        firstAsString = std::to_string(first);
        secondAsString = std::to_string(second);

        //cout << "First: " << first << " " << second << "\n";

        string together = firstAsString + secondAsString;
        int increment = std::stoi(together);
        resultCounter = resultCounter + increment;
    }
    cout << "Result 1: " << resultCounter << "\n";
}

void second()
{
    signed long long resultCounter = 0;
    ifstream MyReadFile("input.txt");
    while (true)
    {
        string input;
        getline(MyReadFile, input);

        if (input == "")
        {
            break;
        }

        vector<int> v = {};

        //cout << "vector before  : ";

        for (int i = 0; i <= 11; i++)
        {
            v.push_back(0);
            //cout << v[i];
        }

        // Do for each input value. Except last
        for (int inputIterator = 0; inputIterator < input.length(); inputIterator++)
        {
            char inputChar = input[inputIterator];
            int inputAsInt = inputChar - '0';
            // How many are left?
            int thisManyLeft = input.length() - inputIterator;
            bool putToZero = false;

            int iterationSpotStartPoint = 12 - thisManyLeft;

            if (iterationSpotStartPoint < 0)
            {
                iterationSpotStartPoint = 0;
            }

            //cout << "iterationSpotStartPoint: " << iterationSpotStartPoint << "\n";

            //if (inputAsInt == 9)
            //{
            //    cout << "";
            //}

            //For each spot (12) on the vector
            for (int spotIterator = iterationSpotStartPoint; spotIterator <= 11; spotIterator++)
            {
                if (spotIterator == 11)
                {
                    cout << "";
                }

                if (putToZero)
                {
                    v[spotIterator] = 0;
                    //cout << "Inserting " << 0 << " To Spot " << spotIterator << "\n";
                }
                else
                {
                    // if currentspot is still possible
                    if (thisManyLeft >= 12 - spotIterator)
                    {
                        // Swap the most top one and put other after to zero
                        // if there is still enough number to come.
                        int currentValueOnSpot = v[spotIterator];

                        //if (inputAsInt == 1 && currentValueOnSpot == 1)
                        //{
                        //    cout << "";
                        //}


                        if (inputAsInt > currentValueOnSpot)
                        {

                            //cout << "Inserting " << inputAsInt << " To Spot " << spotIterator << "\n";

                            // Value is bigger than current and there is more to come
                            v[spotIterator] = inputAsInt;
                            // Put rest to zero
                            putToZero = true;

                            //cout << "Input " << inputAsInt << " was bigger than existing " << currentValueOnSpot << "\n";
                        }
                        else
                        {
                            //cout << "Input " << inputAsInt << " was smaller than existing " << currentValueOnSpot << "\n";
                        }
                    }
                    else
                    {
                        //cout << "Won't do. This many left" << thisManyLeft << " spotiterator " << spotIterator << "\n";
                    }
                }
            }
            //cout << "processed input " << inputIterator << "\n";
        }

        //cout << "Vector : ";

        //for (int i = 0; i <= 11; i++)
        //{
        //    cout << v[i];
        //}
        //cout << "\n";

        string numsTogether = "";

        for (int i = 0; i <= 11; i++)
        {
            numsTogether += std::to_string(v[i]);
        }

        signed long long increment = std::stoll(numsTogether);
        resultCounter = resultCounter + increment;
    }
    cout << "\nResult 2: " << resultCounter;
}

int main()
{
    first();
    second();
}