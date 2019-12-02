#pragma once
#include <iostream>
#include <exception>
using namespace std;
class fraction
{
private:
	long chisl;
	long znamen;
	//сделать сеттер с 2мя параметрами чтобы передавать в него кроме числаа еще и необходим ли сокращать(по умолчанию тру, а в конструкторе сделать фолс)
	//сделать свой класс эксептион который будет выкидывать исключения из моего класса ,а класс эксепшн будет выкидывать исключения не из моего класса
	//при перемножении лонгов результат лонг лонг
	//сделать отдельный метод для проверки не вышли ли значения числ и знамен за пределы лонг(т.к. лонг*лонг=лонг лонг)(спросить)возможно через класс out_of_ranges
	void correctFraction();//работает с исключениями и сокращает дробь
	fraction reverseFraction() const;//меняет местами числитель и знаменатель
	void setChislPrivate(long = 0, bool = true);
	fraction(long long, long long);
public:
	fraction(long = 0, long = 1);
	fraction(const fraction&);//конструктор копирования
	~fraction();
	void setChisl(long);
	void setZnamen(long);
	void setFraction(long, long);
	long getZnamen() const;
	long getChisl() const;
	double getFraction() const;

	fraction& operator =(const fraction&);
	fraction& operator =(const long);
	fraction operator - () const;//изменение знака

	//franctio& если изменяется сам обьект
	//fraction если изменения записываются в новый объект
	fraction operator +(const fraction&) const;//если дробь с дробью
	fraction operator -(const fraction&) const;
	fraction operator *(const fraction&) const;
	fraction operator /(const fraction&) const;
	//friend операторы если левый операнд не является объектом класса

	fraction& operator++();//префиксный
	fraction operator++(const int);//постфиксный
	fraction& operator--();
	fraction operator--(const int);
	fraction& operator+=(const fraction&);
	fraction& operator-=(const fraction&);
	fraction& operator*=(const fraction&);
	fraction& operator/=(const fraction&);


	bool operator ==(const fraction&) const;
	bool operator !=(const fraction&) const;
	bool operator >(const fraction&) const;
	bool operator >=(const fraction&) const;
	bool operator <(const fraction&) const;
	bool operator <=(const fraction&) const;

	friend ostream& operator <<(ostream&, const fraction&);
	friend istream& operator>>(istream&, fraction&);
	operator double() const;
};

class fraction_exception :public exception
{
public:
	fraction_exception(const char* const message) :exception(message) {};
	fraction_exception(const fraction_exception& mistake) :exception(mistake) {};
};
