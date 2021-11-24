#define _USE_MATH_DEFINES // for C++

#include <cmath>
#include <iostream>

using namespace std;

/**
 *   \brief Метод расчёта  энергии нужно затратить, 	чтобы расплавить кусок льда массой m, взятый при 		температуре -10°С.
 *   \param mass Масса в килограммах (кг).
 *   \return Значение энергии в Джоулях (Дж).
 */
double GetEnergy(const double mass);

int main()
{
    double mass;
    cout << "Enter mass\n";
    cin >> mass;

    const auto energy = GetEnergy(mass);

    cout << "Energy is " << energy;
    return 0;
}

double GetEnergy(const double mass){
		return 4.2 * pow( 10 , 3 ) * mass * ( 0 - 10 ) + 3.4 * pow( 10 , 5 ) * mass;
}