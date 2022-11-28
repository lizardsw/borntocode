#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>
class Array
{
	private:
		T *ptr;
		unsigned int n_elem;
	public:
		Array();
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		~Array();

		Array(unsigned int n);
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		unsigned int size(void) const;
		class IndexException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif 