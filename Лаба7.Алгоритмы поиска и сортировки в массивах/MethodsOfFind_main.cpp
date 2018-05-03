#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>

using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void _Swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void _ShowArray(int *array, int kol) {
	for (int i = 0; i < kol; i++) 
		cout << array[i] << " ";
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void _selectionSort (int *array, int kol) {
	int min, temp;
	for (int i = 0; i < kol - 1; i++) {
		min = i;
		for (int j = i + 1; j < kol; j++) 
			if (array[j] < array [min]) 
				min = j;
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
	cout << "\nОтсортированный массив: ";
	_ShowArray(array, kol);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void _QuickShort (int *array, int a0, int b0) {
	int temp = array[b0];
	int a = a0;
	int b = b0;

	while(a <= b) {
    	while (array[a] < temp)
    		a++;
    	while(array[b] > temp)
    		b--;
		if (a <= b) {
			_Swap(array[a], array[b]);
			a++;
			b--;
		}
    }
    if(b > a0)
    	_QuickShort (array, a0, b);
    if(a < b0)
		_QuickShort (array, a, b0);
		
	
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void _search (int *array, int kol, int value) {
	for (int i = 0; i < kol; i++)
		if (array[i] == value) {
			cout << "\nПозиция искомого числа (" << value << ") = " << i + 1 << endl;
			break;
		}
}	
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
int _bsearch (int *array, int kol, int value) {
	int begin = 0;
	int end = kol - 1;
	
	while ( begin <= end ) {
		int mid = (begin + end)/2;
		if (value == array[mid]) {
			cout << "\nПозиция искомого числа (" << value << ") = " << mid + 1 << endl;
			return 0;
		}
		else if (value > array[mid])
				  begin = mid + 1;
			 else 
			 	  end = mid - 1;
	}
	return 1;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int kol, *array, value;
	cout << "Количество элементов массива : ";
	cin >> kol;
	
	array = new int [kol];
	cout << "Элементы массива :\n";
	for (int i = 0; i < kol; i++) {
		cout << "[" << i << "] = ";
		cin >> array[i];
	}
	
	while (true) {
		system ("cls");
		puts ("1 - просмотреть массив.");
		puts ("2 - сортировка прямого выбора.");
		puts ("3 - сортировка QuickShort.");
		puts ("4 - линейный поиск.");
		puts ("5 - бинарный поиск.");
		puts ("0 - Выход.");
		switch (getch()) {
			case '1':
				system("cls");
				cout << "Исходный массив: ";
				_ShowArray(array, kol);
				getch();
			break;
			
			case '2' :
				system("cls");
				cout << "Исходный массив: ";
				_ShowArray(array, kol);
				_selectionSort (array, kol);
				
				getch();
			break;
			
			case '3' :
				system("cls");
				cout << "Исходный массив: ";
				_ShowArray(array, kol);
				_QuickShort (array, 0, kol - 1);
				cout << "\nОтсортированный массив: ";
				_ShowArray(array, kol);
				getch();
			break;
			
			case '4' :
				system("cls");
				cout << "Введите число,позицию которого хотите узнать: ";
				cin >> value;
				cout << "\nМассив: ";
				_ShowArray(array, kol);
				_search(array, kol, value);
				getch();
			break;
		
			case '5' :
				system("cls");
				cout << "Введите число,позицию которого хотите узнать: ";
				cin >> value;
				_QuickShort (array, 0, kol - 1);
				cout << "\nОтсортированный массив: ";
				_ShowArray(array, kol);
				_bsearch(array, kol, value);
				getch();
			break;
		
			case '0' :
				return 0;

		}
 	}
	delete []array;
	getch();
	return 0;
}
