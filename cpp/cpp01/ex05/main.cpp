/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:59:31 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/08 20:59:31 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl my_harl;

    my_harl.complain("DEBUG");
    my_harl.complain("INFO");
    my_harl.complain("WARNING");
    my_harl.complain("ERROR");
    my_harl.complain("EXCEPT");

    return 0;
}