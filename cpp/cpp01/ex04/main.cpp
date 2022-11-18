/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:58:27 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/09 13:09:32 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "argument error!" << std::endl;
    }
    else
    {
        std::ifstream   infile;
        std::ofstream   outfile;
        std::string     buffer;
        std::string     outfile_name(argv[1]);
        std::string     s1(argv[2]);
        std::string     s2(argv[3]);
        int             temp = 0;
        int             pos = 0;

        if (s1.length() < 1)
        {
            std::cout << "s1 error!" << std::endl;
            exit(1);
        }
        infile.open(argv[1]);
        if (infile.is_open())
        {
            outfile_name.append(".replace");
            outfile.open(outfile_name, std::ios::trunc);
            if (outfile.is_open())
            {
                while (!infile.eof())
                {
                    std::getline(infile, buffer);
                    pos = 0;
                    while (1)
                    {
                        temp = buffer.find(s1, pos);
                        if (temp >= 0)
                        {
                            buffer.erase(temp, s1.length());
                            buffer.insert(temp, s2);
                            pos = temp + s2.length();
                        }
                        else
                            break;
                    }
                    if (buffer.length() != 0)
                        outfile << buffer << std::endl;;
                }
                outfile.close();
            }
            else
               std::cout << "outfile_open_error!" << std::endl;     
            infile.close();
        }
        else
            std::cout << "infile_open_error!" << std::endl;
    }
    return (0);
}