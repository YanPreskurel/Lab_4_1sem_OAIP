//Лабораторная 4, задача 7. Выполнена: Прескурел Я.Ю.

/*Дано натуральное число n. Требуется подсчитать количество цифр 
числа и определить, какая цифра стоит в разряде с номером i (разряды 
нумеруются с конца, т.е. разряд единиц имеет номер 0).*/

#include <iostream> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	long long int n, i, temp, dig = 0;

	cout << "Введите число n: ";

	while (!(cin >> n) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
		cout << "\nВведите размер матрицы NxM: ";
	}
	
	temp = n;

	while (temp > 0)
	{
		temp = temp / 10;
		dig++;
	}

	int* arr = new int[dig];

	temp = n;

	for (int i = 0; i < dig; i++)
	{
		arr[i] = temp % 10;
		temp /= 10;
	}

	cout << "\nВведите номер разряда i: ";
	while (!(cin >> i) || (cin.peek() != '\n', i < dig))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
		cout << "\nВведите размер матрицы NxM: ";
	}
	

	cout << "\n\nКоличество цифр в числе: " << dig << endl;
	cout << "\nВ разряде под номером - " << i << " стоит цифра - " << arr[i] << endl;

	delete [] arr;

	return 0;
}