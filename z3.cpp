//Лабораторная 4, задача 3. Выполнена: Прескурел Я.Ю.

/*Вариант 3.
    Память для массива выделить динамически. Выполнить в соответствии с
	номером варианта индивидуальное задание и вывести на экран исходные 
	данные и полученный результат.
		3.  Дана вещественная матрица размером NxM. Переставляя ее строки 
		и столбцы, добиться того, чтобы наибольший элемент (один из них) 
		оказался в верхнем левом углу.*/

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int x, y;

	int N = rand() % 3 + 2;
	int M = rand() % 3 + 2;

	double** arr = new double *[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new double[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = (rand() % 100) * 0.2;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}

	double max = arr[0][0];
	x = y = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j]; //Находим максимальный элемент и запоминаем его позицию
				x = i;
				y = j;
			}
		}
	}

	cout << "\nmax = " << max << " x = " << x << " y = " << y << endl;

	for (int j = 0; j < M; j++)
	{
		swap(arr[x][j], arr[0][j]); //Меняем строку с индексом x на строку с индексом 0
	}
	for (int i = 0; i < N; i++)
	{
		swap(arr[i][y], arr[i][0]); //Меняем столбец с индексом y на столбец с индексом 0
	}
	
	

	cout << "\n\n\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete [] arr;

	system("pause");
	return 0;
}
