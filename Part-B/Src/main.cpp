#include <iostream>
#include <string>
#include <limits>
#include "code.hpp"
#include "response.hpp"
#include "mastermind.hpp"

using namespace std;

//
// Reads one validated integer from standard input
// prompt is the message shown to the user
// Returns the validated integer
//
int readInt(const string& prompt)
{
    while (1)
    {
        cout << prompt;
        int value;

        if (cin >> value)
        {
            return value;
        }

        cout << "Invalid input. Must be a single integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input so the next attempt is fresh
    }
}

//
// Reads, validates, and sets code length n and digit range m
// n is length and m is digit range
// Assumes user enters positive integers
//
void readCodeSettings(int& n, int& m)
{
    while (1)
    {
        n = readInt("Enter code length n: ");
        m = readInt("Enter digit range m: ");

        if (n <= 0 || m <= 0)
        {
            cout << "n and m must be positive integers." << endl;
            continue;
        }

        break;
    }
}

int main(void)
{
    int n;
    int m;

    readCodeSettings(n, m);
    mastermind mm(n, m);
    mm.playGame();
    return 0;
}
