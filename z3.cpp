//������������ 4, ������ 3. ���������: ��������� �.�.

/*������� 3.
    ������ ��� ������� �������� �����������. ��������� � ������������ �
	������� �������� �������������� ������� � ������� �� ����� �������� 
	������ � ���������� ���������.
		3.  ���� ������������ ������� �������� NxM. ����������� �� ������ 
		� �������, �������� ����, ����� ���������� ������� (���� �� ���) 
		�������� � ������� ����� ����.*/

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
				max = arr[i][j]; //������� ������������ ������� � ���������� ��� �������
				x = i;
				y = j;
			}
		}
	}

	cout << "\nmax = " << max << " x = " << x << " y = " << y << endl;

	for (int j = 0; j < M; j++)
	{
		swap(arr[x][j], arr[0][j]); //������ ������ � �������� x �� ������ � �������� 0
	}
	for (int i = 0; i < N; i++)
	{
		swap(arr[i][y], arr[i][0]); //������ ������� � �������� y �� ������� � �������� 0
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
