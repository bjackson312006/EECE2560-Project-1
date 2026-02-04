//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-b Upload Link
// Implementation of the code class for Mastermind
//
#include "code.hpp"

code::code(int length, int range)
//
// Constructor implementation
// length is the number of digits and range is the digit range
// Assumes length > 0 and range > 0
//
{
    
    if (length <= 0 || range <= 0)
    {
        cerr << "Error: length and range must be positive integers" << endl;
        n = 1;
        m = 1;
    }
    else
    {
        n = length;
        m = range;
    }
    digits.resize(n, 0);
}

void code::initializeRandom()
//
// Initialize code with random values
// Assumes m > 0
//
{
    
    for (int i = 0; i < n; i++)
    {
        digits[i] = rand() % m;
    }
}

void code::initializeWithValues(const vector<int>& values)
//
// Initialize code with specific values
// values is the digit list and must match the code length
// Assumes values.size() == n and values are in [0, m-1]
//
{
    
    if (values.size() != n)
    {
        cerr << "Error: values size does not match code length" << endl;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        
        if (values[i] < 0 || values[i] >= m)
        {
            cerr << "Error: value " << values[i]
                 << " is out of range [0, " << m - 1 << "]" << endl;
            return;
        }
    }
    
    digits = values;
} // end initializeWithValues

int code::checkCorrect(const code& guess) const
//
// Check correct digits in correct positions
// guess is the code object to compare against this code
// Returns number of digits that match in both value and position
// Assumes guess has the same length as this code
//
{
    
    if (guess.n != n)
    {
        cerr << "Error: guess length does not match code length" << endl;
        return 0;
    }
    
    int correctCount = 0;
    
    for (int i = 0; i < n; i++)
    {
        
        if (digits[i] == guess.digits[i])
        {
            correctCount++;
        }
    }
    return correctCount;
} // end checkCorrect

int code::checkIncorrect(const code& guess) const
//
// Check correct digits in incorrect positions
// guess is the code object to compare against this code
// Returns number of digits that match in value but not in position
// Assumes guess has the same length as this code
//
{
    
    if (guess.n != n)
    {
        cerr << "Error: guess length does not match code length" << endl;
        return 0;
    }
    
    vector<bool> secretUsed(n, false);
    vector<bool> guessUsed(n, false);
    
    for (int i = 0; i < n; i++)
    {
        
        if (digits[i] == guess.digits[i])
        {
            secretUsed[i] = true;
            guessUsed[i] = true;
        }
    }
    
    int incorrectCount = 0;
    
    for (int i = 0; i < n; i++)
    {
        
        if (!guessUsed[i])
        {
            
            for (int j = 0; j < n; j++)
            {
                
                if (!secretUsed[j] && digits[j] == guess.digits[i])
                {
                    incorrectCount++;
                    secretUsed[j] = true;
                    break; 
                }
            }
        }
    }
    
    return incorrectCount;
} // end checkIncorrect

void code::print() const
//
// Print the code
//
{
    cout << "(";
    
    for (int i = 0; i < n; i++)
    {
        cout << digits[i];
        
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << ")";
}
