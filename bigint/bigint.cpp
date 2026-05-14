#include "bigint.hpp"
 
bigint::bigint(unsigned int n)
{
	std::ostringstream oss;
	oss << n;
	_big = oss.str();
}
 
 
bigint::bigint(const bigint &other)
{
	_big = other._big;
}
 
bigint &bigint::operator=(const bigint &other)
{
	if (this != &other)
		_big = other._big;
	return *this;
}
 
bigint::~bigint()
{}
 
 
bigint bigint::operator+(const bigint &other) const
{
	std::string result;
	int llevo = 0;
	int i = _big.size() - 1;
	int j = other._big.size() - 1; // era _big.size(), debe ser other._big.size()
 
	while (i >= 0 || j >= 0 || llevo)
	{
		int sum = llevo;
		if (i >= 0)
			sum += _big[i--] - '0';
		if (j >= 0)
			sum += other._big[j--] - '0';
		llevo = sum / 10;
		result = char(sum % 10 + '0') + result;
	}
	return bigint(result);
}
 
bigint &bigint::operator+=(const bigint &other)
{
	*this = *this + other; // no concatenar strings, usar operator+
	return *this;
}
 
bigint &bigint::operator++()
{
	*this = *this + bigint(1); // no _big + bigint, usar *this
	return *this;
}
 
bigint bigint::operator++(int)
{
	bigint old = *this;
	*this = *this + bigint(1);
	return old; // era return *this
}
 
bigint bigint::operator<<(unsigned int amount) const // unsigend → unsigned
{
	bigint result = *this;
	result._big += std::string(amount, '0');
	return result;
}
 
bigint bigint::operator<<(const bigint &other) const
{
	size_t n = 0;
	for (size_t i = 0; i < other._big.size(); i++)
		n = n * 10 + (other._big[i] - '0');
	return *this << (unsigned int)n;
}
 
bigint &bigint::operator<<=(unsigned int amount) // unsigend → unsigned
{
	_big += std::string(amount, '0');
	return *this;
}
 
bigint &bigint::operator>>=(const bigint &other)
{
	size_t n = 0;
	for (size_t i = 0; i < other._big.size(); i++) // comas → puntos y coma
		n = n * 10 + (other._big[i] - '0'); // faltaba ;
	if (n >= _big.size())
		_big = "0";
	else
		_big = _big.substr(0, _big.size() - n); // _bigg → _big
	return *this;
}
 
bool bigint::operator<(const bigint &other) const
{
	if (_big.size() != other._big.size())
		return _big.size() < other._big.size();
	return _big < other._big;
}
 
bool bigint::operator>(const bigint &other) const
{
	if (_big.size() != other._big.size())
		return _big.size() > other._big.size();
	return _big > other._big;
}
 
bool bigint::operator<=(const bigint &other) const
{
	return (*this < other || *this == other); // lógica incorrecta antes
}
 
bool bigint::operator>=(const bigint &other) const
{
	return (*this > other || *this == other); // lógica incorrecta antes
}
 
bool bigint::operator==(const bigint &other) const
{
	return _big == other._big; // estaba incompleto
}
 
bool bigint::operator!=(const bigint &other) const
{
	return !(*this == other); // estaba incompleto
}
 
std::ostream &operator<<(std::ostream &out, const bigint &other)
{
	out << other._big; // era >> en vez de <<
	return out; // faltaba return
}