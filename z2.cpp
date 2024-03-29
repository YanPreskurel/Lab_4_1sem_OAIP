//������������ 4, ������ 2. ���������: ��������� �.�.

/*������� 3.
	���������������� ��� ���������� ����������� ��������� ������ 
	����� ����� �������� NxM. ��������� � ������������ � ������� 
	�������� �������������� ������� � ������� �� ����� �������� 
	������ � ���������� ���������.
	  3. ���������� ����� ������������� ���������, 
	    ������������� ���� �������� ��������� ������� */

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	const int N = 4;
	const int M = 4;

	int arr[N][M], sum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 11 - 5;
			cout << setw(2) << arr[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}

	for (int i = 0, g = 1; i < N - 1; i++, g++)
	{
		for (int j = 0; j < M - g; j++)
		{
			if (arr[i][j] < 0)
			{
				sum += arr[i][j];
			}
		}
	}
	cout << "\n����� (������������� ��������� �������, ������� ���� �������� ���������) = " << sum << endl;

	return 0;
}