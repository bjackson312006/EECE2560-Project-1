//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-a Upload Link
// Implementation of the response class for Mastermind.
//
#include <iostream>
#include "response.hpp"

using namespace std;

response::response(int corr, int incorr)
//
// Initializes a response with correct and incorrect counts
// corr is number correct, incorr is number incorrect
//
{
    correct = corr;
    incorrect = incorr;
}

int response::getCorrect() const
//
// Returns the number of correct positions
//
{
    return correct;
}

int response::getIncorrect() const
//
// Returns the number of incorrect positions
//
{
    return incorrect;
}

void response::setCorrect(int c)
//
// Sets the number of correct positions
//
{
    correct = c;
}

void response::setIncorrect(int i)
//
// Sets the number of incorrect positions
//
{
    incorrect = i;
}

bool operator==(response r1, response r2)
//
// Returns true if two responses have equal values
//
{
    return r1.getCorrect() == r2.getCorrect() &&
           r1.getIncorrect() == r2.getIncorrect();
}

ostream& operator<<(ostream& os, response r)
//
// Writes a response to the output stream
//
{
    os << "Correct: " << r.getCorrect() << ", Incorrect: " << r.getIncorrect();
    return os;
}
