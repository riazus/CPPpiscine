#include <iostream>

template <typename T>
void iter(T *arr, size_t length, void (*f)(const T&))
{
    for (size_t i = 0; i < length; i++)
		(*f)(arr[i]);
}

template <typename T>
void print_normal(const T& a)
{
	std::cout << a << std::endl;
}