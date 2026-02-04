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

    //
    // Implementation methods called by playGame()
    //
    // Prints out the secret code
    //
    void printSecret(void) const;

    //
    // Reads a guess from the keyboard and returns a code object
    // representing the guess code
    //
    const code humanGuess(void) const;

    //
    // Gets the response to a guess
    //
    const response getResponse(const code& guess) const;

    //
    // Checks if a response object is solved or not
    //
    const bool isSolved(const response& response) const;

public:
    //
    // Constructors
    //
    // Custom values for n and m
    //
    mastermind(int n, int m);

    //
    // No custom values for n and m. Defaults to n=5 and m=10
    //
    mastermind(void);

    //
    // Plays the game
    //
    const void playGame(void);
};