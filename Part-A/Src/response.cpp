//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-a Upload Link
// Implementation of the response class for Mastermind.
//
#include <iostream>
#include "response.hpp"

using namespace std;

//
// Initializes a response with correct and incorrect counts
// corr is number correct, incorr is number incorrect
//
response::response(int corr, int incorr)
{
    correct = corr;
    incorrect = incorr;
}

//
// Returns the number of correct positions
//
int response::getCorrect() const
{
    return correct;
}

//
// Returns the number of incorrect positions
//
int response::getIncorrect() const
{
    return incorrect;
}

//
// Sets the number of correct positions
//
void response::setCorrect(int c)
{
    correct = c;
}

//
// Sets the number of incorrect positions
//
void response::setIncorrect(int i)
{
    incorrect = i;
}

//
// Returns true if two responses have equal values
//
bool operator==(response r1, response r2)
{
    return r1.getCorrect() == r2.getCorrect() &&
           r1.getIncorrect() == r2.getIncorrect();
}

//
// Writes a response to the output stream
//
ostream& operator<<(ostream& os, response r)
{
    os << "Correct: " << r.getCorrect() << ", Incorrect: " << r.getIncorrect();
    return os;
}
