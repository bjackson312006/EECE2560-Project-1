#pragma once

#include "code.hpp"
#include "response.hpp"

class mastermind {
    private:
        code secret;

        /* Implementation methods called by playGame(). */
        void printSecret(void) const;                        // Prints out the secret code.
        const code humanGuess(void) const;                   // Reads a guess from the keyboard and returns a code object representing the guess code.
        const response getResponse(const code& guess) const; // Gets the response to a guess.
        const bool isSolved(const response& response) const; // Checks if a response object is solved or not.

    public:
        /* Constructors */
        mastermind(int n, int m); // Custom values for n and m.
        mastermind(void); // No custom values for n and m. Defaults to n=5 and m=10.

        /* Plays the game. */
        const void playGame(void);
};