#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
#ifndef HASH_H
#define HASH_H

class Hash
{
	private:
		static const int tableSize=40;
		struct item{
			string name;
			string drink;
			item* next;
			item(){
				this->name="empty";
				this->drink="empty";
				this->next=NULL;
			}
		};
		item *HashTable[tableSize];
	public:
		Hash();
		int HashFun(string key);
		void AddItem(string name,string drink);
		int NumberOfItemInIndex(int index);
		void PrintTable();
		void PrintItemsInIndex(int index);
		string SearchDrink(string name);
		void RemoveItem(string name);
};

#endif

