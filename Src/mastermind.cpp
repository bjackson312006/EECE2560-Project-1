#include "mastermind.hpp"
#include <limits>

/* Constructors. */
mastermind::mastermind(int n, int m) : secret(n,m) { return; } // Initializes 'secret' with user-defined n and m values.
mastermind::mastermind(void) : secret(5,10) { return; } // Initializes 'secret' with default values (n=5, m=10).

/* Prints out the secret code. */
void mastermind::printSecret(void) const {
    this->secret.print();
}

/* Reads a guess from the keyboard and returns a code object representing the guess code. */
const code mastermind::humanGuess(void) const {
    /* Store the current n and m values based on the secret code. */
    int n = this->secret.getLength();
    int m = this->secret.getRange();

    /* Infinite loop until input is successful. */
    while(1) {        
        std::vector<int> values = { 0 };
        int x = 0;

        /* Prompt user to enter in digits. */
        std::cout << "Enter " << n << " digits (0.." << (m-1) << "): ";
        for(int i = 0; i < n; i++) {
            if(!(std::cin >> x)) {
                /* handle invalid input */
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                std::cout << "Invalid input: please enter integers only." << std::endl;
                values.clear();
                continue;
            }
            values.push_back(x);
        }
        if(values.size() != n) { continue; } // Make sure values is the correct size based on 'n'.

        /* Ensure the values are within range. */
        bool status = true;
        for(int i = 0; i < values.size(); i++) {
            int value = values[i];
            if((value < 0) || (value >= m)) {
                status = false;
                break;
            }
        }
        if(!status) {
            std::cout << "Out of range. Digits must be 0.." << (m-1) << "." << std::endl;
            continue;
        }

        /* Create the guess, initialize it with the values, and return it. */
        code guess(n, m);
        guess.initializeWithValues(values);
        return guess;
    }
}