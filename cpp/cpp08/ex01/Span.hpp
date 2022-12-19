#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Span
{
	private:
		std::vector<int> vec;
		unsigned int N;
		Span();
	public:
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();
		Span(unsigned int N);
		void addNumber(int number);
		void addRandNumber(int number);

		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
};

#endif