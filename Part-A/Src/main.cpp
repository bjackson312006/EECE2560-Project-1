//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-a Upload Link
// Main program for Part A sample checks.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "code.hpp"

using namespace std;

code createAndPrintSecretCode(int length, int digRange)
//
// Creates and prints a random secret code.
// length is number of digits and digRange is range [0, m-1].
// Assumes length > 0 and digRange > 0.
//
{
    
    if (length <= 0 || digRange <= 0)
    {
        cerr << "Error: length and digRange must be positive integers"
             << endl;
        return code(1, 1);
    }

    code secret(length, digRange);
    secret.initializeRandom();
    cout << "Secret=";
    secret.print();
    cout << endl << endl;
    return secret;
} // end createAndPrintSecretCode

code createSampleGuess(int length, int digRange, const vector<int>& values)
//
// Creates a guess code from the provided values.
// length is number of digits and digRange is range [0, m-1].
// Assumes values.size() == length and values are within range.
//
{
    
    if (length <= 0 || digRange <= 0)
    {
        cerr << "Error: length and digRange must be positive integers"
             << endl;
        return code(1, 1);
    }

    if (static_cast<int>(values.size()) != length)
    {
        cerr << "Error: values size does not match length" << endl;
        return code(length, digRange);
    }

    code guess(length, digRange);
    guess.initializeWithValues(values);
    return guess;
} // end createSampleGuess

vector<code> createThreeSampleGuesses(int length, int digRange)
//
// Creates the three required sample guesses.
// length is number of digits and digRange is range [0, m-1].
// Assumes length > 0 and digRange > 0.
//
{
    
    if (length <= 0 || digRange <= 0)
    {
        cerr << "Error: length and digRange must be positive integers"
             << endl;
        return vector<code>();
    }

    vector<code> guesses;
    guesses.push_back(createSampleGuess(length, digRange,
        vector<int>{5, 0, 3, 2, 6}));
    guesses.push_back(createSampleGuess(length, digRange,
        vector<int>{2, 1, 2, 2, 2}));
    guesses.push_back(createSampleGuess(length, digRange,
        vector<int>{1, 3, 3, 4, 5}));
    return guesses;
} // end createThreeSampleGuesses

void printSampleGuessResults(const code& secret,
                             const vector<code>& guesses)
//
// Prints the checkCorrect/checkIncorrect results for the sample guesses.
// secret is the code to compare against and guesses are the sample codes.
// Assumes secret and guesses have matching lengths and ranges.
//
{
    
    if (guesses.empty())
    {
        cerr << "Error: guesses list is empty" << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(guesses.size()); i++)
    {
        
        if (guesses[i].getLength() != secret.getLength() ||
            guesses[i].getRange() != secret.getRange())
        {
            cerr << "Error: guess length or range does not match secret"
                 << endl;
            continue;
        }

        cout << "Guess " << i + 1 << ": ";
        guesses[i].print();
        cout << endl;
        cout << "Results: ";
        cout << "checkCorrect=" << secret.checkCorrect(guesses[i]) << " ";
        cout << "checkIncorrect=" << secret.checkIncorrect(guesses[i])
             << endl << endl;
    }
} // end printSampleGuessResults

int main()
//
// Runs the Part A sample checks against a random secret code.
// Assumes length > 0 and digRange > 0.
//
{
    const int length = 5;
    const int digRange = 10;

    if (length <= 0 || digRange <= 0)
    {
        cerr << "Error: length and digRange must be positive integers"
             << endl;
        return 1;
    }

    srand(time(0));
    code secret = createAndPrintSecretCode(length, digRange);

    vector<code> guesses = createThreeSampleGuesses(length, digRange);
    printSampleGuessResults(secret, guesses);

    return 0;
} // end main
