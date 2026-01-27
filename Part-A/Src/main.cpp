#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "code.hpp"
#include "response.hpp"

//
// Creates and prints a random secret code.
// length is number of digits and digRange is range [0, m-1].
// Assumes length > 0 and digRange > 0.
//
code createAndPrintSecretCode(int length, int digRange)
{
    if (length <= 0 || digRange <= 0) {
        std::cerr << "Error: length and digRange must be positive integers"
                  << std::endl;
        return code(1, 1);
    }

    code secret(length, digRange);
    secret.initializeRandom();
    secret.print();
    std::cout << std::endl;
    return secret;
}

//
// Creates a guess code from the provided values.
// length is number of digits and digRange is range [0, m-1].
// Assumes values.size() == length and values are within range.
//
code createSampleGuess(int length, int digRange, const std::vector<int>& values)
{
    if (length <= 0 || digRange <= 0) {
        std::cerr << "Error: length and digRange must be positive integers"
                  << std::endl;
        return code(1, 1);
    }

    if (static_cast<int>(values.size()) != length) {
        std::cerr << "Error: values size does not match length" << std::endl;
        return code(length, digRange);
    }

    code guess(length, digRange);
    guess.initializeWithValues(values);
    return guess;
}

//
// Creates the three required sample guesses.
// length is number of digits and digRange is range [0, m-1].
// Assumes length > 0 and digRange > 0.
//
std::vector<code> createThreeSampleGuesses(int length, int digRange)
{
    if (length <= 0 || digRange <= 0) {
        std::cerr << "Error: length and digRange must be positive integers"
                  << std::endl;
        return std::vector<code>();
    }

    std::vector<code> guesses;
    guesses.push_back(createSampleGuess(length, digRange,
        std::vector<int>{5, 0, 3, 2, 6}));
    guesses.push_back(createSampleGuess(length, digRange,
        std::vector<int>{2, 1, 2, 2, 2}));
    guesses.push_back(createSampleGuess(length, digRange,
        std::vector<int>{1, 3, 3, 4, 5}));
    return guesses;
}

//
// Prints the checkCorrect/checkIncorrect results for the sample guesses.
// secret is the code to compare against and guesses are the sample codes.
// Assumes secret and guesses have matching lengths and ranges.
//
void printSampleGuessResults(const code& secret,
                             const std::vector<code>& guesses)
{
    if (guesses.empty()) {
        std::cerr << "Error: guesses list is empty" << std::endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(guesses.size()); i++) {
        if (guesses[i].getLength() != secret.getLength() ||
            guesses[i].getRange() != secret.getRange()) {
            std::cerr << "Error: guess length or range does not match secret"
                      << std::endl;
            continue;
        }

        std::cout << "Guess " << i + 1 << ": ";
        guesses[i].print();
        std::cout << " -> ";
        std::cout << secret.checkCorrect(guesses[i]) << " ";
        std::cout << secret.checkIncorrect(guesses[i]) << std::endl;
    }
}

//
// Runs the Part A sample checks against a random secret code.
// Assumes length > 0 and digRange > 0.
//
int main()
{
    const int length = 5;
    const int digRange = 9;

    if (length <= 0 || digRange <= 0) {
        std::cerr << "Error: length and digRange must be positive integers"
                  << std::endl;
        return 1;
    }

    std::srand(std::time(0));
    code secret = createAndPrintSecretCode(length, digRange);

    std::vector<code> guesses = createThreeSampleGuesses(length, digRange);
    printSampleGuessResults(secret, guesses);

    return 0;
}
