/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:22:38 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/09 12:59:22 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie A("first");
    Zombie *B;
    
    B = newZombie("second");
    A.announce();
    B->announce();
    randomChump("third");
    delete B;

    return 0;
}