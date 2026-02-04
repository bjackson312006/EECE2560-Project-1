//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-b Upload Link
// Implementation of the response class for Mastermind
//
#include <iostream>
#include "response.hpp"

using namespace std;

response::response(int corr, int incorr)
//
// Constructor
// corr is number correct and incorr is number incorrect
// Assumes corr >= 0 and incorr >= 0
//
{
    correct = corr;
    incorrect = incorr;
}

int response::getCorrect() const
//
// Returns the stored correct count
//
{
    return correct;
}

int response::getIncorrect() const
//
// Returns the stored incorrect count
//
{
    return incorrect;
}

void response::setCorrect(int c)
//
// Sets the stored correct count
// Assumes c >= 0
//
{
    correct = c;
}

void response::setIncorrect(int i)
//
// Sets the stored incorrect count
// Assumes i >= 0
//
{
    incorrect = i;
}

bool operator==(response r1, response r2)
//
// Global operator==
// r1 and r2 are responses to compare
//
{
    return r1.getCorrect() == r2.getCorrect() &&
           r1.getIncorrect() == r2.getIncorrect();
}

ostream& operator<<(ostream& os, response r)
//
// Global operator<<
// r is the response to print
//
{
    os << "Correct: " << r.getCorrect()
       << ", Incorrect: " << r.getIncorrect();
    return os;
}