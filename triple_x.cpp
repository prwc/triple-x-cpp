#include <iostream>
#include <time.h>

using namespace std;

int RandomInput(int level)
{
    return (rand() % (level + 1)) + 1;
}

int CalculateSum(int *Inputs)
{
    return Inputs[0] + Inputs[1] + Inputs[2];
}

int CalculateProduct(int *Inputs)
{
    return Inputs[0] * Inputs[1] * Inputs[2];
}

bool PlayLevel(int Level)
{
    const int MaxTryCount = 3;

    int RandomInputs[3] = {RandomInput(Level), RandomInput(Level), RandomInput(Level)};
    const int TargetSum = CalculateSum(RandomInputs);
    const int TargetProduct = CalculateProduct(RandomInputs);

    int Inputs[3] = {0, 0, 0};

    int PlayCount = 0;
    cout << "Access Level " << Level << endl;
    cout << "There are 3 numbers in the code" << endl;
    cout << "The codes add-up to: " << TargetSum << endl;
    cout << "The codes multiply to give: " << TargetProduct << endl;
    cout << "Enter the correct codes to continue" << endl;
    while (PlayCount < MaxTryCount)
    {
        cin >> Inputs[0] >> Inputs[1] >> Inputs[2];
        cin.clear();
        cin.ignore();
        int Sum = CalculateSum(Inputs);
        int Product = CalculateProduct(Inputs);
        if (TargetSum == Sum && TargetProduct == Product)
        {
            cout << "Clear Level " << Level << endl;
            return true;
        }
        PlayCount++;
        cout << "Try again.." << endl;
    }

    return false;
}

int main(int Argc, char **Argv)
{
    const int MaxLevel = 10;
    const int StartLevel = 1;
    int Level = StartLevel;

    srand(time(NULL));

    cout << "You are a secret agent breaking into a secure server room..." << endl;
    while (Level <= MaxLevel)
    {
        if (PlayLevel(Level))
        {
            Level++;
        }
        else
        {
            cout << "Game over!";
            return 0;
        }
    }
    cout << "Good jobs.";
    return 0;
}