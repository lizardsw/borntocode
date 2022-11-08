/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:34 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/08 21:28:35 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string temp = "HI THIS IS BRAIN";
    std::string *stringPTR = &temp;
    std::string &stringREF = temp;

    std::cout << "<<address>>" << std::endl;
    std::cout << "address of the string variable : " << &temp << std::endl;
    std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "<<value>" << std::endl;
    std::cout << "value of the string variable : " << temp << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;

    return (0);
}