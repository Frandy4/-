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
	switch (getch()) {  		  			//� ������
		case '1':
			temp->prev = NULL;
			temp->next = Head;
			Head->prev = temp;
			Head = temp;
		break;
		
		case '2':		                	//� �����  
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
			cout << "----� ������----\n";
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
			cout << "----� �����----\n";
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
		puts ("1 - ������� ������.");
		puts ("2 - �������� � ������.");
		puts ("3 - ����������� ������.");
		puts ("4 - �������� ������.");
		puts ("q - ����� �� ���������.");
	
		switch (getch()) {
			case '1' :                     // ������� ������.
				system ("cls");
				if (Head != NULL) {
					system ("cls");
					cout << "����� ��������� ������ ������ ����� �������� ������!";
					getch();
					break;
				}
				cout << "������� �����, ������� ������ ��������: ";
				cin >> number;
				CreateSpis(Head, Tail, number);
				if (number < 0)
					CreateSpis(HeadMinus, TailMinus, number);
				else
					CreateSpis(HeadPlus, TailPlus, number);
			break;
			
			case '2' :						//�������� � ������.
				system("cls");
				cout << "������� �����, ������� ������ ��������: ";
				cin >> number;
				system("cls");
				cout << "���� �������� ����� " << number << " ?\n1 - � ������ ������.\n2 - � ����� ������.\n" << endl;
				AddInSpis(*&Head, *&Tail, number);
				if (number < 0) 
					CreateOrAddSpis2 (HeadMinus, TailMinus, number);
				else 
					CreateOrAddSpis2 (HeadPlus, TailPlus, number);	
				
				
			break;
			
			case '3' :						//����������� ������.
				system("cls");
				if (Head == NULL) {
					cout << "������ �����!";
					getch();
					break;
				}
				cout << "    ����� ������ �� ������ �����������?\n1 - ��������.\n2 - � �������������� �������.\n3 - � �������������� �������.\n";
				switch (getch()) {
					case '1':
						system ("cls");
						cout << "   �������� � :\n1 - ������ ������.\n2 - ����� ������.\n";
						ShowSpis(Head, Tail);
					break;
					case '2':
						system ("cls");
						cout << "������ ������������� �����:\n";
						ShowSpis2(HeadPlus);
					break;
					case '3':
						system ("cls");
						cout << "������ ������������� �����:\n";
						ShowSpis2(HeadMinus);
					break;
				}
			break;
			
			case '4' :						//������� ������.
				system("cls");
				DeleteSpis(Head);
				DeleteSpis(HeadPlus);
				DeleteSpis(HeadMinus);
				cout << "������ �������.";
				getch();
			break;
			
			case 'q' :						//����� �� ���������.
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
















