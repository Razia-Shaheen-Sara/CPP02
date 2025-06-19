/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:45:10 by rshaheen      #+#    #+#                 */
/*   Updated: 2025/05/30 16:15:36 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed
{
	private:
    int					fixedPointValue;
    static const int	fractionalBitsVal = 8;//number of bits used after the binary point to represent the fraction part.

	public:
	
    Fixed();
    // Copy constructor: Makes a New Copy of an object
    Fixed(const Fixed& other);
    // Copy assignment operator: Assign values from an original object to another existing object
    Fixed& operator=(const Fixed& other);
    ~Fixed();

	Fixed(const int int_num);  //constructor to convert the int to corresponding fixed point value
	Fixed(const float float_num);  //constructor to convert the float to corresponding fixed point value

    int getRawBits(void) const;
    void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);//custom function that inserts a float when given a fixed point 

#endif


//This operator overload enables--Clean and readable output for Fixed objects.
//Conversion of internal fixed-point data into a standard floating-point format for display.
//std::ostream& out: A reference to an output stream (e.g., std::cout, std::ofstream, etc.).Used to output the formatted data.
//const Fixed& obj: A constant reference to the Fixed object you want to print.Declared as const because the function does not modify obj.
//return value: type --std::ostream& Purpose: Enables stream chaining and continues writing to the same output stream.