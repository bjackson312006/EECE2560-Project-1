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
    response(int corr = 0, int incorr = 0);
    //
    // Initializes a response with correct and incorrect counts.
    // corr is number correct, incorr is number incorrect.
    //

    int getCorrect() const;
    //
    // Returns the number of correct positions.
    //

    int getIncorrect() const;
    //
    // Returns the number of incorrect positions.
    //

    void setCorrect(int c);
    //
    // Sets the number of correct positions.
    //

    void setIncorrect(int i);
    //
    // Sets the number of incorrect positions.
    //
};
// end class response

std::ostream& operator<<(std::ostream& os, response r);
//
// Writes a response to the output stream.
//

bool operator==(response r1, response r2);
//
// Returns true if two responses have equal values.
//
