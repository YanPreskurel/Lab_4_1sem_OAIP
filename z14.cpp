//Лабораторная 4, задача 14. Выполнена: Прескурел Я.Ю.

/*На вход подаётся поле для игры в "сапёр" размером n*m 
символов, где символ '.' означает пустое место, а символ '*' - бомбу. 
Требуется дополнить это поле числами , как в оригинальной игре. Выделение 
памяти через функции языка С.*/

#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

        int N, j = 0, k, g, count = 0, res = 0, M;

        cout << "Введите размер матрицы NxM: ";
        
        while (!(cin >> N) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
            cout << "\nВведите размер матрицы NxM:";
        }
        while (!(cin >> M) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Произошла ошибка, попробуйте ещё раз)" << endl;
            cout << "\nВведите размер матрицы NxM:";
        }

        double** matr = (double**)calloc(N, sizeof(double*));      

        for (int i = 0; i < N; i++)
        {
            matr[i] = (double*)calloc(M, sizeof(double));
        }

        char** mine = (char**)calloc(N, sizeof(char*));

        for (int i = 0; i < N; i++)
        {
            mine[i] = (char*)calloc(M, sizeof(char));
        }

        for (int i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                matr[i][j] = rand() % 2;
                cout << setw(2) << matr[i][j];
            }
            cout << '\n';
        }

        cout << "\n\n\n";

        for (int i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (matr[i][j] == 1)
                    mine[i][j] = '*';
                else
                    mine[i][j] = '.';
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                k = i - 1;
                g = j - 1;

                for (k; (k < i + 2) && (k < N); k++)
                {
                    for (g; (g < j + 2) && (g < M); g++)
                    {
                        if (k < 0)
                            k++;
                        if (g < 0)
                            g++;

                        if ((k == i) && (g == j) && (g + 1 != N))
                            g++;

                        if ((matr[i][j] < matr[k][g]) && (matr[i][j] == 0))
                        {
                            count++;
                        }
                    }
                    g = j - 1;
                }

                switch (count)
                {
                case 1:
                    mine[i][j] = '1';
                    break;
                case 2:
                    mine[i][j] = '2';
                    break;
                case 3:
                    mine[i][j] = '3';
                    break;
                case 4:
                    mine[i][j] = '4';
                    break;
                case 5:
                    mine[i][j] = '5';
                    break;
                case 6:
                    mine[i][j] = '6';
                    break;
                case 7:
                    mine[i][j] = '7';
                    break;
                case 8:
                    mine[i][j] = '8';
                    break;
                }
                count = 0;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << setw(2) << mine[i][j];
            }
            cout << "\n";
        }

        for (int i = 0; i < N; i++)
        {
            free(matr[i]);
        }       
        free(matr);

        for (int i = 0; i < N; i++)
        {
            free(mine[i]);
        }  
        free(mine);

    return 0;
}