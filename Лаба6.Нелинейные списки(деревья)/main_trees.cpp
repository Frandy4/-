#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;
//---------------------------------------------------------------------------------------------------------------
struct Tree {
	int key;
	string info; 
	Tree *left, *right;
} *root;
//---------------------------------------------------------------------------------------------------------------
Tree* CreateList(int key, string info){               
	Tree *temp = new Tree;
	temp->key = key;
	temp->info = info;
	temp->left = temp->right = NULL;
	return temp;
}
//---------------------------------------------------------------------------------------------------------------
void AddList(Tree *&root, int key, string info) {
	int i;
	Tree *prev, *temp;
	bool find = true;
	temp = root;
	while ( temp != NULL && find ) {
 		prev = temp;
		if( key == temp->key) {
 			find = false;
 			system("cls");
 			cout << "ДУБЛИКАТ. Проверьте ввод данных." << endl;
			getch();
		}
		else
			if ( key < temp->key ) 
				temp = temp->left;
			else 
				temp = temp->right;
		}
		
		if (find) {
			temp = CreateList(key, info);
			if ( key < prev->key ) 
				prev->left = temp;
			else 
				prev->right = temp;
			}
}
//---------------------------------------------------------------------------------------------------------------
void ShowTree(Tree *&root, int level) {
	string str = "";	
	if ( root ) {
		ShowTree (root->right, level+1);
		for (int i=0; i<level; i++) 
			str = str + "\t";
		cout << str << "[" << root->key << "]" << root->info << endl;
 		ShowTree(root->left, level+1); 
 	}
} 
//---------------------------------------------------------------------------------------------------------------
void SwapMaxMin (Tree* root) {
	Tree *max = root, *min = root;
	while (min->left != NULL)
		min = min->left;
	while (max->right != NULL)
		max = max->right;
	string temp = max->info;
	max->info = min->info;
	min->info = temp;
}
//---------------------------------------------------------------------------------------------------------------
void DeleteTree(Tree *&temp) {
	if (temp != NULL) {
 		DeleteTree (temp -> left); 
 		DeleteTree (temp -> right); 
 	delete temp;
 	}
}
//---------------------------------------------------------------------------------------------------------------
int main(int argc, char** argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int key, level;
	string info;
		
	while (true) {
		system ("cls");
		puts ("1 - добавить в дерево.");
		puts ("2 - просмотреть дерево.");
		puts ("3 - поменять информацию максимального и минимального ключей местами.");
		puts ("4 - очистить память.");
		puts ("0 - выйти из программы.");
	
		switch (getch()) {
			case '1' :
				system("cls");	
				cout << "Введите ключ: ";
				cin >> key;
				cout << "Введите информацию: ";
				cin >> info;
				if(root == NULL) 
					root = CreateList(key, info);
 				else 
				 	AddList(root, key, info); 	
			break;
			
			case '2' :					
				system("cls");
				if( root == NULL ) 
					cout << "Создайте дерево.";
 				else 
 					ShowTree(root, 0);
 					cout << endl << endl;
 				getch();
			break;
			
			case '3' :		
				system("cls");
				if (root == NULL) {
					cout << "Дерева не существует.";
					getch();
					break;
				}
				SwapMaxMin (root);
				ShowTree(root, 0);
				getch();
			break;
			
			case '4' :		
				system("cls");
				DeleteTree(root);
				cout << "Память очищена.";
 				root = NULL;
				getch();
			break;
			
			case '0' :		
			if(root != NULL) 
 				DeleteTree(root);
		 	return 0;		
		}		
	}
}
