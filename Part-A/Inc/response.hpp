//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-a Upload Link
// Header for the response class used by the Mastermind game.
//
#pragma once

#include <iostream>

class response
{
private:
    int correct;
    int incorrect;

public:
    //
    // Initializes a response with correct and incorrect counts.
    // corr is number correct, incorr is number incorrect.
    //
    response(int corr = 0, int incorr = 0);

    //
    // Returns the number of correct positions.
    //
    int getCorrect() const;

    //
    // Returns the number of incorrect positions.
    //
    int getIncorrect() const;

    //
    // Sets the number of correct positions.
    //
    void setCorrect(int c);

    //
    // Sets the number of incorrect positions.
    //
    void setIncorrect(int i);
};

//
// Writes a response to the output stream.
//
std::ostream& operator<<(std::ostream& os, response r);

//
// Returns true if two responses have equal values.
//
bool operator==(response r1, response r2);
