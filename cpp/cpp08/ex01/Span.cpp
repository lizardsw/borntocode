#include "Span.hpp"

Span::Span()
{
}

Span::Span(const Span &copy)
{
	this->vec = copy.vec;
}

Span &Span::operator=(const Span &copy)
{
	this->vec = copy.vec;
	this->N = copy.N;
	return (*this);
}

Span::~Span()
{
}

Span::Span(unsigned int N)
{
	this->vec.reserve(N);
	this->N = N;
}

void Span::addNumber(int number)
{
	if (this->vec.capacity() == this->vec.size())
	{
		throw(std::runtime_error("full container!"));
	}
	this->vec.push_back(number);
}

void Span::addRandNumber(int number)
{
	static int seed;
	int temp;
	if (seed == 0)
	{
		seed = 1;
		std::srand((unsigned int)std::time(NULL));
	}
	for (int i = 0; i < number; i++)
	{
		temp = std::rand() % 10000;
		this->addNumber(temp);
	}
}

unsigned int Span::shortestSpan(void) const
{
	if (this->vec.size() < 2)
	{
		throw(std::runtime_error("size small!!"));
	}
	unsigned int shortspan = UINT_MAX;
	std::vector<int>temp = this->vec;
	std::sort(temp.begin(), temp.end());
	std::vector<int>::iterator iter;
	for (iter = temp.begin() + 1; iter != temp.end(); iter++)
	{
		if (shortspan > static_cast<unsigned int>(*iter - *(iter - 1)))
		{
			shortspan =  static_cast<unsigned int>(*iter - *(iter - 1));
		}
	}
	return (shortspan);
}

unsigned int Span::longestSpan(void) const
{
	if (this->vec.size() < 2)
	{
		throw(std::runtime_error("size small!"));
	}
	unsigned int longspan;
	longspan = *std::max_element(this->vec.begin() , this->vec.end()) - \
					*std::min_element(this->vec.begin() , this->vec.end());
	return (longspan);
}