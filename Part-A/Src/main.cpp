#include <stdio.h>
#include "code.hpp"
#include "response.hpp"

/* main() for part a. */
int main(void) {
    /* Initialize and print the secret code. */
    code secret(5, 10);
    secret.initializeRandom();
    std::cout << "Secret=";
    secret.print();
    std::cout << std::endl << std::endl;

    /* First sample guess */
    std::vector<int> one = {5,0,3,2,6};
    code first_guess(5, 10);
    first_guess.initializeWithValues(one);
    std::cout << "First sample guess: ";
    first_guess.print();
    std::cout << std::endl << "checkCorrect=" << secret.checkCorrect(first_guess) << std::endl;
    std::cout << "checkIncorrect=" << secret.checkIncorrect(first_guess) << std::endl << std::endl;

    /* Second sample guess */
    std::vector<int> two = {2,1,2,2,2};
    code second_guess(5, 10);
    second_guess.initializeWithValues(two);
    std::cout << "Second sample guess: ";
    second_guess.print();
    std::cout << std::endl << "checkCorrect=" << secret.checkCorrect(second_guess) << std::endl;
    std::cout << "checkIncorrect=" << secret.checkIncorrect(second_guess) << std::endl << std::endl;

    /* Third sample guess */
    std::vector<int> three = {1,3,3,4,5};
    code third_guess(5, 10);
    third_guess.initializeWithValues(three);
    std::cout << "Third sample guess: ";
    third_guess.print();
    std::cout << std::endl << "checkCorrect=" << secret.checkCorrect(third_guess) << std::endl;
    std::cout << "checkIncorrect=" << secret.checkIncorrect(third_guess) << std::endl << std::endl;
    return 0;
}
