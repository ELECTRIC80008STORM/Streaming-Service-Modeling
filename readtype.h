/*
* Streaming Service Modeling Proyect
* Rommel T.
*/

/*
Solution to the problem in which "cin" stops taking user input.
Copied from: https://latedev.wordpress.com/2011/09/13/simple-input-bullet-proofing-in-c/
The function was edited to be useful in the program.
*/

#ifndef INC_READTYPE_H
#define INC_READTYPE_H

#include <iostream>
#include <string>
#include <limits>

/**
 * Reads input of type T (this denotes that could be any type)
 * from the user with a prompt message.
 * Handles invalid input and reprompts the user until valid input is entered.
 * @param const std::string& prompt: the prompt message displayed to the user
 * @return T: the value of the input of type T
*/
template <typename T>
T ReadType( const std::string & prompt  ) {
    T n;
    while( (std::cout << prompt) && ! (std::cin>> n) ) {
        std::cout << "Invalid input!\n";
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );
    }
    return n;
}

#endif