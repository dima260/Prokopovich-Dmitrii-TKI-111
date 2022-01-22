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
void RandomDigits(int* array, const size_t size);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void UserInput(int* array, const size_t size);

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
void NumberGreaterNext(int* array, const size_t size);

/**
* \brief Метод,Найти номер последней пары соседних элементов с разными знаками.
* \param array Массив
* \param size Размер массива
* \param input введенное число 
**/
void MultiplyАllmultiplesThirdElement(int* array, const size_t size, double input);

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
int* array;
size_t size;
cin >> size;

array = new int[size]; //инициализировал в 74 строке
cout << "1 - Сгенерировать массив\n2 - Заполнить массив вручную\n";
int choice;
cin >> choice;

const auto filling = static_cast<Filling>(choice);
switch (filling)
{
case Filling::RANDOM:
RandomDigits(array, size);
Print(array, size);
break;
case Filling::USER:
UserInput(array, size);
Print(array, size);
break;
default:
cout << "Ошибка! Не выбран ни один из вариантов";
}

cout << "Найти сумму положительных элементов, значения которых состоят из двух цифр." << GetSum(array, size) << "\n\n";

cout << "Умножить все четные положительные элементы на последний элемент массива.:\n";

NumberGreaterNext(array, size);

cout << "Найти номер первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа.:\n";
double input;
cin >> input;
MultiplyАllmultiplesThirdElement(array, size, input);

if (array != nullptr)
{
delete[] array;
array = nullptr;
};

return 0;
}

void RandomDigits(int* array, const size_t size) {
random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> uniformIntDistribution(-50, 50);
    int* a = new int [size];
    for (int i = 0; i < size; i++) 
    {
      a[i] = uniformIntDistribution(gen);
}
}

void UserInput(int* array, const size_t size) {
for (size_t i = 0; i < size; i++) {
cout << "arr[" << i << "] = ";
cin >> array[i];
}
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

void NumberGreaterNext(int* array, const size_t size) {
for (size_t i = 0; i < size; i++) {
  if ((array[i]%2==0)&&(array[i]>=0)){
    array[i]=array[i]*array[size];
  }
}
for (size_t i = 0; i < size; i++){cout << array[i]<<endl;}
}


void MultiplyАllmultiplesThirdElement(int* array, const size_t size,double input) {
bool k = false;
for (size_t i = 1; i < size; i++) {
if ((array[i] * array[i - 1] < 0)&&(array[i] + array[i - 1]<input)) {
cout << "вот эта пара под номерами" << i << " " << i - 1 << " ";
k = true;
}
}
if (k == false) {
cout << "Таких пар нет ";
}
}