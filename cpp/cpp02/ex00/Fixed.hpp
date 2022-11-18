/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:34:25 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/11 17:51:40 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 number;
        const static int    bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed &operator=(const Fixed& copy);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
