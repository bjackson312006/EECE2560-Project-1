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
    //
    // Constructor
    //
    response(int corr = 0, int incorr = 0);

    //
    // Getters
    //
    int getCorrect() const;

    int getIncorrect() const;

    //
    // Setters
    //
    void setCorrect(int c);

    void setIncorrect(int i);
};

//
// Global operator<<
//
std::ostream& operator<<(std::ostream& os, response r);

//
// Global operator==
//
bool operator==(response r1, response r2);