//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #1 MasterMind-b Upload Link
// Implementation of the mastermind class for Mastermind
//
#include "mastermind.hpp"
#include <limits>
#include <sstream>
#include <string>

//
// Constructors.
// Initializes 'secret' with user-defined n and m values
//
mastermind::mastermind(int n, int m)
    : secret(n, m)
{
    return;
}

//
// Initializes 'secret' with default values (n=5, m=10)
//
mastermind::mastermind(void)
    : secret(5, 10)
{
    return;
}

//
// Prints out the secret code
//
void mastermind::printSecret(void) const
{
    this->secret.print();
}

//
// Reads a guess from the keyboard and returns a code object
// representing the guess code
//
const code mastermind::humanGuess(void) const
{
    int n = secret.getLength();
    int m = secret.getRange();

    // Prompt user to enter in digits
    std::cout << "Enter " << n << " digits (0.." << (m - 1) << ").\n";
    std::vector<int> values;
    values.reserve(n);

    // Loop through each integer input individually
    for (int i = 0; i < n; i++)
    {
        
        // Inner infinite loop to validate individual integer inputs
        while (1)
        {
            std::cout << "Integer " << (i + 1) << ": ";

            // Using this instead of normal cin because it makes it easier
            // to validate input
            std::string line;
            std::getline(std::cin >> std::ws, line); // Reads the whole line
            std::stringstream ss(line);

            int x;
            char extra;

            // Make sure input is a single integer
            if (!(ss >> x) || (ss >> extra))
            {
                std::cout << "Invalid input (must be a single integer value)."
                          << std::endl;
                continue;
            }

            // Make sure input is within range
            if (x < 0 || x >= m)
            {
                std::cout << "Out of range. Must be 0.." << (m - 1) << ".\n";
                continue;
            }

            // Valid input for this digit, so go to the next digit
            values.push_back(x);
            break;
        }
    }

    // Finalize guess
    code guess(n, m);
    guess.initializeWithValues(values);
    std::cout << std::endl << "Your guess: ";
    guess.print();
    std::cout << std::endl;
    return guess;
}

//
// Gets the response to a guess
//
const response mastermind::getResponse(const code& guess) const
{
    int correct = secret.checkCorrect(guess);
    int incorrect = secret.checkIncorrect(guess);
    return response(correct, incorrect);
}

//
// Checks if a response object is solved or not
//
const bool mastermind::isSolved(const response& response) const
{
    return response.getCorrect() == this->secret.getLength();
}

//
// Plays the game
//
const void mastermind::playGame(void)
{
    static bool seeded = false;

    // Track seeding state (so you only seed once)
    if (seeded == false)
    {
        std::srand(std::time(nullptr));
        seeded = true;
    }

    // Init the secret and print it
    this->secret.initializeRandom();
    std::cout << "Secret code (for testing): ";
    this->secret.print();
    std::cout << std::endl;

    // Actual game
    constexpr int MAX_GUESSES = 10;
    for (int attempt = 1; attempt <= MAX_GUESSES; attempt++)
    {
        std::cout << std::endl << "Guess " << attempt << " of " << MAX_GUESSES
                  << std::endl;
        code guess = humanGuess();
        response r = getResponse(guess);
        std::cout << r << std::endl;

        if (isSolved(r))
        {
            std::cout << "You win! Solved in " << attempt << " guesses!"
                      << std::endl;
            return;
        }
    }

    // If this point is reached, player must've used all guesses (so they lost)
    std::cout << "You lose! You did not solve the code in 10 guesses."
              << std::endl;
    std::cout << "The secret code was: ";
    this->secret.print();
    std::cout << std::endl;
}