#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Mastermind code - Codebreaker is prompted two integers n and m, where n is the length of the code 
 * and m is the range of digits [0, m-1]. Codemaker then creates a secret code of length n with digits in the range [0, m-1].
 * Codebreaker makes guesses and receives feedback on how many digits are correct and in the correct position,
 * and how many digits are correct but in the wrong position.
 */

class code {
private:
    vector<int> digits;  // The code digits
    int n;               // Length of the code
    int m;               // Range of digits [0, m-1]

public:
    /**
     * Constructor - initializes a code object with given length and digit range
     * @param length - the number of digits in the code (n)
     * @param range - the range of possible digits [0, m-1]
     * Assumptions: length > 0, range > 0
     */
    code(int length, int range);
    
    /**
     * Initializes the code with random digits in the range [0, m-1]
     * Uses rand() to generate random values
     */
    void initializeRandom();
    
    /**
     * Initializes the code with specific values from a vector
     * @param values - vector of integers to set as the code
     * Assumptions: values.size() == n, all values in range [0, m-1]
     */
    void initializeWithValues(const vector<int>& values);
    
    /**
     * Checks how many digits in the guess are correct and in correct location
     * @param guess - the guess code object to compare against this code
     * @return number of digits that match in both value and position
     * Assumptions: guess has the same length as this code
     */
    int checkCorrect(const code& guess) const;
    
    /**
     * Checks how many digits in the guess are correct but in wrong location
     * @param guess - the guess code object to compare against this code
     * @return number of digits that match in value but not in position
     * Assumptions: guess has the same length as this code
     * Note: Digits already counted as correct position are not counted here
     */
    int checkIncorrect(const code& guess) const;
    
    /**
     * Prints the code to console
     */
    void print() const;
    
    /**
     * Gets the length of the code
     * @return the number of digits in the code
     */
    int getLength() const { return n; }
    
    /**
     * Gets the range of the code
     * @return the range value m
     */
    int getRange() const { return m; }
};

// Constructor implementation
code::code(int length, int range) {
    if (length <= 0 || range <= 0) {
        cerr << "Error: length and range must be positive integers" << endl;
        n = 1;
        m = 1;
    } else {
        n = length;
        m = range;
    }
    digits.resize(n, 0);
}

// Initialize code with random values
void code::initializeRandom() {
    for (int i = 0; i < n; i++) {
        digits[i] = rand() % m;
    }
}

// Initialize code with specific values
void code::initializeWithValues(const vector<int>& values) {
    if (values.size() != n) {
        cerr << "Error: values size does not match code length" << endl;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (values[i] < 0 || values[i] >= m) {
            cerr << "Error: value " << values[i] << " is out of range [0, " 
                 << m-1 << "]" << endl;
            return;
        }
    }
    
    digits = values;
}

// Check correct digits in correct positions
int code::checkCorrect(const code& guess) const {
    if (guess.n != n) {
        cerr << "Error: guess length does not match code length" << endl;
        return 0;
    }
    
    int correctCount = 0;
    for (int i = 0; i < n; i++) {
        if (digits[i] == guess.digits[i]) {
            correctCount++;
        }
    }
    return correctCount;
}

// Check correct digits in incorrect positions
int code::checkIncorrect(const code& guess) const {
    if (guess.n != n) {
        cerr << "Error: guess length does not match code length" << endl;
        return 0;
    }
    
    vector<bool> secretUsed(n, false);
    vector<bool> guessUsed(n, false);
    
    for (int i = 0; i < n; i++) {
        if (digits[i] == guess.digits[i]) {
            secretUsed[i] = true;
            guessUsed[i] = true;
        }
    }
    
    int incorrectCount = 0;
    for (int i = 0; i < n; i++) {
        if (!guessUsed[i]) {  
            for (int j = 0; j < n; j++) {
                if (!secretUsed[j] && digits[j] == guess.digits[i]) {
                    incorrectCount++;
                    secretUsed[j] = true;
                    break; 
                }
            }
        }
    }
    
    return incorrectCount;
}

// Print the code
void code::print() const {
    cout << "(";
    for (int i = 0; i < n; i++) {
        cout << digits[i];
        if (i < n - 1) cout << ", ";
    }
    cout << ")";
}

