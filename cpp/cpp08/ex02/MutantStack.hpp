#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <list>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void){};
		MutantStack(const MutantStack &copy){*this = copy;};
		MutantStack &operator=(const MutantStack &copy)
		{
			if (*this != copy)
			{
				std::stack<T>::operator=(copy);
			}
			return(*this);
		};
		~MutantStack(void){};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void){return this->c.begin();}
		iterator end(void){return this->c.end();}

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin(void){return this->c.cbegin();}
		const_iterator cend(void){return this->c.cend();}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void){return this->c.rbegin();}
		reverse_iterator rend(void){return this->c.rend();}

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin(void){return this->c.crbegin();}
		const_reverse_iterator crend(void){return this->c.crend();}
};

#endif