/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:44:03 by rshaheen      #+#    #+#                 */
/*   Updated: 2025/05/28 19:08:20 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Default constructor: creates an object
Fixed::Fixed() : fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor: copies the org/given object
Fixed::Fixed(const Fixed& orgObject) //takes a ref to the original object
{
    std::cout << "Copy constructor called" << std::endl;
    fixedPointValue = orgObject.getRawBits();
}

// Copy assignment operator assigns the value of org/given object to another object
// Return a reference to the current object to allow chaining (e.g., a = b = c;)
// operator= is a special function in C++ for doing a = b style assigning
//"this" is a pointer to the object on the left-hand side of the assignment (a = b; 'a' is this).

Fixed& Fixed::operator=(const Fixed& orgObject) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &orgObject) //not trying to assign the object to itself
	{
        this->fixedPointValue = orgObject.getRawBits();//setting the fixedPointValue of the left-hand object to the value from the right-hand object.
    }
    return (*this);//return a reference to the current object
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// Getter for raw bits
int Fixed::getRawBits() const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPointValue);
}

// Setter for raw bits-- made for later exercise
void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    fixedPointValue = raw;
}


//Why Use a Reference in a Copy Constructor?
//If we didn’t use a reference and instead passed by value like this:
//Fixed::Fixed(Fixed source) // ❌ Bad idea
//It would create a copy of the object to pass it in…
//Which would invoke another copy constructor to make that copy…
//Which would again try to copy the object…
//Leading to an infinite loop → 🔁 → 💥 Stack overflow!