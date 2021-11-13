//Лабораторная 4, задача 8. Выполнена: Прескурел Я.Ю.

/*Заменить нулями все элементы, которые находятся в ячейках 
между минимальным и максимальным элементами (не включая их). 
Изначально все элементы в массиве различные. Если после данного действия 
большая часть массива будет содержать нули, то удалить все нулевые 
элементы из массива (c сохранением порядка следования остальных элементов).*/

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int N, dif, k = 0, min[2], max[2];

	cout << "Введите количество элементов массива: ";

	while (!(cin >> N) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
		cout << "\nВведите размер матрицы NxM: ";
	}	

	int* arr = new int[N];

	cout << "\nПервичный массив:\n";
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 1000 + 1;
		cout << arr[i] << "\t";
	}

	
	min[0] = max[0] = arr[0];
	min[1] = max[1] = 0;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] < min[0])
		{
			min[0] = arr[i];
			min[1] = i; // присваивание индекса минимального элемента массива
		}
		if (arr[i] > max[0])
		{
			max[0] = arr[i];
			max[1] = i; // присваивание индекса максимального элемента массива
		}
	}

	if (min[1] < max[1])
	{
		for (int i = min[1] + 1; i < max[1]; i++)
		{
			arr[i] = 0;
		}
	}
	else
	{
		for (int i = max[1] + 1; i < min[1]; i++)
		{
			arr[i] = 0;
		}
	}

	dif = fabs(max[1] - min[1]) - 1;

	cout << "\n\nКоличество нулей = " << dif << "\n\n";
	cout << "Исходный массив:\n";

	int* arr2 = new int[N - dif];

	if (dif > N / 2)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i] != 0)
			{
				arr2[k] = arr[i];
				cout << arr2[k] << "\t";
				k++;
			}
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << '\t';
		}
	}

	delete [] arr;
	delete [] arr2;

	return 0;
}