//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-b Upload Link
// Header for the mastermind class used by the Mastermind game
//
#pragma once

#include "code.hpp"
#include "response.hpp"

class mastermind
{
private:
    code secret;

    void printSecret(void) const;
    //
    // Implementation methods called by playGame()
    //
    // Prints out the secret code
    // Assumes secret is initialized
    //

    const code humanGuess(void) const;
    //
    // Reads a guess from the keyboard and returns a code object
    // representing the guess code
    // Assumes user enters integers in range [0, m-1]
    //

    const response getResponse(const code& guess) const;
    //
    // Gets the response to a guess
    // guess is the code object to compare against secret
    //

    const bool isSolved(const response& response) const;
    //
    // Checks if a response object is solved or not
    // response is the result of a guess
    //

public:
    mastermind(int n, int m);
    //
    // Constructors
    //
    // Custom values for n and m
    // n is code length and m is digit range
    // Assumes n > 0 and m > 0
    //

    mastermind(void);
    //
    // No custom values for n and m. Defaults to n=5 and m=10
    //

    const void playGame(void);
    //
    // Plays the game
    // Assumes secret is initialized and input is given by the user
    //
};