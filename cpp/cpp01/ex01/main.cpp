/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:13 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/08 21:28:14 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *my_zombies;
    int number = 0;

    std::cout << "insert zombie num : ";
    std::cin >> number;
    my_zombies = zombieHorde(number, "seongwch");
    for (int i = 0; i < number; i++)
    {
        my_zombies[i].announce();
    }
    delete[] my_zombies;
    return 0;
}