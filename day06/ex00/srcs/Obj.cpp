#include "../includes/Obj.hpp"
#include <cmath>
#include <iomanip>

Obj::Obj(std::string str)
    : string(str)
{
    if (str.empty())
		throw Obj::InvalidInput();
	else if (str.size() == 1)
	{
		if (isdigit(*str.begin()))
		{
			this->intVal = static_cast<int>(strtol(str.c_str(), NULL, 10));
			this->type = Int;
		}
		else
		{
			this->charVal = *str.begin();
			this->type = Char;
		}
	}
	else
	{
		char *longRest;
		long longPart = strtol(str.c_str(), &longRest, 10);
		char *doubleRest;
		double doublePart = strtof(str.c_str(), &doubleRest);

		if (*longRest)
		{
			if (*doubleRest)
			{
				if (*doubleRest == 'f')
				{
					this->floatVal = static_cast<float>(doublePart);
					this->type = Float;
				}
				else
					throw Obj::InvalidInput();
			}
			else
			{
				this->doubleVal = doublePart;
				this->type = Double;
			}
		}
		else
		{
			if (longPart > std::numeric_limits<int>::max() || longPart < std::numeric_limits<int>::min())
				throw Obj::InvalidInput();
			else
			{
				this->intVal = static_cast<int>(longPart);
				this->type = Int;
			}
		}
	}
}

Obj::Obj(const Obj &obj)
    : string(obj.string)
{
    *this = obj;
}

Obj &Obj::operator=(const Obj &obj)
{
    *this = obj;
    return *this;
}
       
Obj::~Obj()
{
}

char Obj::toChar() const
{
    switch (this->type)
	{
	char c;
	case Char:
		return this->charVal;
	case Int:
		c = static_cast<char>(this->intVal);
		if (!isprint(c))
			throw Obj::NonDisplayable();
		else
			return c;
	case Float:
		c = static_cast<char>(this->floatVal);
		if (std::isnan(this->floatVal) || std::isinf(this->floatVal)
			|| this->floatVal > std::numeric_limits<char>::max() || this->floatVal < std::numeric_limits<char>::min())
			throw Obj::Impossible();
		else if (!std::isprint(c))
			throw Obj::NonDisplayable();
		else
			return c;
	case Double:
		c = static_cast<char>(this->doubleVal);
		if (std::isnan(this->doubleVal) || std::isinf(this->doubleVal)
			|| this->doubleVal > std::numeric_limits<char>::max() || this->doubleVal < std::numeric_limits<char>::min())
			throw Obj::Impossible();
		else if (!std::isprint(c))
			throw Obj::NonDisplayable();
		else
			return c;
	default:
		break;
	}
    return 0;
}
int Obj::toInt() const
{
    switch (this->type)
	{
	case Char:
		return static_cast<int>(this->charVal);
	case Int:
		return this->intVal;
	case Float:
		if (std::isnan(this->floatVal) || std::isinf(this->floatVal)
			|| this->floatVal > std::numeric_limits<int>::max() || this->floatVal < std::numeric_limits<int>::min())
			throw Obj::Impossible();
		else
			return static_cast<int>(this->floatVal);
	case Double:
		if (std::isnan(this->doubleVal) || std::isinf(this->doubleVal)
			|| this->doubleVal > std::numeric_limits<int>::max() || this->doubleVal < std::numeric_limits<int>::min())
			throw Obj::Impossible();
		else
			return static_cast<int>(this->doubleVal);
	default:
		break;
	}
    return 0;
}

float Obj::toFloat() const
{
    switch (this->type)
	{
	case Char:
		return static_cast<float>(this->charVal);
	case Int:
		return static_cast<float>(this->intVal);
	case Float:
		return this->floatVal;
	case Double:
		return static_cast<float>(this->doubleVal);
	default:
		break;
	}
    return 0;
}

double Obj::toDouble() const
{
    switch (this->type)
	{
	case Char:
		return static_cast<double>(this->charVal);
	case Int:
		return static_cast<double>(this->intVal);
	case Float:
		return static_cast<double>(this->floatVal);
	case Double:
		return this->doubleVal;
	default:
		break;
	}
    return 0;
}

const char* Obj::Impossible::what() const throw()
{
    return ("impossible");
}

const char* Obj::InvalidInput::what() const throw()
{
    return ("invalid input");
}

const char* Obj::NonDisplayable::what() const throw()
{
    return ("non displayable");
}

std::ostream& operator<<(std::ostream& o, const Obj& obj)
{
    //char
    o << "char: ";
    try
    {
        char ch = obj.toChar();
        o << "'" << ch << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    //int
    o << "int: ";
    try
    {
        int i = obj.toInt();
        o << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    //float
    o << "float: ";
    try
    {
        float f = obj.toFloat();
        double intPart;
		if (modf(f, &intPart) == 0)
			o.precision(1);
        o << std::fixed << f << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    //double
    o << "double: ";
    try
    {
        double d = obj.toDouble();
        double intPart;
		if (modf(d, &intPart) == 0)
			o.precision(1);
        o << std::fixed << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return o;
}