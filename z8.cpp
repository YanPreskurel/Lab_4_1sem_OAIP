//������������ 4, ������ 8. ���������: ��������� �.�.

/*�������� ������ ��� ��������, ������� ��������� � ������� 
����� ����������� � ������������ ���������� (�� ������� ��). 
���������� ��� �������� � ������� ���������. ���� ����� ������� �������� 
������� ����� ������� ����� ��������� ����, �� ������� ��� ������� 
�������� �� ������� (c ����������� ������� ���������� ��������� ���������).*/

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int N, dif, k = 0, min[2], max[2];

	cout << "������� ���������� ��������� �������: ";

	while (!(cin >> N) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "��������� ������, ���������� ��� ���)" << endl;
		cout << "\n������� ������ ������� NxM: ";
	}	

	int* arr = new int[N];

	cout << "\n��������� ������:\n";
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
			min[1] = i; // ������������ ������� ������������ �������� �������
		}
		if (arr[i] > max[0])
		{
			max[0] = arr[i];
			max[1] = i; // ������������ ������� ������������� �������� �������
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

	cout << "\n\n���������� ����� = " << dif << "\n\n";
	cout << "�������� ������:\n";

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