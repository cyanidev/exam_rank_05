#include "vect2.hpp"

vect2::vect2(int x, int y)
{
	_x = x;
	_y = y;
}

vect2::vect2(const vect2 &other)
{
	_x = other._x;
	_y = other._y;
}

vect2 &vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

vect2::~vect2()
{}

vect2 &vect2::operator++()
{
	*this = *this + vect2(1, 1);
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 old = *this;
	*this = *this + vect2(1, 1);
	return old;
}

vect2 &vect2::operator--()
{
	*this = *this - vect2(1, 1);
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 old = *this;
	*this = *this - vect2(1, 1);
	return old;
}

vect2 vect2::operator+(const vect2 &other) const
{
	vect2 result(_x + other._x, _y + other._y);
	return result;
}

vect2 vect2::operator-(const vect2 &other) const
{
	vect2 result(_x - other._x, _y - other._y);
	return result;
}

vect2 vect2::operator*(int scalar) const
{
	vect2 result(_x * scalar, _y * scalar);
	return result;
}

vect2 &vect2::operator+=(const vect2 &other)
{
	_x = _x + other._x;
	_y = _y + other._y;

	return *this;
}

vect2 &vect2::operator-=(const vect2 &other)
{
	_x = _x - other._x;
	_y = _y - other._y;

	return *this;
}

vect2 &vect2::operator*=(int scalar)
{
	_x = _x * scalar;
	_y = _y * scalar;

	return *this;
}

vect2 vect2::operator-() const
{
	vect2 result(_x * -1, _y * -1);
	return result;
}

int &vect2::operator[](int index)
{
	if (index == 0)
		return _x;
	return _y;
}

const int &vect2::operator[](int index) const
{
	if (index == 0)
		return _x;
	return _y;

}

bool vect2::operator==(const vect2 &other) const
{
	if (_x == other._x && _y == other._y)
		return true;
	return false;
}

bool vect2::operator!=(const vect2 &other) const
{
	if (_x != other._x || _y != other._y)
		return true;
	return false;
}


std::ostream &operator<<(std::ostream &out, const vect2 &other)
{
	out << "{" << other._x << ", " << other._y << "}";
	return out;
}

vect2 operator*(int scalar, const vect2 &other)
{
	return vect2(scalar * other._x, scalar * other._y);
}
