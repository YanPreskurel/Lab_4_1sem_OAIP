//Лабораторная 4, задача 12. Выполнена: Прескурел Я.Ю.

/*Написать функцию которая будет удалять дубликаты элементов 
из массива. Входные параметры: массив, длинна массива. Выходные 
параметры: новый массив, новый размер.*/

#include <iostream>
#include <algorithm>

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N, x, i = 0, dif = 0, k = 1;

	cout << "Введите длину массива: ";

	while (!(cin >> N) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
		cout << "\nВведите длину массива: ";
	}

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nВведите " << i << " элемент массива ";

		while (!(cin >> arr[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
			cout << "\nВведите " << i << " элемент массива ";
		}
	}

	cout << "\n\n";

	qsort(arr, N, sizeof(int), compare);

	int* arr2 = new int[N];

	arr2[0] = arr[0];

	for (int i = 0; i < N; i++)
	{
		if (arr[i + 1] != arr[i])
		{
			arr2[k] = arr[i + 1];
			k++;
		}
		else
		{
			dif++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < N - dif; i++)
	{
		cout << arr2[i] << "\t";
	}

	cout << "\n\n";

	delete[] arr;
	delete[] arr2;
	
	return 0;
}