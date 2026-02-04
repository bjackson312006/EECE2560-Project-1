//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-b Upload Link
// Header for the response class used by the Mastermind game
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
    // Constructor
    // corr is number correct and incorr is number incorrect
    // Assumes corr >= 0 and incorr >= 0
    //

    int getCorrect() const;
    //
    // Returns the stored correct count
    //

    int getIncorrect() const;
    //
    // Returns the stored incorrect count
    //

    void setCorrect(int c);
    //
    // Sets the stored correct count
    // Assumes c >= 0
    //

    void setIncorrect(int i);
    //
    // Sets the stored incorrect count
    // Assumes i >= 0
    //
};

std::ostream& operator<<(std::ostream& os, response r);
//
// Global operator<<
// os is the output stream and r is the response to print
//

bool operator==(response r1, response r2);
//
// Global operator==
// r1 and r2 are responses to compare
//
