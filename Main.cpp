//Шаблон
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

//Задача 3. Структура треугольника 
struct triangle {
	double a = 0;
	double b = 0;
	double c = 0;
};



template <typename T>
void fill_arr(T arr, const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
template <typename T>
void show_arr(T arr, const int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//добавление нового элемента в конец массива
template <typename T>
void append(T*& arr, int length, T val) {
	T* tmp = new T[length + 1];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[]arr;
	tmp[length] = val;
	arr = tmp;
}


template <typename T>
void memory(T* &ptr, int length);

template <typename T>
T* pos_arr_concat(T arr1[], const int length1, T arr2[], const int length2, int &var);

//Задача 3. Площадь треугольника
double tr_area(triangle& T) {
	double halfp = (T.a + T.b + T.c) / 2.0;   //полупериметр
	return sqrt(halfp * (halfp - T.a)* (halfp - T.b)* (halfp - T.c));
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Задача 1. Выделение памяти
	/*cout << "Задача 1.\nВведите длинну массива: ";
	cin >> n;
	int* pArr1 = nullptr;
	try {
		memory(pArr1, n);
		fill_arr(pArr1, n, 1, 11);
		cout << "Итоговый массив:\n";
		show_arr(pArr1, n);
		cout << '\n';
		delete[]pArr1;
	}
	catch (const out_of_range& ex) {
		cout << "Ошибка:" << ex.what() << "\n\n";
	}*/

	//Задача 2.Массив положительных элементов
	/*cout << "Задача 2.\n";
	const int size1 = 10;
	const int size2 = 7;
	int arr1[size1];
	int arr2[size2];
	fill_arr(arr1, size1, -11, 12);
	fill_arr(arr2, size2, -10, 11);
	cout << "Массив 1:\n";
	show_arr(arr1, size1);
	cout << "Массив 2:\n";
	show_arr(arr2, size2);

	int* result_arr = pos_arr_concat(arr1, size1, arr2, size2, n);
	cout << "Итоговый массив:\n";
	show_arr(result_arr, n);
	cout << "\n\n";
	delete[]result_arr;*/

	//Задача 3. Площадь произвольного треугольника
	/*cout << "Задача 3.\nСтороны треугольника: ";
	triangle ABC{ 5.5, 9.1, 10.0 };
	cout << ABC.a << ", " << ABC.b << ", " << ABC.c << '\n';
	cout << "Площадь треугольника = " << tr_area(ABC) << "\n\n";*/

	
	return 0;
}

//Задача 1. Выделение памяти
template <typename T>
void memory(T* &ptr, int length) {
	if (length < 0)
		throw out_of_range("длина массива не может быть отрицательной");
	ptr = new T[length];
}

//Задача 2.
template <typename T>
T* pos_arr_concat(T arr1[], const int length1, T arr2[], const int length2, int& var) {
	int tmp_size = 0;
	T* tmp_arr = new T[0];
	
	for(int i =0 ; i< length1; i++)
		if (arr1[i] > 0) {
			append(tmp_arr, tmp_size, arr1[i]);
			tmp_size++;
		}
	for (int i = 0; i < length2; i++)
		if (arr2[i] > 0) {
			append(tmp_arr, tmp_size, arr2[i]);
			tmp_size++;
		}
	var = tmp_size;
	return tmp_arr;
}