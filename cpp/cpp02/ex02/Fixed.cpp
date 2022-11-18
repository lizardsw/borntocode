/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:08:55 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/11 19:38:13 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed& copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->number = copy.getRawBits();
	return (*this);
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->number = value & (0x80000000);
	this->number |= (value << this->bits) & (0x7fffffff);
}

Fixed::Fixed(const float value)
{
	// std::cout << "float constructor called" << std::endl;
	this->number = static_cast<int>(roundf(value * (1 << this->bits)));
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "settRawBits member function called" << std::endl;
	this->number = raw;
}

float Fixed::toFloat(void) const
{
	// std::cout << "call toFloat" << std::endl;
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

// comparison operator

bool Fixed::operator<(const Fixed& operand) const
{
	return (this->getRawBits() < operand.getRawBits());
}

bool Fixed::operator<=(const Fixed& operand) const
{
	return (this->getRawBits() <= operand.getRawBits());
}

bool Fixed::operator>(const Fixed& operand) const
{
	return (this->getRawBits() > operand.getRawBits());
}

bool Fixed::operator>=(const Fixed& operand) const
{
	return (this->getRawBits() >= operand.getRawBits());
}

bool Fixed::operator==(const Fixed& operand) const
{
	return (this->getRawBits() == operand.getRawBits());
}

bool Fixed::operator!=(const Fixed& operand) const
{
	return (this->getRawBits() != operand.getRawBits());
}

// math operator

Fixed Fixed::operator+(const Fixed& operand) const
{
	Fixed return_value(this->toFloat() + operand.toFloat());
	return (return_value);
}
Fixed Fixed::operator-(const Fixed& operand) const
{
	Fixed return_value(this->toFloat() - operand.toFloat());
	return (return_value);
}
Fixed Fixed::operator*(const Fixed& operand) const
{
	Fixed return_value(this->toFloat() * operand.toFloat());
	return (return_value);
}
Fixed Fixed::operator/(const Fixed& operand) const
{
	Fixed return_value(this->toFloat() / operand.toFloat());
	return (return_value);
}

// increment operator

Fixed &Fixed::operator++(void)
{
	this->number++;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->number++;
	return (temp);
}

Fixed &Fixed::operator--(void)
{
	this->number--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->number--;
	return (temp);
}

// max min operator
Fixed& Fixed::min(Fixed &one, Fixed &two)
{
	if (one > two)
		return (two);
	else
		return (one);
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one > two)
		return (two);
	else
		return (one);
}

Fixed& Fixed::max(Fixed &one, Fixed &two)
{
	if (one < two)
		return (two);
	else
		return (one);
}

const Fixed& Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one < two)
		return (two);
	else
		return (one);
}