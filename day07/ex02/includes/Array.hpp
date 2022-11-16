#include <string>

template <class T>
class Array
{
    public :
        Array() : _size(0), array(new T[0]) {};
        Array(unsigned int n) : _size(n), array(new T[n]) {};
        Array(const Array &arr)
        {
            this->_size = arr._size;
            this->array = new T[arr._size];
            for (unsigned int i = 0; i < arr._size; i++)
            {
                this->array[i] = arr.array[i];
            }
        }
        Array &operator=(const Array &arr)
        {
            if (this != &arr)
            {
                this->~Array();
                this->_size = arr._size;
                this->array = new T[arr._size];
                for (unsigned int i = 0; i < arr._size; i++)
                    this->array[i] = arr.array[i];
            }
            return *this;
        }
        ~Array()
        {
            delete []this->array;
        }

        T& operator[](unsigned int idx)
        {
            if (idx >= this->_size)
                throw OutOfIndex();
            return this->array[idx];
        }
        unsigned int size() const
        {
            return this->_size;
        }

        class OutOfIndex : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Out of index exception");
                }
        };

    private :
        unsigned int _size;
	    T* array;
};