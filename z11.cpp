//Лабораторная 4, задача 11. Выполнена: Прескурел Я.Ю.

/*Дан трёхмерный динамический массив размером n^3 целых 
неотрицательных чисел. Необходимо определить диагональ с наибольшей 
суммой чисел. Для обхода диагоналей нельзя использовать вложенные циклы.*/

#include <iostream> 
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    int x, y, z, d1 = 0, d2 = 0, d3 = 0, d4 = 0, N, k, max, diagonal[4];

    cout << "Введите размер массива N: ";

    while (!(cin >> N) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
        cout << "\nВведите размер массива N: ";
    }

    k = N;

    int*** arr = new int** [N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new int *[N];

        for (int j = 0; j < N; j++) 
        {
            arr[i][j] = new int[N];
        }
    }

    for (int z = 0; z < N; z++)
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                arr[z][x][y] = rand() % 11;
            }
        }
    }
     
    for (int z = 0; z < N; z++)
    {
        cout << "\nСлой " << z << "\n\n";
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                cout << arr[z][x][y] << '\t';
            }
            cout << "\n\n";
        }
    }

    for (int i = 0; i < N; i++)
    {
        d1 += arr[i][i][i];
    }
    for (int i = 0; i < N; i++, k--)
    {
        d2 += arr[i][i][k - 1];
        d3 += arr[i][k - 1][i];
        d4 += arr[i][k - 1][k - 1];
    }

    diagonal[0] = d1;
    diagonal[1] = d2;
    diagonal[2] = d3;
    diagonal[3] = d4;

    max = diagonal[0];

    for (int k = 1; k < 4; k++)
    {
        if (max < diagonal[k])
        {
            max = diagonal[k];
        }
    }
    
    cout << "\n\nДиагональ с наибольшей суммой чисел = " << max << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            delete arr[i][j];
        }
    }
    delete[] arr;

    return 0;
}