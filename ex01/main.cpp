/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:44:57 by rshaheen      #+#    #+#                 */
/*   Updated: 2025/05/28 19:17:06 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;       //obj a created by default constructor
	Fixed const b( 10 ); // Calls int constructor and converts 10 to 
	Fixed const c( 42.42f ); // Calls float constructor and converts 42.42 to fixed-point value
	Fixed const d( b ); // Calls copy constructor and copies fixed-point value from b
	a = Fixed( 1234.4321f ); // Calls float constructor, converts 1234.4321 to fixed-point, then assigns the value to 'a'
	std::cout << "a is " << a << std::endl; // Prints float value of 'a'
	std::cout << "b is " << b << std::endl; 
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // Prints int part of 'a'
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
	
}