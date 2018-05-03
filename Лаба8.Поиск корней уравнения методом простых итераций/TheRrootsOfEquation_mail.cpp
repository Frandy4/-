#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <locale>
#include <iomanip>

using namespace std;

double f (double x) {                                     //изначальна€ функци€
	return pow(x, 3) - 6*x +8;
}
 
double fi (double x) {                                    //преобразованна€ дл€ метода простых итераций
	return (pow(x, 3) + 8) / 6;
}

double FindRoot(double x, double eps) {                  //поиск корней 
	double w;
    do {
    	w=x;
        x = fi(x);
       } while(fabs(x - w) >eps);
	return x;
}
//----------------------------------------
void CheckIntervalOnRoot () {                             //поиск интервалов, где могут находитс€ корни и поиск этих корней, использу€ функцию FindRoot
	int kol = 1;
	double x0, x1, eps, h, a , b;
	cout << "¬ведите a = "; cin >> a;
	cout << "¬ведите b = "; cin >> b;
	cout << "¬ведите eps = "; cin >> eps;
	cout << "¬ведите h = "; cin >> h;
	system("cls");
	cout << "   орни уравнени€ x^3 - 6*x + 8:\n";
	for (double x = a; x < b; x+=h)
		if ( f(x)*f(x+h) < 0) 
			cout << kol++ << ")  " << FindRoot(x+h/2, eps) << endl;
	getch();
}

//--------------------------------------
int main() {
	setlocale(LC_ALL, "russian");
	CheckIntervalOnRoot ();
	return 0;
}













