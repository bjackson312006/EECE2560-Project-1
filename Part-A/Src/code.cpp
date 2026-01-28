//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-a Upload Link
// Implementation of the code class for Mastermind.
//
#include "code.hpp"

code::code(int length, int range)
//
// Initializes a code object with given length and digit range
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
// Initializes the code with random values in [0, m-1]
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
// Initializes the code with specific values.
// values is the digit list and must match the code length
// Assumes values.size() == n and values are in [0, m-1]
//
{
    
    if (values.size() != static_cast<size_t>(n))
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
} // end code::initializeWithValues

int code::checkCorrect(const code& guess) const
//
// Returns number of digits correct in both value and position
// guess is the code object to compare
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
}

int code::checkIncorrect(const code& guess) const
//
// Returns number of digits correct in value but wrong position
// guess is the code object to compare
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
        } // end if
    } // end for
    
    return incorrectCount;
} // end code::checkIncorrect

void code::print() const
//
// Prints the secret code in a user-friendly format
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
