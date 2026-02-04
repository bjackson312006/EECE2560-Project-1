//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-b Upload Link
// Header for the code class used by the Mastermind game
//
#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//
// Mastermind code - Codebreaker is prompted two integers n and m, where n is
// the length of the code and m is the range of digits [0, m-1]. Codemaker then
// creates a secret code of length n with digits in the range [0, m-1].
// Codebreaker makes guesses and receives feedback on how many digits are
// correct and in the correct position, and how many digits are correct but in
// the wrong position.
//

class code
{
private:
    vector<int> digits;  // The code digits
    int n;               // Length of the code
    int m;               // Range of digits [0, m-1]

public:
    code(int length, int range);
    //
    // Constructor - initializes a code object with given length and digit range
    // length is the number of digits in the code (n)
    // range is the range of possible digits [0, m-1]
    // Assumes length > 0 and range > 0
    //
    
    void initializeRandom();
    //
    // Initializes the code with random digits in the range [0, m-1]
    // Uses rand() to generate random values
    //
    
    void initializeWithValues(const vector<int>& values);
    //
    // Initializes the code with specific values from a vector
    // values is the vector of integers to set as the code
    // Assumes values.size() == n and all values in range [0, m-1]
    //
    
    int checkCorrect(const code& guess) const;
    //
    // Checks how many digits in the guess are correct and in correct location
    // guess is the guess code object to compare against this code
    // Returns number of digits that match in both value and position
    // Assumes guess has the same length as this code
    //
    
    int checkIncorrect(const code& guess) const;
    //
    // Checks how many digits in the guess are correct but in wrong location
    // guess is the guess code object to compare against this code
    // Returns number of digits that match in value but not in position
    // Assumes guess has the same length as this code
    // Note: Digits already counted as correct position are not counted here
    //
    
    void print() const;
    //
    // Prints the code to console
    //
    
    int getLength() const
    //
    // Gets the length of the code
    //
    {
        return n;
    }
    
    int getRange() const
    //
    // Gets the range of the code
    //
    {
        return m;
    }
};