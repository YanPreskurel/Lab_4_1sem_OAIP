//������������ 4, ������ 5. ���������: ��������� �.�.

/*�������� �������� a[i][j] � ������� ������� �������� � ������� 
a[k][g], ��� i-1<k<i+1, j-1<g<j+1, (k,g) �� ����� (i,j).
�������� ����������� ������� ���� ����� ������� ���� �� �������,
������ ������� ������� ���������� ��� ������� �������������� ��������� 
������� ���������������� �������� �������� �������. ��������� ��������� 
����������� �������� ������������ �������.*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int N, M, k, g, N2, M2;

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

	double** arr = new double *[N]; //��������� ������� �������

	for (int i = 0; i < N; i++)
	{
		arr[i] = new double[M];
	}

	for (int i = 0; i < N; i++)  //���������� ������� �������
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = (rand() % 10) * 0.2;
		}
	}

	for (int i = 0; i < N; i++) //����� ������� �������
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}

	double** arr2 = new double* [N];   //��������� ������� �������

	for (int i = 0; i < N; i++)
	{
		arr2[i] = new double[M];
	}

	arr2[0][0] = (arr[0][1] + arr[1][0]) / 2;
	arr2[0][M-1] = (arr[0][M - 2] + arr[1][M - 1]) / 2;
	arr2[N - 1][0] = (arr[N - 2][0] + arr[N - 1][1]) / 2;
	arr2[N - 1][M - 1] = (arr[N - 2][M - 1] + arr[N - 1][M - 2]) / 2;

	for (int j = 1; j < M - 1; j++)
	{
		k = 0;
		g = j;
		arr2[0][j] = (arr[k][g - 1] + arr[k][g + 1] + arr[k + 1][g]) / 3;
		
		//================================================================================================

		k = N - 1;
		g = j;
		arr2[N - 1][j] = (arr[k][g - 1] + arr[k][g + 1] + arr[k - 1][g]) / 3;
	}

	for (int i = 1; i < N - 1; i++)
	{
		k = i;
		g = 0;

		arr2[i][0] = (arr[k - 1][g] + arr[k + 1][g] + arr[k][g + 1]) / 3;
		
		//================================================================================================
		k = i;
		g = M - 1;

		arr2[i][M - 1] = (arr[k - 1][g] + arr[k + 1][g] + arr[k][g - 1]) / 3;
	}

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			k = i;
			g = j;

			arr2[i][j] = (arr[k][g - 1] + arr[k][g + 1] + arr[k - 1][g] + arr[k + 1][g]) / 4;
		}
	}

	cout << "\n" << "\n";

	for (int i = 0; i < N; i++) //����� ��������� �������
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr2[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}

	for (int i = 0; i < N; i++) // �������� ������� �������
	{
		delete[] arr[i];
	}
	delete[] arr;

	for (int i = 0; i < N; i++) // �������� ������� �������
	{
		delete[] arr2[i];
	}
	delete[] arr2;

	return 0;
}