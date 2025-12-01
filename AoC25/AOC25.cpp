#include <iostream>
#include <vector>
#include <string>

using namespace std;

// I am aware that turning each dial step using loop might not be the most efficient way to do this,
// but I found it to be easiest to think and implement

void first()
{
    FILE* fptr;
    fptr = fopen("input.txt", "r");
    char line[100];

    int dial = 50;
    int dialDifference = 0;
    int dialAfterDifference = 0;
    int dialMaxValue = 99;
    int count = 0;

    int numsOfRowProcessed = 0;

    if (fptr != NULL) {

        while (fgets(line, 100, fptr)) {
            int direction = 1;
            printf("Input: ");
            printf(line);
            char first_letter = line[0];
            printf("Starts with: ");
            printf("%c", first_letter);
            printf("\n");

            if (first_letter == 'L')
            {
                direction = -1;
            }
            std::vector<char> originalVector(std::begin(line), std::end(line));
            std::vector<char> deepCopy = originalVector;
            deepCopy.erase(deepCopy.begin());
            string s(deepCopy.begin(), deepCopy.end());
            int numOfTurns = std::stoi(s);
            printf("%s", "Value: ");
            printf("%d", numOfTurns);
            printf("\n");

            while (numOfTurns > 0)
            {
                dial = dial + direction;

                if (dial == -1)
                {
                    dial = 99;
                }

                if (dial == 100)
                {
                    dial = 0;
                }

                numOfTurns--;
            }

            if (dial == 0)
            {
                count++;
                printf("Dial is 0! With input: ");
                printf(line);
                printf("\n");

            }

            printf("Dial: ");
            printf("%d", dial);
            printf("\n");
            numsOfRowProcessed++;
        }
    }
    else
    {
        printf("Not able to open the file.");
    }

    printf("The answer: ");
    printf("%d", count);
    printf("\nProcessed rows answer: ");
    printf("%d", numsOfRowProcessed);

    fclose(fptr);
}

void second()
{
    FILE* fptr;
    fptr = fopen("input.txt", "r");
    char line[100];

    int dial = 50;
    int dialDifference = 0;
    int dialAfterDifference = 0;
    int dialMaxValue = 99;
    int count = 0;

    int numsOfRowProcessed = 0;

    if (fptr != NULL) {

        while (fgets(line, 100, fptr)) {
            int direction = 1;
            printf("Input: ");
            printf(line);
            char first_letter = line[0];
            printf("Starts with: ");
            printf("%c", first_letter);
            printf("\n");

            if (first_letter == 'L')
            {
                direction = -1;
            }
            std::vector<char> originalVector(std::begin(line), std::end(line));
            std::vector<char> deepCopy = originalVector;
            deepCopy.erase(deepCopy.begin());
            string s(deepCopy.begin(), deepCopy.end());
            int numOfTurns = std::stoi(s);
            printf("%s", "Value: ");
            printf("%d", numOfTurns);
            printf("\n");

            while (numOfTurns > 0)
            {
                dial = dial + direction;

                if (dial == -1)
                {
                    dial = 99;
                }

                if (dial == 100)
                {
                    dial = 0;
                }

                if (dial == 0)
                {
                    count++;
                    printf("Dial is 0! With input: ");
                    printf(line);
                    printf("\n");
                }

                numOfTurns--;
            }

            printf("Dial: ");
            printf("%d", dial);
            printf("\n");
            numsOfRowProcessed++;
        }
    }
    else
    {
        printf("Not able to open the file.");
    }

    printf("The answer: ");
    printf("%d", count);
    printf("\nProcessed rows answer: ");
    printf("%d", numsOfRowProcessed);

    fclose(fptr);
}

int main()
{
    first();
    second();
}
 