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
		puts ("1 - ������� ����.");
		puts ("2 - �������� � ����.");
		puts ("3 - ����������� ����.");
		puts ("4 - �������� ������.");
		puts ("q - ����� �� ���������.");
		
		switch (getch()) {
			case '1':
				if (Head != NULL) {
					system ("cls");
					cout << "����� ��������� ������ ����� ����� �������� ������!";
					getch();
					break;
				}
				
			case '2':
				system ("cls");
				cout << "������� �����, ������� ������ �������� � ���� : ";
				cin >> number;
				AddInStack(Head, number);
				if (number >= 0)
					AddInStack(HeadPlus, number);
				else
					AddInStack(HeadMinus, number);
			break;
			
			case '3':
				system("cls");
				puts ("�������� ���� :");
				puts ("1 - �� ����� �������.");
				puts ("2 - � ��������������� �������.");
				puts ("3 - � �������������� �������.");
				switch (getch()) {
					case '1' :
						system("cls");
						if (Head == NULL) {
							cout << "���� ����! ��������� ������.";
							getch ();
							break;
						}
						else	
							cout << "���� �� ����� ������� :\n"; 
						ShowStack(Head);
					break;
					
					case '2' :
						system("cls");	
						if (HeadPlus == NULL) {
							cout << "���� ����! ��������� ������.";
							getch ();
							break;
						}
						else	
							cout << "���� � �������������� ������� :\n"; 
						ShowStack(HeadPlus);
					break;
					
					case '3' :
						system("cls");	
						if (HeadMinus == NULL) {
							cout << "���� ����! ��������� ������.";
							getch ();
							break;
						}
						else	
							cout << "���� � �������������� ������� :\n"; 
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
				cout << "������ �������!";
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






