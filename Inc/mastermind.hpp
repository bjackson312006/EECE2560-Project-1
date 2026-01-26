#include "code.hpp"

class mastermind {
    private:
        code secret;
    public:
        /* Constructors */
        mastermind(int n, int m); // Custom values for n and m.
        mastermind(void); // No custom values for n and m. Defaults to n=5 and m=10.

        /* Prints out the secret code. */
        void printSecret(void) const;

        /* Reads a guess from the keyboard and returns a code object representing the guess code. */
        const code humanGuess(void) const;
};