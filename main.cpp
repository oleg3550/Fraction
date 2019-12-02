#include <iostream>
#include "fraction.h"
#include <exception>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	//вводим С ПОМОЩЬЮ friend оператора >>
	fraction* a = nullptr;
	try
	{
		a = new fraction;
		cin >> *a;
	}
	catch (fraction_exception & e)
	{
		delete a;
		a = nullptr;
		cout << e.what() << endl;
	}
	catch (ios_base::failure)
	{
		delete a;
		a = nullptr;
		cout << "Error: data type overflow" << endl;
		cin.clear();
	}
	catch (exception & e)
	{
		delete a;
		a = nullptr;
		cout << e.what() << endl;
	}
	catch (...)
	{
		//
	}
	//вводим БЕЗ friend оператора
	long x, y;
	fraction* b = nullptr;
	try
	{
		b = new fraction();
		cin >> x >> y;
		b->setChisl(x);
		b->setZnamen(y);
	}
	catch (fraction_exception & e)
	{
		delete b;
		b = nullptr;
		cout << e.what() << endl;
	}
	catch (ios_base::failure)
	{
		delete b;
		b = nullptr;
		cout << "Error: data type overflow" << endl;
		cin.clear();
	}
	catch (...)
	{
		//
	}
	if (b != nullptr && a != nullptr)//если была ошибка ввода то память не выделялась
	{
		cout << *a << endl << *b << endl;
		cout << "Сумма двух дробей: " << *a + *b << endl;
		try {
			cout << "Произведение двух дробей: " << *a * *b << endl;
		}
		catch (fraction_exception & e)
		{
			cout << e.what() << endl;
		}
		catch (exception & e)
		{
			cout << e.what() << endl;
		}
		try {
			fraction c = *a / (*b);
			cout << "Деление двух дробей: " << c << endl;
		}
		catch (fraction_exception & e)
		{
			cout << e.what() << endl;
		}
		catch (exception & e)
		{
			cout << e.what() << endl;
		}
		cout << (*a > * b) << endl;
		cout << "a+=b: " << (*a += *b) << endl;
		delete b;
		delete a;
	}
}
