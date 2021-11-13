//Лабораторная 4, задача 9. Выполнена: Прескурел Я.Ю.

/*В качестве входных данных поступают две целочисленные 
матрицы A и B, которые имеют размер N и соответственно. Требуется найти 
произведение матриц A*B. Выделение памяти через функции языка С.*/

#include <iostream> 
#include <stdlib.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

		int N;

		cout << "Введите размеры матриц: ";

		while (!(cin >> N) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
			cout << "\nВведите размер матрицы N: ";
		}

		cout << "\nВведите элементы первой матрицы: " << endl;

		int** arr = (int**)calloc(N, sizeof(int*));

		for (int i = 0; i < N; i++)
		{
			arr[i] = (int*)calloc(N, sizeof(int));

			for (int j = 0; j < N; j++)
			{
				while (!(cin >> arr[i][j]) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
					cout << "\nВведите элементы первой матрицы: ";
				}
			}
		}

		cout << "\nМатрица №1" << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << "\n\n";
		}

		cout << "\nВведите элементы второй матрицы: " << endl;

		int** arr2 = (int**)calloc(N, sizeof(int*));

		for (int i = 0; i < N; i++)
		{
			arr2[i] = (int*)calloc(N, sizeof(int));

			for (int j = 0; j < N; j++) 
			{
				while (!(cin >> arr2[i][j]) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
					cout << "\nВведите элементы второй матрицы: ";
				}
			}
		}

		cout << "\nМатрица №2" << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr2[i][j] << "\t";
			}
			cout << "\n\n";
		}

		int** result = (int**)calloc(N, sizeof(int*));

		for (int i = 0; i < N; i++)
		{
			result[i] = (int*)calloc(N, sizeof(int));

			for (int j = 0; j < N; j++)
			{
				result[i][j] = 0;

				for (int r = 0; r < N; r++)
				{
					result[i][j] += arr[i][r] * arr2[r][j];
				}	
			}
		}

		cout << "\nИсходная матрица";
		cout << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << result[i][j] << "\t";
			}
			cout << "\n\n";
		}

		for (int i = 0; i < N; i++)
		{
			free(arr[i]);
		}
		free(arr);
		
		for (int i = 0; i < N; i++)
		{
			free(arr2[i]);
		}
		free(arr2);

		for (int i = 0; i < N; i++)
		{
			free(result[i]);
		}
		free(result);

    return 0;
}