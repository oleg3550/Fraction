#include "fraction.h"
#include <iostream>

using namespace std;

long NOD(long a, long b)
{
	a = abs(a);
	b = abs(b);
	return b ? NOD(b, a % b) : a;//через рекурсивное деление
}

fraction::fraction(long long achisl, long long aznamen)
{
	if (abs(achisl) > LONG_MAX)
		throw fraction_exception("Error: the numerator can't be more than LONG_MAX");
	if (abs(aznamen) > LONG_MAX)
		throw fraction_exception("Error: the denominator can't be more than LONG_MAX");
	setFraction(achisl, aznamen);
}
fraction::fraction(long achisl, long aznamen)
{
	setFraction(achisl, aznamen);
}
fraction::fraction(const fraction& f) : fraction(f.chisl, f.znamen) {}

void fraction::correctFraction()
{
	if (znamen == 0)
		throw fraction_exception("Error: you try to enter the denominator 0.");
	if (chisl > LONG_MAX)
		throw fraction_exception("Error: the numerator can't be more than MAX_LONG");
	if (znamen > LONG_MAX)
		throw fraction_exception("Error: the denominator can't be more than MAX_LONG");
	long c = NOD(chisl, znamen);
	chisl /= c;
	znamen /= c;
	if (znamen < 0)
	{
		chisl = -chisl;
		znamen = -znamen;
	}
	else if (chisl == 0)
		znamen = 1;
}
fraction fraction::reverseFraction() const
{
	if (znamen == 0)
		throw fraction_exception("Error: you are trying to divide by 0.");
	return fraction(znamen, chisl);
}
fraction::~fraction() { /*cout << "Память удалена." << endl; */ }

fraction fraction::operator-() const//унарный минус
{
	return fraction(-chisl, znamen);
}
fraction::operator double() const
{
	return (double)chisl / znamen;
}

fraction fraction::operator+(const fraction& f) const
{
	return fraction(chisl * f.znamen + znamen * f.chisl, znamen * f.znamen);
}
fraction fraction::operator-(const fraction& f) const//бинарный минус
{
	return (*this + (-f));
}
fraction fraction::operator*(const fraction& f) const
{
	return fraction((long long)chisl * f.chisl, (long long)znamen * f.znamen);
}
fraction fraction::operator/(const fraction& f) const
{
	return *this * f.reverseFraction();
}

bool fraction::operator==(const fraction& f) const
{
	return (chisl == f.chisl && znamen == f.znamen);
}
bool fraction::operator>(const fraction& f) const
{
	if ((*this - f).chisl > 0)//можно записать this->operator+(-f)
		return true;
	return false;
}
bool fraction::operator>=(const fraction& p) const
{
	return (*this > p || *this == p);
}
bool fraction::operator!=(const fraction& f) const
{
	return !(*this == f);
}
bool fraction::operator<(const fraction& f) const
{
	return (!(*this >= f));
}
bool fraction::operator<=(const fraction& p) const
{
	return (!(*this > p));
}


ostream& operator << (ostream& o, const fraction& f)
{
	return o << (double)f.chisl / f.znamen;
}
istream& operator>>(istream& i, fraction& f)
{
	i >> f.chisl >> f.znamen;
	i.exceptions(istream::failbit | istream::badbit);
	return i;
}

fraction& fraction::operator+=(const fraction& f)
{
	*this = *this + f;
	return *this;
}
fraction& fraction::operator-=(const fraction& f)
{
	*this += -f;
	return *this;
}
fraction& fraction::operator*=(const fraction& p)
{
	*this = *this * p;
	correctFraction();
	return *this;
}
fraction& fraction::operator/=(const fraction& p)
{
	*this *= p.reverseFraction();
	return *this;
}



double fraction::getFraction() const
{
	return (double)*this;
}
long fraction::getChisl() const
{
	return chisl;
}
long fraction::getZnamen() const
{
	return znamen;
}
void fraction::setChislPrivate(long achisl, bool divided)
{
	chisl = achisl;
	if (divided)
		correctFraction();
}
void fraction::setChisl(long achisl)
{
	setChislPrivate(achisl);
}
void fraction::setZnamen(long aznamen)
{
	znamen = aznamen;
	correctFraction();
}
void fraction::setFraction(long achisl, long aznamen)
{
	setChislPrivate(achisl, false);
	setZnamen(aznamen);
}


fraction& fraction::operator++()
{
	chisl += znamen;
	return *this;
}
fraction fraction::operator++(int a)
{
	fraction p = *this;
	chisl += znamen;
	return p;
}
fraction& fraction::operator--()
{
	chisl -= znamen;
	return *this;
}
fraction fraction::operator--(const int a)
{

	fraction p = *this;
	chisl -= znamen;
	return p;
}

fraction& fraction::operator=(const fraction& p)
{
	chisl = p.chisl;
	znamen = p.znamen;
	return *this;
}
fraction& fraction::operator=(const long a)
{
	chisl = a;
	znamen = 1;
	return *this;
}
