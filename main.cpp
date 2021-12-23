#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Функция для расчета y
* \param x Аргумент x
* \return Значение y
*/
double GetY(const double x);

/**
* \brief Ввод значения х в программу
* \return Конечное значение
*/
int main()
{
setlocale(LC_ALL, "Russian");

const double step = 0.1, limit = 2.0;
double x = 0;


while (x <= limit)
{
cout << " переменная x: " << x << " |" << " переменная функция: " << GetY(x) << endl;
x += step;
}
}

double GetY(const double x)
{
return x - (cos(x)-exp(-(pow(x,2)/2)+x-1));
}
