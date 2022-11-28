#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	this->ptr = new T[0];
	this->n_elem = 0;
}

template <class T>
Array<T>::~Array()
{
	delete[] this->ptr;
}

template <class T>
Array<T>::Array(const Array<T> &copy)
{
	this->ptr = new T[copy.n_elem];
	for (unsigned int i = 0; i < copy.n_elem; i++)
	{
		ptr[i] = copy.ptr[i]; 
	}
	this->n_elem = copy.n_elem;
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
	if(this != &copy)
	{
		delete[] this->ptr;
		this->ptr = new T[copy.n_elem];
		for (unsigned int i = 0; i < copy.n_elem; i++)
		{
			this->ptr[i] = copy.ptr[i];
		}
		this->n_elem = copy.n_elem;
	}
	return (*this);
}

template <class T>
Array<T>::Array(unsigned int n)
{
	this->ptr = new T[n];
	this->n_elem = n;
}

template <class T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= this->n_elem)
	{
		throw (Array<T>::IndexException());
	}
	return (this->ptr[index]);
}

template <class T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index < 0 || index >= this->n_elem)
	{
		throw (Array<T>::IndexException());
	}
	return (this->ptr[index]);
}

template <class T>
unsigned int Array<T>::size(void) const
{
	return (this->n_elem);
}

template <class T>
const char *Array<T>::IndexException::what() const throw()
{
	return ("index is out of bounds!");
}
