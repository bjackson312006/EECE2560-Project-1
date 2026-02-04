//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-b Upload Link
// Main program for Part B interactive game
//
#include <iostream>
#include <string>
#include <limits>
#include "code.hpp"
#include "response.hpp"
#include "mastermind.hpp"

using namespace std;

int readInt(const string& prompt)
//
// Reads one validated integer from standard input
// prompt is the message shown to the user
// Returns the validated integer
// Assumes input is provided by the user
//
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

        // Clear input so the next attempt is fresh
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
} // end readInt

void readCodeSettings(int& n, int& m)
//
// Reads, validates, and sets code length n and digit range m
// n is length and m is digit range
// Assumes user enters positive integers
//
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
} // end readCodeSettings

int main(void)
//
// Program entry point
// Prompts for settings, starts the game, then exits
//
{
    int n;
    int m;

    readCodeSettings(n, m);
    mastermind mm(n, m);
    mm.playGame();
    return 0;
}
