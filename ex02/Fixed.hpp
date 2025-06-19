/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:47:11 by rshaheen      #+#    #+#                 */
/*   Updated: 2025/05/26 15:47:12 by rshaheen      ########   odam.nl         */
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

    //6 comparison operators
    bool operator>(const Fixed& to_cmp);
	bool operator<(const Fixed& to_cmp);
	bool operator==(const Fixed& to_cmp);
	bool operator>=(const Fixed& to_cmp);
	bool operator<=(const Fixed& to_cmp);
	bool operator!=(const Fixed& to_cmp);	


    //4 arithmatic operators
    Fixed operator+(const Fixed& fixed)const;
	Fixed operator-(const Fixed& fixed)const;
	Fixed operator*(const Fixed& fixed)const;
	Fixed operator/(const Fixed& fixed)const;

	//4 increament decrement operators
    Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	
    //4 member functions
	static const Fixed& min(Fixed& ref_one, Fixed& ref_two);
	static const Fixed& max(Fixed& ref_one, Fixed& ref_two);
	static const Fixed& min(const Fixed& ref_one, const Fixed& ref_two);
	static const Fixed& max(const Fixed& ref_one, const Fixed& ref_two);
	
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);//custom function that inserts a float when given a fixed point 

#endif