#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void main()
{
	setlocale(LC_ALL, "Russian");
	int n; //������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {3,5,8};
	FillRand(arr, n);
	Print(arr, n);
	int value; //����������� ��������
	cout << "������� ����������� ��������: "; cin >> value;
	//1)������� �������� ������ ������� ������� (�� 1 ������� ������):
	int* buffer = new int[n + 1]{};
	//2)�������� ��� �������� � ����� ������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������:
	delete[] arr;
	//4)��������� �������� ������ ��������:
	arr = buffer;
	//5)��������� �������� � ����� �������:
	arr[n] = value;
	//6)����� ����, ��� � ������� ��������� �������,
	//���������� ��� ��������� ������������� �� 1:
	n++;
	buffer[0] = 1024;
	Print(arr, n);
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{ 
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}