/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:46:49 by rshaheen      #+#    #+#                 */
/*   Updated: 2025/05/26 15:46:50 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
    Fixed a; //created a by calling default constructor a is 0 here
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); //b is created by copy constructor using the muliplication result of 2 fixed created by int constructor and float constructor
    std::cout << ++a << std::endl; // Pre-increment: increases 'a' by 1, Since 1 raw unit = 1 / 256 = 0.00390625; Prints: 0.00390625
    std::cout << a << std::endl; //prints the value of a now 
    std::cout << a++ << std::endl; // Post-increment: prints current a first (0.00390625), Then increases raw value by 1 → a = 2 raw units
    std::cout << a << std::endl; // // a is now 2 raw units → 2 / 256 = 0.0078125- Prints: 0.0078125
    std::cout << b << std::endl; // Prints 'b', which holds result of 5.05 * 2 = 10.something
    std::cout << Fixed::max( a, b ) << std::endl;// Compares 2.0 and 10.10 → returns and prints 10.10

    std::cout << "\n===== EXTRA TESTS FOR FIXED CLASS =====\n";

    Fixed x(2.0f); //float constructor called
    Fixed y(5.0f); //float constructor called
    Fixed z; //default constructor called

    //Arithmetic operators: default constructor because they create a new local object with Fixed result;
    std::cout << "\n[Arithmetic Operators]\n";
    std::cout << "x: " << x << ", y: " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

    //Post-increment/decrement: copy constructor because they make a copy to return the old value.
    std::cout << "\n[Increment/Decrement Operators]\n";
    std::cout << "z: " << z << std::endl;
    std::cout << "++z: " << ++z << std::endl;
    std::cout << "z++: " << z++ << std::endl;
    std::cout << "z after z++: " << z << std::endl;
    std::cout << "--z: " << --z << std::endl;
    std::cout << "z--: " << z-- << std::endl;
    std::cout << "z after z--: " << z << std::endl;

    std::cout << "\n[Comparison Operators]\n";
    std::cout << "x: " << x << ", y: " << y << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;

    std::cout << "\n[Min/Max Functions]\n";
    std::cout << "min(x, y): " << Fixed::min(x, y) << std::endl;
    std::cout << "max(x, y): " << Fixed::max(x, y) << std::endl;

    const Fixed u(7.75f);
    const Fixed v(3.5f);
    std::cout << "const min(u, v): " << Fixed::min(u, v) << std::endl;
    std::cout << "const max(u, v): " << Fixed::max(u, v) << std::endl;

    return 0; 
}