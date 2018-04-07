#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <locale>

using namespace std;

struct Spis {
	int info;
	Spis *next, *prev;
} *Head, *Tail, *HeadPlus, *TailPlus, *HeadMinus, *TailMinus;

void AddInSpis (Spis *&Head, Spis *&Tail, int number) {
	Spis *temp = new Spis;
	temp->info = number;
	temp->next = NULL;
	if (Head == NULL)         
		Head = Tail = temp;
	else {
		Tail->next = temp;
		Tail = temp;
	}
}

void ShowSpis (Spis *&Head) {
	Spis *temp = Head;
	while (temp != NULL){
		cout <<"\t" << temp->info << endl;
		temp = temp->next;
	}
}

void DeleteSpis (Spis *&Head) {
	while (Head != NULL){
		Spis *temp = Head->next;		
		delete Head;
		Head = temp;
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	
	int number;	
	
	while (true) {
		system ("cls");
		puts ("1 - создать список.");
		puts ("2 - добавить в список.");
		puts ("3 - просмотреть список.");
		puts ("4 - очистить память.");
		puts ("q - выйти из программы.");
		
		switch (getch()) {	
			case '1':
				if (Head != NULL) {
					system ("cls");
					cout << "Перед созданием нового списка нужно очистить память!";
					getch();
					break;
				}
				
			case '2':
				system ("cls");
				cout << "Введите число, которое хотите добавить в список : ";
				cin >> number;
				AddInSpis(Head, Tail, number);
				if (number >= 0)
					AddInSpis(HeadPlus, TailPlus, number);
				else
					AddInSpis(HeadMinus, TailMinus, number);
			break;
			
			case '3':
				system("cls");
				puts ("Показать список :");
				puts ("1 - со всеми числами.");
				puts ("2 - с положительныими числами.");
				puts ("3 - с отрицательными числами.");
				switch (getch()) {
					case '1' :
						system("cls");
						if (Head == NULL) {
							cout << "Список пуст! Проверьте данные.";
							getch ();
							break;
						}
						else	
							cout << "Список со всеми числами :\n"; 
						ShowSpis(Head);
					break;
					
					case '2' :
						system("cls");	
						if (HeadPlus == NULL) {
							cout << "Список пуст! Проверьте данные.";
							getch ();
							break;
						}
						else	
							cout << "Список с положительными числами :\n"; 
						ShowSpis(HeadPlus);
					break;
					
					case '3' :
						system("cls");	
						if (HeadMinus == NULL) {
							cout << "Список пуст! Проверьте данные.";
							getch ();
							break;
						}
						else	
							cout << "Список с отрицательными числами :\n"; 
						ShowSpis(HeadMinus);
					break;
				}	
				getch();
			break;
			
			case '4':
				system ("cls");
				DeleteSpis(Head);
				DeleteSpis(HeadPlus);
				DeleteSpis(HeadMinus);
				cout << "Память очищена!";
				getch();
			break;
			
			case 'q' :
				if (Head != NULL){
					DeleteSpis(Head);
					DeleteSpis(HeadPlus);
					DeleteSpis(HeadMinus);
			}
			return 0;	 
		}
			
	}
	return 0;
}

