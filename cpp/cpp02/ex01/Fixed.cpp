/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:08:55 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/11 17:30:22 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->number = copy.getRawBits();
	return (*this);
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = value << this->bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "float constructor called" << std::endl;
	this->number = static_cast<int>(roundf(value * (1 << this->bits)));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "settRawBits member function called" << std::endl;
	this->number = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->number) / (1 << this->bits));
}

int Fixed::toInt(void) const
{
	return (this->number >> this->bits);
}

std::ostream& operator <<(std::ostream &out, const Fixed &copy)
{
	out << copy.toFloat();
	return (out);
}
