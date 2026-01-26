#include <iostream>
#include "response.hpp"

using namespace std;

class response {
    private:
        int correct;
        int incorrect;

    public:
        // Constructor
        response::response(int corr = 0, int incorr = 0) {
            correct = corr;
            incorrect = incorr;
        }

    // Getters
    int getCorrect() { return correct; }
    int getIncorrect() { return incorrect; }

    // Setters
    void setCorrect(int c) { correct = c; }
    void setIncorrect(int i) { incorrect = i; }
};

// Constructor
response::response(int corr = 0, int incorr = 0) {
    correct = corr;
    incorrect = incorr;
}

// Getters
int response::getCorrect() { return correct; }
int response::getIncorrect() { return incorrect; }

// Setters
void response::setCorrect(int c) { correct = c; }
void response::setIncorrect(int i) { incorrect = i; }

// Global operator==
bool operator==(response r1, response r2) {
    return r1.getCorrect() == r2.getCorrect() && r1.getIncorrect() == r2.getIncorrect();
}

// Global operator<<
ostream& operator<<(ostream& os, response r) {
    os << "Correct: " << r.getCorrect() << ", Incorrect: " << r.getIncorrect();
    return os;
}