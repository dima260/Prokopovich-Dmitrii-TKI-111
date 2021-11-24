#include <iostream>

using namespace std;

/**
 * \brief Вычисляет сумму чисел.
 * \param value1 число введённое пользователем.
 * \param value2 число введённое пользователем.
 * \return сумму чисел.
 */
double sum(double value1, double value2);

/**
 * \brief Вычисляет разность чисел.
 * \param value1 число введённое пользователем.
 * \param value2 число введённое пользователем.
 * \return разность чисел.
 */
double difference(double value1, double value2);

/**
 * \brief Вычисляет сред арифетическое чисел.
 * \param value1 число введённое пользователем.
 * \param value2 число введённое пользователем.
 * \return сред арифетическое чисел.
 */
double quotient(double value1, double value2);

/**
* \brief выбор заполнения массива
*/
enum path
{
	first = 1,
	second = 2,
	trird = 3
};



int main()
{
	setlocale(LC_ALL, "Russian");

	int value1, value2, choice;
	cout << "Введите а и b ";
	cin >> value1 >> value2;
	cout << "Выберите какую операцию вы хотите выполнить:\n1 - сложение\n2 - разность\n3 - срднее арифетическое\n";
	cin >> choice;
	const auto filling = static_cast<path>(choice);
	switch (filling) {
	case path::first:
	{
		double rezult = sum(value1, value2);
		cout<<rezult;
		break;
	}
	case path::second:
	{
		double rezult = difference( value1,  value2);
		cout<<rezult;
		break;
	}
	case path::trird:{
		double rezult = quotient(value1, value2);
		cout<<rezult;
		break;
	}
	default:
		cout << "Некоректный ввод.";
		break;
	}
}

double sum(double value1, double value2)
{
	return value1+value2;
	
}

double difference(double value1, double value2){
	return value1-value2;
}

double quotient(double value1, double value2){
	return (value1+value2)/2;
}