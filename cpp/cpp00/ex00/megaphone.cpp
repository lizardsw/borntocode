/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:24:10 by seongwch          #+#    #+#             */
/*   Updated: 2022/10/25 21:34:42 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char **argv)
{
    int i;
    int j;
    int my_strlen;

    i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (i < argc)
        {
            my_strlen = std::strlen(argv[i]);
            j = 0;
            while (j < my_strlen)
            {
                std::cout << (char)(std::toupper(argv[i][j]));
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}