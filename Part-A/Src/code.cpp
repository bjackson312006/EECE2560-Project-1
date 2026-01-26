#include "code.hpp"

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