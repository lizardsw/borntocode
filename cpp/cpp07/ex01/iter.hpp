#ifndef ITER_HPP 
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename U>
void iter(T *array, int length, U ft)
{
	for (int i = 0; i < length; i++)
	{
		ft(array[i]);
	}
}

template<typename T>
void iter_print(T &input)
{
	std::cout << input << " ";
}

template<typename T>
void plus_one(T &input)
{
	input += 1;
}

template<>
void plus_one(std::string &input)
{
	input += "one";
}

#endif