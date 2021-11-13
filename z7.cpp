//������������ 4, ������ 7. ���������: ��������� �.�.

/*���� ����������� ����� n. ��������� ���������� ���������� ���� 
����� � ����������, ����� ����� ����� � ������� � ������� i (������� 
���������� � �����, �.�. ������ ������ ����� ����� 0).*/

#include <iostream> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	long long int n, i, temp, dig = 0;

	cout << "������� ����� n: ";

	while (!(cin >> n) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "��������� ������, ���������� ��� ���)" << endl;
		cout << "\n������� ������ ������� NxM: ";
	}
	
	temp = n;

	while (temp > 0)
	{
		temp = temp / 10;
		dig++;
	}

	int* arr = new int[dig];

	temp = n;

	for (int i = 0; i < dig; i++)
	{
		arr[i] = temp % 10;
		temp /= 10;
	}

	cout << "\n������� ����� ������� i: ";
	while (!(cin >> i) || (cin.peek() != '\n', i < dig))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "��������� ������, ���������� ��� ���)" << endl;
		cout << "\n������� ������ ������� NxM: ";
	}
	

	cout << "\n\n���������� ���� � �����: " << dig << endl;
	cout << "\n� ������� ��� ������� - " << i << " ����� ����� - " << arr[i] << endl;

	delete [] arr;

	return 0;
}