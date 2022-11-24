#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

void display_input(char input);
void display_input(int input);
void display_input(float input);
void display_input(double input);

std::ostream &operator<<(std::ostream &out, char temp);


#endif