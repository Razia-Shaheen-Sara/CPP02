/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:44:18 by rshaheen      #+#    #+#                 */
/*   Updated: 2025/05/28 18:49:35 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed
{
	private:
    int					fixedPointValue;
    static const int	fractionalBitsNum = 8;

	public:
    // Default constructor
    Fixed();

    // Copy constructor: Makes a New Copy of an object
    Fixed(const Fixed& other);

    // Copy assignment operator: Assign values from an original object to another existing object
    Fixed& operator=(const Fixed& other);

    // Destructor
    ~Fixed();

    // Getter for raw bits
    int getRawBits(void) const;

    // Setter for raw bits
    void setRawBits(int const raw);
	
};

#endif