//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-a Upload Link
// Header for the code class used by the Mastermind game.
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
    //
    // Initializes a code object with given length and digit range.
    // length is the number of digits and range is the digit range.
    // Assumes length > 0 and range > 0.
    //
    code(int length, int range);
    
    //
    // Initializes the code with random digits in the range [0, m-1].
    // Assumes m > 0.
    //
    void initializeRandom();
    
    //
    // Initializes the code with specific values from a vector.
    // values is the digit list and must match the code length.
    // Assumes values.size() == n and values are in [0, m-1].
    //
    void initializeWithValues(const vector<int>& values);
    
    //
    // Returns number of digits correct in both value and position.
    // guess is the code object to compare.
    // Assumes guess has the same length as this code.
    //
    int checkCorrect(const code& guess) const;
    
    //
    // Returns number of digits correct in value but wrong position.
    // guess is the code object to compare.
    // Assumes guess has the same length as this code.
    //
    int checkIncorrect(const code& guess) const;
    
    //
    // Prints the code to standard output.
    //
    void print() const;
    
    //
    // Returns the length of the code.
    //
    int getLength() const
    {
        return n;
    }
    
    //
    // Returns the digit range value m.
    //
    int getRange() const
    {
        return m;
    }
};
