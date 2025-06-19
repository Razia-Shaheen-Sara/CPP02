/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:45:31 by rshaheen      #+#    #+#                 */
/*   Updated: 2025/05/28 19:30:16 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

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

//converts int_num to corresponding fixed point value
//int_num << fractionalBitsVal means: Multiply int_num by 2^fractionalBitsVal(8) using a bit shift.
//So corresponding fixedPointValue = int_num * (2^8)
//Example: if int_num is 3, then fixedPointValue = 3 * (2^8) = 768

Fixed::Fixed(const int int_num) : fixedPointValue(int_num << fractionalBitsVal)
{
	std::cout << "Int constructor called" << std::endl;
}

// Converts float_num to corresponding fixed-point value
// float_num * (1 << fractionalBitsVal) means: Multiply float by 2^fractionalBitsVal (8) to scale it
// roundf() is used to round the result to the nearest integer
// So: fixedPointValue = round(float_num * (2^8))
// Example: if float_num is 3.5, then fixedPointValue = round(3.5 * 256) = round(896.0) = 896

Fixed::Fixed(const float float_num) : fixedPointValue(roundf(float_num*(1 << fractionalBitsVal)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// Getter for raw bits
int Fixed::getRawBits() const 
{
    return (fixedPointValue);
}

// Setter for raw bits-- made for later exercise
void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    fixedPointValue = raw;
}

// Converts fixed point value to float
// Divide by 2^fractionalBitsVal (8)
// So: float_value = fixedPointValue / (2^8)
// Example: if fixedPointValue = 896, then float_value = 896 / 256 = 3.5
float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointValue) / (1 << fractionalBitsVal));
}

// Converts fixed-point value to int
// Shift right by fractionalBitsVal (8) to remove the fractional part
// This is like dividing by 2^8 and keeping only the whole number
// Example: if fixedPointValue = 896, then result = 896 >> 8 = 3
int Fixed::toInt(void) const
{
	int result = fixedPointValue >> fractionalBitsVal;
	return (result);
}

// Overloads << operator to print Fixed objects
// Converts Fixed to float using toFloat()
// Inserts the float value into the output stream
// So when you do: std::cout << fixedObj;
// It prints the floating-point number stored in fixedObj
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
