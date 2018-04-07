#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <locale>

using namespace std;
 
struct Spis {
	int info;
	Spis *next, *prev;
} *Head, *Tail, *HeadPlus, *HeadMinus; 

void CreateSpis (Spis *&Head, Spis *&Tail, int number) {}
	Spis *temp = new Spis;
	temp->info = number;
	temp->next = temp->prev = NULL;
	Head = Tail = temp;
}

void AddInSpis (Spis *&Head, Spis *&Tail, int number) {
	Spis *temp = new Spis;
	temp->info = number;
	switch (getch()) {  		  			//в начало
		case '1':
			temp->prev = NULL;
			temp->next = Head;
			Head->prev = temp;
			Head = temp;
		break;
		
		case '2':		                	//в конец  
			temp->prev = Tail;
			temp->next = NULL;
			Tail->next = temp;
			Tail = temp;
		break;
	}
}

void AddInSpis2 (Spis *&Head, Spis *&Tail, int number) {
	Spis *temp = new Spis;
	temp->info = number;
	temp->next = Head;
	Head = temp;
}

void ShowSpis(Spis *&Head, Spis *&Tail) {
	switch (getch()) {	
		case '1': {
			system ("cls");
			Spis *temp = Head;
			cout << "----С начала----\n";
			while (temp != NULL) {
				cout << "\t" << temp->info << endl;
				temp = temp->next;
			}
			getch();
		break;
		}
		case '2': {
			system ("cls");
			Spis *temp = Tail;
			cout << "----С конца----\n";
			while (temp != NULL) {
				cout << "\t" << temp->info << endl;
				temp = temp->prev;
			}
		 	getch();
		break;	
		}
	}
}

void ShowSpis2(Spis *&Head) {
	Spis *temp = Head;
	while (temp != NULL) {
		cout << "\t" << temp->info << endl;
		temp = temp->next;
	}
	getch();
}

void CreateOrAddSpis2 (Spis *&HeadMinus, Spis *&TailMinus, int number) {
	if (HeadMinus != NULL)
		AddInSpis2(HeadMinus, TailMinus, number);
	else
		CreateSpis(HeadMinus, TailMinus, number);
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
			case '1' :                     // создать список.
				system ("cls");
				if (Head != NULL) {
					system ("cls");
					cout << "Перед созданием нового списка нужно очистить память!";
					getch();
					break;
				}
				cout << "Введите число, которое хотите добавить: ";
				cin >> number;
				CreateSpis(Head, Tail, number);
				if (number < 0)
					CreateSpis(HeadMinus, TailMinus, number);
				else
					CreateSpis(HeadPlus, TailPlus, number);
			break;
			
			case '2' :						//добавить в список.
				system("cls");
				cout << "Введите число, которое хотите добавить: ";
				cin >> number;
				system("cls");
				cout << "Куда добавить число " << number << " ?\n1 - в начало списка.\n2 - в конец списка.\n" << endl;
				AddInSpis(*&Head, *&Tail, number);
				if (number < 0) 
					CreateOrAddSpis2 (HeadMinus, TailMinus, number);
				else 
					CreateOrAddSpis2 (HeadPlus, TailPlus, number);	
				
				
			break;
			
			case '3' :						//просмотреть список.
				system("cls");
				if (Head == NULL) {
					cout << "Списки пусты!";
					getch();
					break;
				}
				cout << "    Какой список вы хотите просмотреть?\n1 - Основной.\n2 - С положительными числами.\n3 - С отрицательными числами.\n";
				switch (getch()) {
					case '1':
						system ("cls");
						cout << "   Просмотр с :\n1 - Начала списка.\n2 - Конца списка.\n";
						ShowSpis(Head, Tail);
					break;
					case '2':
						system ("cls");
						cout << "Список положительных чисел:\n";
						ShowSpis2(HeadPlus);
					break;
					case '3':
						system ("cls");
						cout << "Список отрицательных чисел:\n";
						ShowSpis2(HeadMinus);
					break;
				}
			break;
			
			case '4' :						//удалить списки.
				system("cls");
				DeleteSpis(Head);
				DeleteSpis(HeadPlus);
				DeleteSpis(HeadMinus);
				cout << "Память очищена.";
				getch();
			break;
			
			case 'q' :						//выйти из программы.
				system("cls");
				if(Head != NULL) {
					DeleteSpis(Head);
					DeleteSpis(HeadPlus);
					DeleteSpis(HeadMinus);	
				}
		 	return 0;		
		}		
	}
}
















