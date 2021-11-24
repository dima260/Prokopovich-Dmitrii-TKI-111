#include <iostream>

using namespace std;

/**
 * \brief Вычисляет площадь прямоугольника.
 * \param length Длина стороны прямоугольника.
 * \param width Ширина стороны прямоугольника.
 * \return Площадь прямоугольника.
 */
double Square(const double length, const double width);

/**
 * \brief Вычисляет периметр прямоугольника.
 * \param length Длина стороны прямоугольника.
 * \param width Ширина стороны прямоугольника.
 * \return Периметр прямоугольника.
 */
double Perimeter(const double length, const double width);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    cout << "Введите длины сторон прямоугольника\n";
    double a,b;
    cin >> a >> b;

    const auto square = Square(a, b);
    cout << "Площадь квадрата равна " << square << "\n";

    const auto perimeter = Perimeter(a, b);
    cout << "Периметр прямоугольника " << perimeter << endl;
}

double Square(const double length, const double width)
{
    return length * width;
}

double Perimeter(const double length, const double width)
{
    return 2 * (length + width);
}