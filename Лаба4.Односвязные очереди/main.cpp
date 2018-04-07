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
		puts ("1 - ������� ������.");
		puts ("2 - �������� � ������.");
		puts ("3 - ����������� ������.");
		puts ("4 - �������� ������.");
		puts ("q - ����� �� ���������.");
		
		switch (getch()) {	
			case '1':
				if (Head != NULL) {
					system ("cls");
					cout << "����� ��������� ������ ������ ����� �������� ������!";
					getch();
					break;
				}
				
			case '2':
				system ("cls");
				cout << "������� �����, ������� ������ �������� � ������ : ";
				cin >> number;
				AddInSpis(Head, Tail, number);
				if (number >= 0)
					AddInSpis(HeadPlus, TailPlus, number);
				else
					AddInSpis(HeadMinus, TailMinus, number);
			break;
			
			case '3':
				system("cls");
				puts ("�������� ������ :");
				puts ("1 - �� ����� �������.");
				puts ("2 - � ��������������� �������.");
				puts ("3 - � �������������� �������.");
				switch (getch()) {
					case '1' :
						system("cls");
						if (Head == NULL) {
							cout << "������ ����! ��������� ������.";
							getch ();
							break;
						}
						else	
							cout << "������ �� ����� ������� :\n"; 
						ShowSpis(Head);
					break;
					
					case '2' :
						system("cls");	
						if (HeadPlus == NULL) {
							cout << "������ ����! ��������� ������.";
							getch ();
							break;
						}
						else	
							cout << "������ � �������������� ������� :\n"; 
						ShowSpis(HeadPlus);
					break;
					
					case '3' :
						system("cls");	
						if (HeadMinus == NULL) {
							cout << "������ ����! ��������� ������.";
							getch ();
							break;
						}
						else	
							cout << "������ � �������������� ������� :\n"; 
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
				cout << "������ �������!";
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

