#include <iostream>
#include <locale>
#include <math.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

void doTransfer (int number, int p) {
 	int arr[100], n = -1;	
	while(true){
		if (number < p) {
	 		arr[++n] = number;
	 		break;
		}
		arr[++n] = number % p;  	 			 
		number /= p;
	 	
	}
	
	for (int i = n; i >= 0 ; i--)
	cout << arr[i];		
}
 
void doTransfer_R( int number, int p ) {
   if ( number >= p ) {
      doTransfer_R( number / p, p );
   }
   cout << number % p;
   return;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "russian");
	
	int number, p;
	cout << "Введите число : "; cin >> number; system ("cls"); int N = number;
	cout << "Введите p-ичную систему (p < 10), в которую хотите перевести число " << number << " : ";  cin >> p; 
	system ("cls");
	
	cout << "\nОбычная функция:\n";
	cout << "Число (" << N << ") в " << p << "-ичной системе счисления = ";
	doTransfer(number, p);
	
	cout << "\n\nРекурсивная функция:\n";
	cout << "Число (" << N << ") в " << p << "-ичной системе счисления = ";
    doTransfer_R(number, p);
	
	cout << "\n\n\n";	
	system ("pause");
	return 0;
}
