#include<bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "hash.h"
using namespace std;
int main() {
	cout<<"Hare Krishna Welcome To HashTable\n";
	cout<<"Follow these commands for better experience\n";
	cout<<"1. To Add Item."<<"\n";
	cout<<"2. To access any key.\n";
	cout<<"3. To print the whole Table.\n";
	cout<<"4. To delete any key.\n";
	cout<<"5. To Exit Application.\n";
	int t=0;
	Hash HashObj;
	while(t!=5){
		cin>>t;
		switch(t) {
			case 1:{
				string name,drink;
				cout<<"Enter Name and Drink: ";
				cin>>name>>drink;
				HashObj.AddItem(name,drink);
				break;
			}
			case 2:{
				string key;
				cout<<"Enter name to acess the drink: ";
				cin>>key;
				cout<<"Drink for "<<key<<" is"<<HashObj.SearchDrink(key)<<"\n";
				break;
			}
			case 3:{
				HashObj.PrintTable();
				break;
			}
			case 4:{
				string name;
				cout<<"Type name to be deleted: ";
				cin>>name;
				HashObj.RemoveItem(name);
				break;
			}
			case 5:{
				cout<<"Thank you for using......\n";
				break;
			}
			default:{
				cout<<"Invalid Input!!\n";
			} 
		}
	}
	return 0;
}

