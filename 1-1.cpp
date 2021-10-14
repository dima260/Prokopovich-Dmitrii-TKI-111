#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

//using namespace std;

/** 
 * \brief Это функция выполняет выполняет вычисление по заданной формуле
 *\param x параметр x
 *\param y параметр y
 *\return значение функции
 */
double getA (const double x, const double y, const double z);
/**
 * \brief Это функция выполняет вычисление по заданной формуле
 * \param x параметр х
 * \param y параметр y
 * \param z параметр z
 * \return 0  значение функции
 */
double getB(const double x, const double y, const double z);

/**
 * \brief Точка входа в программу
 * \return 0  в случае успеха
 */
int main()
{
  const double x = 1.7;
  const double y = 1.08;
  const double z = 0.5;
  
  const double a = getA(x, y, z);
  const double b = getB(x, y, z);


 cout << setprecision(9) << "x = " << x << " y = " << y << " z = " << z 
        << " a = " << a << " b = " << b  << "\n";
    return 0;
}



double getA(const double x, const double y, const double z)
{
  return (sin(x)/sqrt((pow(y,2)+(pow(sin(x),2)))))-(pow(x,2))*y*z;
}

double getB(const double x, const double y, const double z)
{
 return (exp(-z*x))*(sqrt(x+1))+(exp(-y*x));
}