#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>

template <class T>
class MutantStack : public stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &copy);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void){return this->c.begin()};
		iterator end(void){return this->c.end()};

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
}



#endif