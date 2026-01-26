#include <iostream>
#include "response.hpp"

using namespace std;

// Constructor
response::response(int corr, int incorr) {
    correct = corr;
    incorrect = incorr;
}

// Getters
int response::getCorrect() const { return correct; }
int response::getIncorrect() const { return incorrect; }

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