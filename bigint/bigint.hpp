#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <string>

class bigint
{
	public:
		bigint(unsigned int n = 0);
		bigint(const bigint &other);
		bigint &operator=(const bigint &other);
		~bigint();
		bigint(const std::string &s) : _big(s) {} 

		bigint operator+(const bigint &other) const;
		bigint &operator+=(const bigint &other);

		bigint &operator++();
		bigint operator++(int);

		bigint operator<<(unsigned int amount) const;
		bigint operator<<(const bigint &other) const;
		bigint &operator<<=(unsigned int amount) ;
		bigint &operator>>=(const bigint &other);

		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;

	private:
		std::string _big;
		friend std::ostream &operator<<(std::ostream &out, const bigint &other);
};

#endif