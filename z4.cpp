//������������ 4, ������ 4. ���������: ��������� �.�.

/*������� ������� ���������� ��������� ���������, ���� �� ������ ������ 
���� ��������� � ���� �������. �������� �������� a[i][j] � ������� ������� 
�������� a[k][g], ��� i-1<k<i+1, j-1<g<j+1, (k,g) �� ����� (i,j). 
���������� ���������� ��������� ��������� �������� �������.*/

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N, M, k, g, min = 0;

	cout << "������� ������ ������� NxM: ";

	while (!(cin >> N) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "��������� ������, ���������� ��� ���)" << endl;
		cout << "\n������� ������ ������� NxM: ";
	}
	while (!(cin >> M) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "��������� ������, ���������� ��� ���)" << endl;
		cout << "\n������� ������ ������� NxM: ";
	}

	cout << "\n\n";

	int** arr = new int* [N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 10;
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

	if (arr[0][0] < arr[0][1] && arr[0][0] < arr[1][0])
	{
		min++;
	}
	if (arr[0][M - 1] < arr[0][M - 2] && arr[0][M - 1] < arr[1][M - 1])
	{
		min++;                                                     // ���������� ��������� ��������� � ������ �������  
	}
	if (arr[N - 1][0] < arr[N - 2][0] && arr[N - 1][0] < arr[N - 1][1])
	{
		min++;
	}
	if (arr[N-1][M-1] < arr[N - 2][M-1] && arr[N-1][M-1] < arr[N-1][M - 2])
	{
		min++;
	}

	for (int j = 1; j < M - 1; j++)
	{
		k = 0;
		g = j;
		if (arr[0][j] < arr[k][g - 1] && arr[0][j] < arr[k][g + 1] && arr[0][j] < arr[k + 1][g])  
		{
			min++;           // ���������� ��������� ��������� � ������� ������� ������� 
		}
		//================================================================================================
		k = N - 1;
		g = j;
		if (arr[N - 1][j] < arr[k][g - 1] && arr[N - 1][j] < arr[k][g + 1] && arr[N - 1][j] < arr[k - 1][g])
		{
			min++;          // ���������� ��������� ��������� � ������ ������� ������� 
		}
	}
	for (int i = 1; i < N - 1; i++)
	{
		k = i;
		g = 0;

		if (arr[i][0] < arr[k - 1][g] && arr[i][0] < arr[k + 1][g] && arr[i][0] < arr[k][g + 1])
		{
			min++;          // ���������� ��������� ��������� � ����� ������� ������� 
		}
		//================================================================================================
		k = i;
		g = M - 1;

		if (arr[i][M - 1] < arr[k - 1][g] && arr[i][M - 1] < arr[k + 1][g] && arr[i][M - 1] < arr[k][g - 1])
		{
			min++;          // ���������� ��������� ��������� � ������ ������� ������� 
		}
	}

	for(int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			k = i;
			g = j;

			if (arr[i][j] < arr[k][g - 1] && arr[i][j] < arr[k][g + 1] && arr[i][j] < arr[k - 1][g] && arr[i][j] < arr[k + 1][g])
			{
				min++;    // ���������� ��������� ��������� � ����������� ����� ������� 
			}
		}
	}

	cout << "\n��������� �������� = " << min << endl;
	
	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete [] arr;

	return 0;
}