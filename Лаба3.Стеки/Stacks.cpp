#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <locale>

using namespace std;

struct Stack {
	int info;
	Stack *Next;
}*Head = NULL, *HeadMinus = NULL, *HeadPlus = NULL;

void AddInStack (Stack *&Head, int number) {
	Stack *temp = new Stack;
	temp->info = number;
	temp->Next = Head;
	Head = temp;
}

void ShowStack (Stack *&Head) {
	Stack *temp = Head;
	while (temp != NULL){
		cout <<"\t" << temp->info << endl;
		temp = temp->Next;
	}
}

void DeleteStack (Stack *&Head) {
	while (Head != NULL){
		Stack *temp = Head->Next;		
		delete Head;
		Head = temp;
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	
	int number;	
	
	while (true) {
		system ("cls");
		puts ("1 - создать стек.");
		puts ("2 - добавить в стек.");
		puts ("3 - просмотреть стек.");
		puts ("4 - очистить память.");
		puts ("q - выйти из программы.");
		
		switch (getch()) {
			case '1':
				if (Head != NULL) {
					system ("cls");
					cout << "Перед созданием нового стека нужно очистить память!";
					getch();
					break;
				}
				
			case '2':
				system ("cls");
				cout << "Введите число, которое хотите добавить в стек : ";
				cin >> number;
				AddInStack(Head, number);
				if (number >= 0)
					AddInStack(HeadPlus, number);
				else
					AddInStack(HeadMinus, number);
			break;
			
			case '3':
				system("cls");
				puts ("Показать стек :");
				puts ("1 - со всеми числами.");
				puts ("2 - с положительныими числами.");
				puts ("3 - с отрицательными числами.");
				switch (getch()) {
					case '1' :
						system("cls");
						if (Head == NULL) {
							cout << "Стек пуст! Проверьте данные.";
							getch ();
							break;
						}
						else	
							cout << "Стек со всеми числами :\n"; 
						ShowStack(Head);
					break;
					
					case '2' :
						system("cls");	
						if (HeadPlus == NULL) {
							cout << "Стек пуст! Проверьте данные.";
							getch ();
							break;
						}
						else	
							cout << "Стек с положительными числами :\n"; 
						ShowStack(HeadPlus);
					break;
					
					case '3' :
						system("cls");	
						if (HeadMinus == NULL) {
							cout << "Стек пуст! Проверьте данные.";
							getch ();
							break;
						}
						else	
							cout << "Стек с отрицательными числами :\n"; 
						ShowStack(HeadMinus);
					break;
				}	
				getch();
			break;
			
			case '4':
				system ("cls");
				DeleteStack(Head);
				DeleteStack(HeadPlus);
				DeleteStack(HeadMinus);
				cout << "Память очищена!";
				getch();
			break;	 
			
			case 'q' :
				if (Head != NULL) {
					DeleteStack(Head);
					DeleteStack(HeadPlus);
					DeleteStack(HeadMinus);
			   	}
			return 0;
		}
			
	}
	return 0;
}






