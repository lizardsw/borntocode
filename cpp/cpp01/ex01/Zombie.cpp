/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:18 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/08 21:28:19 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << " : " << "destructor" << std::endl; 
}

void    Zombie::announce(void)
{
    std::cout << this->name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_zombie_name(std::string name)
{
    this->name = name;
}