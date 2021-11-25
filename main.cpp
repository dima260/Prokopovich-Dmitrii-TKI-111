#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES
using namespace std;

/**
* \brief Это функция выполняет вычисление функции при x < 1.2
* \param a параметр а
* \param x параметр х
* \return значение функции
*/
double getY1(const double a, double x);

/**
* \brief Это функция выполняет вычисление функции при x >= 1.2
* \param a параметр а
* \param x параметр х
* \return значение функции
*/
double getY2(const double a, double x);

/**
* \brief Точка входа в программу
* \return 0 в случае успеха
*/
int main()
{
double x;
double y;
const double a = 2;
cout << "Введите значение х ";
cin >> x;
if (x > a)
{
y = getY1( a, x);
cout << "y = " << y << "\n";
}
else
{
y = getY2( a, x);
cout << "y = "<< y << "\n";
}
return 0;
}
double getY1(const double a, double x)
{
return tan(x)+M_PI/3;
}
double getY2(const double a, double x)
{
return sin(x)*a;
}