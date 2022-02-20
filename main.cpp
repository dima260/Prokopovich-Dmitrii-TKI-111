#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

/**
* \brief Заполнение массива случайными числами
* \param array Массив
* \param size Размер массива
**/
int* RandomDigits( const size_t size);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
int* UserInput( const size_t size);

/**
* \brief Вывод массива
* \param array Массив
* \param size Размер массива
**/
void Print(int* array, const size_t size);

/**
* \brief Сумма элементов массива, начения которых >0
* \param array Массив
* \param size Размер массива
* \param return Значение суммы
**/
int GetSum(int* array, const size_t size);

/**
* \brief Найти количество тех элементов, значения которых положительны и не превосходят заданного числа А.
* \param array Массив
* \param size Размер массива
**/
void multiplication_by_last_number(int* array, const size_t size);

/**
* \brief Метод,Найти номер последней пары соседних элементов с разными знаками.
* \param array Массив
* \param size Размер массива
* \param input введенное число 
**/
void search_pair(int* array, const size_t size,int input);

/**
* \brief Выбор заполнеия массива
**/
enum class Filling
{
RANDOM = 1,
USER = 2
};


/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
setlocale(LC_ALL, "ru");
srand(time(NULL));

cout << "Введите количество элементов массива: ";

size_t size;
int* Array = nullptr;
cin >> size;



cout <<static_cast<int>(Filling::RANDOM)<< "- Сгенерировать массив\n" <<static_cast<int>(Filling::USER)<<" - Заполнить массив вручную\n";
int choice;
cin >> choice;

const auto filling = static_cast<Filling>(choice);
switch (filling)
{
case Filling::RANDOM:
Array = RandomDigits(size);
Print(Array, size);
break;
case Filling::USER:
Array = UserInput(size);
Print(Array, size);
break;
default:
cout << "Ошибка! Не выбран ни один из вариантов";
}

cout << "Найти сумму положительных элементов, значения которых состоят из двух цифр." << GetSum(Array, size) << "\n\n";

cout << "Умножить все четные положительные элементы на последний элемент массива.:\n";

multiplication_by_last_number(Array, size);

cout << "Найти номер первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа.:\n";
double input;
cin >> input;
search_pair(Array, size, input);

if (Array != nullptr)
{
delete[] Array;
Array = nullptr;
};

return 0;
}

int* RandomDigits(const size_t size) {
		random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> uniformIntDistribution(-50, 50);
    int* a = new int [size];
    for (int i = 0; i < size; i++) 
    {
      a[i] = uniformIntDistribution(gen);
}
	return a;
}

int* UserInput(const size_t size) {
	int* a = new int [size];
	for (size_t i = 0; i < size; i++) {
		cout << "arr[" << i << "] = ";
		cin >> a[i];
	}
	return a;
}

void Print(int* array, const size_t size) {
cout << "array[" << size << "]" << "= {";
for (size_t i = 0; i < size - 1; i++) {
cout << array[i] << ";" << setw(3);
}
cout << array[size - 1] << "}\n\n";
}

int GetSum(int* array, const size_t size) {
int sum = 0;
for (size_t i = 0; i < size; i++) {
if ((array[i] >= 0) && (array[i] > 9) && (array[i] < 100)) { //первая скобка проверяет что число больше нуля вторая и третья скобки проверяют что число имеет два числа внутри
sum += array[i];
}
}
return sum;
}

void multiplication_by_last_number(int* array, const size_t size) {
for (size_t i = 0; i < size; i++) {
  if ( ( array[i] % 2 == 0 ) && ( array[i]>=0 ) ){
    array[i]=array[i]*array[size-1];
  }
}
Print(array, size);
}


void search_pair(int* array, const size_t size,int input) {
bool flag = false;
for (size_t i = 1; i < size; i++) {
if ((array[i] * array[i - 1] < 0)&&(array[i] + array[i - 1]<input)) {
cout << "вот эта пара под номерами" << i << " " << i - 1 << " ";
flag= true;
}
}
if (flag == false) {
cout << "Таких пар нет ";
}
}