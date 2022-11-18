#include "../includes/Span.hpp"

Span::Span(unsigned int N)
    : maxNum(N)
{
}

Span::Span(const Span &span)
    : maxNum(span.maxNum), totalNum(span.totalNum)
{
}

Span &Span::operator=(const Span &span)
{
    if (this != &span)
    {
        this->maxNum = span.maxNum;
        this->totalNum = span.totalNum;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(unsigned int N)
{
    if (this->totalNum.size() < this->maxNum)
		this->totalNum.push_back(N);
	else
		throw AlreadyFullSpanException();
}

void Span::addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
    int distance = std::distance(begin, end);
	if (distance + this->totalNum.size() > this->maxNum)
	{
		this->totalNum.insert(this->totalNum.end(), begin, begin + (this->maxNum - this->totalNum.size()));
		throw AlreadyFullSpanException();
	}
	else
		this->totalNum.insert(this->totalNum.end(), begin, end);
}

unsigned int Span::shortestSpan()
{
	if (this->totalNum.size() < 2)
		throw EmptySpanException();

    unsigned int	shortest;
	std::vector<int>::iterator it;
	std::vector<int> tmp = this->totalNum;
	std::sort(tmp.begin(), tmp.end());
	for (it = tmp.begin(); it + 1 != tmp.end(); it++)
	{
		unsigned int diff = *(it + 1) - *it;
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int Span::longestSpan()
{
	if (this->totalNum.size() <= 1)
		throw EmptySpanException();

	int biggest = *std::max_element(this->totalNum.begin(), this->totalNum.end());
	int smallest = *std::min_element(this->totalNum.begin(), this->totalNum.end());
	return (std::abs(biggest - smallest));
}

const char *Span::AlreadyFullSpanException::what() const throw()
{
    return ("Span have enough numbers");
}

const char *Span::EmptySpanException::what() const throw()
{
    return ("Span is empty");
}