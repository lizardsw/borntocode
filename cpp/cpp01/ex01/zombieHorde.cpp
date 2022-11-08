/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:16 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/08 21:28:16 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    Zombie *new_zombies;
    std::stringstream ss;

    new_zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        ss.str("");
        ss << name << i + 1;
        new_zombies[i].set_zombie_name(ss.str());
    }
    return new_zombies;
}