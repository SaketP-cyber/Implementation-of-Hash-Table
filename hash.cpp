#include "hash.h"
using namespace std;
Hash :: Hash(){
	for(int i=0;i<tableSize;i++){
		HashTable[i]=new item ;
	}
}
void Hash::AddItem(string name,string drink){
	int index=HashFun(name);
	if(HashTable[index]->name=="empty"){
		HashTable[index]->name=name;
		HashTable[index]->drink=drink;
	}
	else{
		item *ptr=HashTable[index];
		item *newItem=new item;
		newItem->name=name;
		newItem->drink=drink;
		newItem->next=NULL;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newItem;
	}
	cout<<"Info is Added\n";
}
int Hash :: NumberOfItemInIndex(int index){
	int count=0;
	item *temp=HashTable[index];
	if(temp->name=="empty"){
		return count;
	}
	else{
		count++;
		while(temp->next!=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}
}
string Hash :: SearchDrink(string name){
	int index=HashFun(name);
	item *ptr=HashTable[index];
	bool isNameExit=false;
	string drink;
	while(ptr!=NULL){
		if(ptr->name==name){
			isNameExit=true;
			drink=ptr->drink;
		}
		ptr=ptr->next;
	}
	if(isNameExit){
		return drink;
	}
	else{
		cout<<"info of"<<name<<"is not available"<<endl;
		return "";
	}
}
void Hash :: PrintTable(){
	int num;
	for(int i=0;i<tableSize;i++){
		num=NumberOfItemInIndex(i);
		cout<<"-------------------\n";
		cout<<"index="<<i<<endl;
		cout<<HashTable[i]->name<<endl;
		cout<<HashTable[i]->drink<<endl;
		cout<<"NO. Of Items="<<num<<endl;
		cout<<"-------------------\n";
	}
}
void Hash ::PrintItemsInIndex(int index){
	item *ptr=HashTable[index];
	if(ptr->name=="empty"){
		cout<<"Index="<<index<<"is empty"<<endl;
		return;
	}
	else{
		cout<<"index"<<index<<"contains folllowing items"<<endl;
		while(ptr!=NULL){
			cout<<"-------------------\n";
			cout<<ptr->name<<endl;
			cout<<ptr->drink<<endl;
			cout<<"-------------------\n";
			ptr=ptr->next;
		}
		return;
	}
}
void Hash :: RemoveItem(string name){
	int index=HashFun(name);
	item *ptr=HashTable[index];
	//Bucket Is Empty
	 if(ptr->name=="empty"){
	 	cout<<"No Such Name Exit"<<endl;
	 }
	 else if(ptr->name==name && NumberOfItemInIndex(index)==1){
	 	HashTable[index]->name="empty";
	 	HashTable[index]->drink="empty";
	 	HashTable[index]->next=NULL;
	 }
	 else if(ptr->name==name){
	 	item* delPtr=HashTable[index];
	 	HashTable[index]=HashTable[index]->next;
	 	delete delPtr;
	 }
	 else{
	 	bool isFound=false;
	 	item* p1=HashTable[index]->next;
		 item* p2=HashTable[index];
	 	while(p1!=NULL && p1->name!=name){
	 		p2=p1;
	 		p1=p1->next;
			 //ptr=ptr->next;
		 }
		 if(p1==NULL){
		 	cout<<"NO Items"<<endl;
		 }
		 else{
		 	item *delPtr=p1;
		 	p1=p1->next;
		 	p2->next=p1;
		 	delete delPtr;
		 	cout<<name<<" was removed"<<endl;
		 }
	 }
}
int Hash :: HashFun(string key){
	int hash=0;
	int len=key.size();
	int index;
	for(int i=0;i<len;i++){
		hash+=(key[i]);
	
	}
	index=hash%tableSize;
	//cout<<index<<"\n";
	return index;
}

