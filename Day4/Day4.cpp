#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void second()
{
    int AccessibleRolls = 0;

    vector<vector<char>> area = {};

    ifstream MyReadFile("input.txt");

    // Read Input and put to vector
    while (true)
    {
        string input;
        getline(MyReadFile, input);

        if (input == "")
        {
            break;
        }

        vector<char> row = {};

        for (int inputIterator = 0; inputIterator < input.length(); inputIterator++)
        {
            char inputChar = input[inputIterator];
            row.push_back(inputChar);
        }
        area.push_back(row);
    }

    int temp = -1;

    while (true)
    {
        if (AccessibleRolls != temp)
        {
            temp = AccessibleRolls;
        }
        else
        {
            break;
        }

        // Iteratate through all the values and call check function
        for (int row = 0; row < area.size(); row++)
        {
            auto columnsSize = area[row].size();
            for (int column = 0; column < columnsSize; column++)
            {
                //cout << area[row][column];

                // Is there value above to this?
                bool above = false;
                if (row > 0)
                {
                    above = true;
                }
                // Is there value bellow to this?
                bool bellow = false;
                if (row < area.size() - 1)
                {
                    bellow = true;
                }
                // Is there value left to this?
                bool left = false;
                if (column > 0)
                {
                    left = true;
                }
                // Is there value right to this?
                bool right = false;
                if (column < area.size() - 1)
                {
                    right = true;
                }

                int rollsNearby = 0;

                // Check top left corner
                if (above && left)
                {
                    if (area[row - 1][column - 1] == '@')
                    {
                        rollsNearby++;
                    }
                }

                // Check top right corner
                if (above && right)
                {
                    if (area[row - 1][column + 1] == '@')
                    {
                        rollsNearby++;
                    }
                }

                // Check bottom right corner
                if (bellow && right)
                {
                    if (area[row + 1][column + 1] == '@')
                    {
                        rollsNearby++;
                    }
                }

                // Check bottom left corner
                if (bellow && left)
                {
                    if (area[row + 1][column - 1] == '@')
                    {
                        rollsNearby++;
                    }
                }

                // Check above
                if (above)
                {
                    if (area[row - 1][column] == '@')
                    {
                        rollsNearby++;
                    }
                }

                // Check left
                if (left)
                {
                    if (area[row][column - 1] == '@')
                    {
                        rollsNearby++;
                    }
                }

                // Check rigth
                if (right)
                {
                    if (area[row][column + 1] == '@')
                    {
                        rollsNearby++;
                    }
                }

                // Check bellow
                if (bellow)
                {
                    if (area[row + 1][column] == '@')
                    {
                        rollsNearby++;
                    }
                }

                //  ..@@.@@@@.
                //  @@@.@.@.@@
                //  @@@@@.@.@@

                if (rollsNearby < 4 && area[row][column] == '@')
                {
                    AccessibleRolls++;
                    area[row][column] = '.';
                }
            }
            // Separate rows
            cout << "\n";
        }
    }

    cout << AccessibleRolls << "\n";
}

void first()
{
    int AccessibleRolls = 0;

    vector<vector<char>> area = {};

    ifstream MyReadFile("input.txt");

    // Read Input and put to vector
    while (true)
    {
        string input;
        getline(MyReadFile, input);

        if (input == "")
        {
            break;
        }

        vector<char> row = {};

        for (int inputIterator = 0; inputIterator < input.length(); inputIterator++)
        {
            char inputChar = input[inputIterator];
            row.push_back(inputChar);
        }
        area.push_back(row);
    }

    // Iteratate through all the values and call check function
    for (int row = 0; row < area.size(); row++)
    {
        auto columnsSize = area[row].size();
        for (int column = 0; column < columnsSize; column++)
        {
            cout << area[row][column];

            // Is there value above to this?
            bool above = false;
            if (row > 0)
            {
                above = true;
            }
            // Is there value bellow to this?
            bool bellow = false;
            if (row < area.size()-1)
            {
                bellow = true;
            }
            // Is there value left to this?
            bool left = false;
            if (column > 0)
            {
                left = true;
            }
            // Is there value right to this?
            bool right = false;
            if (column < area.size()-1)
            {
                right = true;
            }

            int rollsNearby = 0;

            // Check top left corner
            if (above && left)
            {
                if (area[row - 1][column - 1] == '@')
                {
                    rollsNearby++;
                }
            }

            // Check top right corner
            if (above && right)
            {
                if (area[row - 1][column + 1] == '@')
                {
                    rollsNearby++;
                }
            }

            // Check bottom right corner
            if (bellow && right)
            {
                if (area[row + 1][column + 1] == '@')
                {
                    rollsNearby++;
                }
            }

            // Check bottom left corner
            if (bellow && left)
            {
                if (area[row + 1][column - 1] == '@')
                {
                    rollsNearby++;
                }
            }

            // Check above
            if (above)
            {
                if (area[row - 1][column] == '@')
                {
                    rollsNearby++;
                }
            }

            // Check left
            if (left)
            {
                if (area[row][column-1] == '@')
                {
                    rollsNearby++;
                }
            }

            // Check rigth
            if (right)
            {
                if (area[row][column + 1] == '@')
                {
                    rollsNearby++;
                }
            }

            // Check bellow
            if (bellow)
            {
                if (area[row+1][column] == '@')
                {
                    rollsNearby++;
                }
            }

            //  ..@@.@@@@.
            //  @@@.@.@.@@
            //  @@@@@.@.@@

            if (rollsNearby < 4 && area[row][column] == '@')
            {
                AccessibleRolls++;
            }
        }
        // Separate rows
        cout << "\n";
    }
    cout << AccessibleRolls <<"\n";
}

int main()
{
    first();
    second();
}