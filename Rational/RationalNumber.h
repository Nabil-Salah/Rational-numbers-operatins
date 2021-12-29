#include <string>
#include <sstream>
#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

class RationalNumber
{
public:
	RationalNumber(int numeratorc = 1, int denominatorc = 1) {
		simply(numeratorc, denominatorc);
	};
	~RationalNumber() {};
	void operator+=(RationalNumber r) {
		int c = denominator;
		denominator += r.denominator;
		numerator = (numerator * r.denominator) + (r.numerator * c);
		simply(numerator, denominator);
	}
	void operator-=(RationalNumber r) {
		int c = denominator;
		denominator *= r.denominator;
		numerator = (numerator * r.denominator) - (r.numerator * c);
		simply(numerator, denominator);
	}
	void operator*=(RationalNumber r) {
		numerator *= r.numerator;
		denominator *= r.denominator;
		simply(numerator, denominator);
	}
	void operator/=(RationalNumber r) {
		numerator *= r.denominator;
		denominator *= r.numerator;
	}
	std::string toString() {
		std::ostringstream out;
		if(denominator == 1)
			out << numerator;
		else
			out << numerator << "/" << denominator;
		return out.str();
	}
	double toDouble() {
		return numerator / denominator;
	}
	void simply(int numeratorc = 1, int denominatorc = 1) {
		if (denominatorc != 0 || numeratorc != 0) {
			int divide = gCDRe(numeratorc, denominatorc);
			numerator = numeratorc / divide;
			denominator = denominatorc / divide;
		}
		else if (numeratorc == 0) {
			numerator = 0;
			denominator = 0;
		}
		else
		{
			throw std::invalid_argument("denominator can't be zero");
		}
	}
	// the recursive Method of gcd finding
	int gCDRe(int a, int b)
	{
		//my base case that involves finding a=0 or b=0 after last reminder
		if (b == 0)
		{
			return a;//return the gcd
		}
		else
		{
			return gCDRe(b, a % b);
		}
	}
	void setNum(int x) {
		numerator = x;
	}
	void setden(int x) {
		denominator = x;
	}
private:
	int numerator;
	int denominator;
};

#endif // RATIONALNUMBER_H
