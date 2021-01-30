#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void main()
{
	setlocale(LC_ALL, "Russian");
	int n; //Размер массива
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {3,5,8};
	FillRand(arr, n);
	Print(arr, n);
	int value; //Добавляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;
	//1)Создаем буферный массив нужного размера (на 1 элемент больше):
	int* buffer = new int[n + 1]{};
	//2)Копируем все значения в новый массив:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив:
	delete[] arr;
	//4)Подменяем исходный массив буферным:
	arr = buffer;
	//5)Добавляем значение в конец массива:
	arr[n] = value;
	//6)После того, как в массиве добавился элемент,
	//количество его элементов увеличивается на 1:
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