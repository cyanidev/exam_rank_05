#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	public:
		vect2(int x = 0, int y = 0);
		vect2(const vect2 &other);
		vect2 &operator=(const vect2 &other);
		~vect2();

		vect2 &operator++();
		vect2 operator++(int);
		vect2 &operator--();
		vect2 operator--(int);

		vect2 operator+(const vect2 &other) const;
		vect2 operator-(const vect2 &other) const;
		vect2 operator*(int scalar) const;
		vect2 &operator+=(const vect2 &other);
		vect2 &operator-=(const vect2 &other);
		vect2 &operator*=(int scalar);

		vect2 operator-() const;
		int &operator[](int index);
		const int &operator[](int index) const;

		bool operator==(const vect2 &other) const;
		bool operator!=(const vect2 &other) const;


	private:
		int _x;
		int _y;
		friend std::ostream &operator<<(std::ostream &out, const vect2 &other);
		friend vect2 operator*(int scalar, const vect2 &other);
};

#endif