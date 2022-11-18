#include <exception>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <iostream>

class Span
{
    public :
        Span(unsigned int N);
        Span(const Span &span);
        Span &operator=(const Span &span);
        ~Span();

        void addNumber(unsigned int N);
        void addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        class AlreadyFullSpanException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class EmptySpanException : public std::exception
        {
            virtual const char *what() const throw();
        };

    private :
        unsigned int maxNum;
        std::vector<int> totalNum;
};