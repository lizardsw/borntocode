#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T container,int value)
{
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
	{
		throw(std::runtime_error("this value is not in this conatiner......"));
	}
	return (iter);
}

#endif