//������������ 4, ������ 9. ���������: ��������� �.�.

/*� �������� ������� ������ ��������� ��� ������������� 
������� A � B, ������� ����� ������ N � ��������������. ��������� ����� 
������������ ������ A*B. ��������� ������ ����� ������� ����� �.*/

#include <iostream> 
#include <stdlib.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

		int N;

		cout << "������� ������� ������: ";

		while (!(cin >> N) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "��������� ������, ���������� ��� ���)" << endl;
			cout << "\n������� ������ ������� N: ";
		}

		cout << "\n������� �������� ������ �������: " << endl;

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
					cout << "��������� ������, ���������� ��� ���)" << endl;
					cout << "\n������� �������� ������ �������: ";
				}
			}
		}

		cout << "\n������� �1" << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << "\n\n";
		}

		cout << "\n������� �������� ������ �������: " << endl;

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
					cout << "��������� ������, ���������� ��� ���)" << endl;
					cout << "\n������� �������� ������ �������: ";
				}
			}
		}

		cout << "\n������� �2" << endl;

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

		cout << "\n�������� �������";
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