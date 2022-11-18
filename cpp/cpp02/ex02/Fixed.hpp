/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:08:58 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/11 17:16:39 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int                 number;
		const static int    bits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& copy);
		Fixed &operator=(const Fixed& copy);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool operator<(const Fixed& operand) const;
		bool operator<=(const Fixed& operand) const;
		bool operator>(const Fixed& operand) const;
		bool operator>=(const Fixed& operand) const;
		bool operator==(const Fixed& operand) const;
		bool operator!=(const Fixed& operand) const;

		Fixed operator+(const Fixed& operand) const;
		Fixed operator-(const Fixed& operand) const;
		Fixed operator*(const Fixed& operand) const;
		Fixed operator/(const Fixed& operand) const;

		Fixed &operator++(void);
		const Fixed operator++(int);
		Fixed &operator--(void);
		const Fixed operator--(int);

		static Fixed& min(Fixed &one, Fixed &two);
		const static Fixed& min(const Fixed &one, const Fixed &two);
		static Fixed& max(Fixed &one, Fixed &two);
		const static Fixed& max(const Fixed &one, const Fixed &two);

};

std::ostream& operator <<(std::ostream &out, const Fixed &copy);

#endif