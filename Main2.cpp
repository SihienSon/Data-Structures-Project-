#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "HashTable.hpp"
using namespace std;
////////////////////////////////////////////////////////////////////////////////
class Node			//Linked list node and class basic stuff, adding deleting
{
public:
	string data;
	Node *next;
	Node(string data);
};
////////////////////////////////////////////////////////////////////////////////
struct Hash {
	std::string data;
	Hash* next;
	Hash() : data("_"), next(nullptr) {}
	Hash(std::string d) : data(d), next(nullptr) {}
};
////////////////////////////////////////////////////////////////////////////////
class LinkedList
{
public:
	Node *head;
	int size;
	LinkedList();
	void insertAtHead(string data);
	void printList();
	bool deleteAtIndex(int index);
	bool isEmpty();
	bool deleteAtHead();
};
////////////////////////////////////////////////////////////////////////////////
Node::Node(string data)
{
	this->data = data;
	this->next = NULL;
}
LinkedList::LinkedList()
{
	this->size = 0;
	this->head = NULL;
}
////////////////////////////////////////////////////////////////////////////////
void LinkedList::insertAtHead(string data)
{
	Node *newNode = new Node(data);
	newNode->next = this->head;
	this->head = newNode;
	this->size++;
}
////////////////////////////////////////////////////////////////////////////////
void LinkedList::printList()
{
	Node *temp = this->head;
	int i = 1;
	cout << "Your Shopping List Currently Looks Like:" << endl;
	while(temp->next != NULL)
	{
		cout << i << ":";
		cout << temp-> data;
		cout<<"|";
		temp = temp->next;
		i++;
	}
	cout << i << ":";
	cout << temp->data;
	cout << " " << endl;
}
////////////////////////////////////////////////////////////////////////////////
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(this->size == 0)
	{
		cout<<"No nodes to delete"<<endl;
		return isDeleted;
	}
  Node *pres = this->head;
	Node *prev = pres;
  int i;
  for(int i = 0; i < n; i++)
	{
    prev = pres;
		pres = pres->next;
	}
  prev->next = pres->next;
	delete pres;
	isDeleted = true;
	return isDeleted;
}
bool LinkedList::isEmpty(){
  Node *temp2 = this->head;
  if(temp2 == NULL){
    return true;
  }
  else{
    return false;
  }
}
////////////////////////////////////////////////////////////////////////////////
bool LinkedList::deleteAtHead()
{
	bool isDeleted = false;

	if(this->size == 0)
	{
		cout<<"No nodes to delete"<<endl;
		return isDeleted;
	}
  Node *temp = this->head;
	this->head = temp->next;
	delete temp;
  isDeleted = true;
  this->size--;
	return isDeleted;
}
////////////////////////////////////////////////////////////////////////////////
int main()
{
queue<string> ShoppingList;  //Initlizie queues hashtable and linked list for program
HashTable<GroceryItem> table(50);
LinkedList list;
bool List = 0;
cout << "Enter Each Item Followed By The Enter Key" << endl;   //User input and gives them choice to enter more or delete something
cout << "When You Are Done Enter 'Done' Followed By Enter" << endl;

while(!List){
  string Item;
  cin >> Item;
  if(Item == "Done"){
    List = 1;
  }
  else{
  list.insertAtHead(Item);
  }
}
	if(list.isEmpty() == true)
	{
		cout << "No List Detected Have A Good Day." << endl;
		return 0;
	}
	else{
		list.printList();
	}
bool Options = 0;
while(!Options){
cout << "What Would You Like To Do?" << endl;
cout << "1.Add To My List" << endl;
cout << "2.Delete Items" << endl;
cout << "3.Contuine To Finding The Optimal Route" << endl;
string Choice;
cin >> Choice;
if(Choice == "1"){
	bool List = 0;
	cout << "Enter Each Item Followed By The Enter Key" << endl;
	cout << "When You Are Done Enter 'Done' Followed By Enter" << endl;
	while(!List){
	  string Item;
	  cin >> Item;
	  if(Item == "Done"){
	    List = 1;
	  }
	  else{
	  list.insertAtHead(Item);
	  }
	}
		list.printList();
}
if(Choice == "2"){
		int DeleteIndex;
		cout << "Enter The Index Number Of The Item You Want Deleted." << endl;
		cin >> DeleteIndex;
		DeleteIndex = DeleteIndex - 1;
		if(DeleteIndex == 0){
			list.deleteAtHead();
			list.printList();
		}
		else{
			list.deleteAtIndex(DeleteIndex);
			list.printList();
		}
}
if(Choice == "3"){
	Options = 1;
		}
}
ifstream myfile("/Users/Sihienkson/Desktop/Project/Store.txt");   //reads Store.txt file to insert data into hashtable
if (myfile.is_open()){
	while (!myfile.eof()) {
		GroceryItem temp = GroceryItem();
		myfile >> temp.name;
		myfile >> temp.aisle;
		myfile >> temp.distance;
		table.addGroceryItem(temp);
	}
}
else{
	cout << "Not Open" << endl;
}
string Aisle1[11] = {"0","0","0","0","0","0","0","0","0","0","0"}; //I am very lazy and made arrays could be more efficent
string Aisle2[11] = {"0","0","0","0","0","0","0","0","0","0","0"};
string Aisle3[11] = {"0","0","0","0","0","0","0","0","0","0","0"};
string Aisle4[11] = {"0","0","0","0","0","0","0","0","0","0","0"};
string Aisle5[11] = {"0","0","0","0","0","0","0","0","0","0","0"};
string Aisle6[11] = {"0","0","0","0","0","0","0","0","0","0","0"};
string Aisle7[11] = {"0","0","0","0","0","0","0","0","0","0","0"};
string Aisle8[11] = {"0","0","0","0","0","0","0","0","0","0","0"};

while(list.head != NULL){
	GroceryItem item = table.getFromtTable(list.head->data); //Adding each item to its Aisle Array
	if(item.aisle == -1){
		cout << "We Don't Carry " << list.head->data << " Sorry!" << endl;
	}
	if(item.aisle == 1){
		Aisle1[item.distance] = item.name;
	}
	if(item.aisle == 2){
		Aisle2[item.distance] = item.name;
	}
	if(item.aisle == 3){
		Aisle3[item.distance] = item.name;
	}
	if(item.aisle == 4){
		Aisle4[item.distance] = item.name;
	}
	if(item.aisle == 5){
		Aisle5[item.distance] = item.name;
	}
	if(item.aisle == 6){
		Aisle6[item.distance] = item.name;
	}
	if(item.aisle == 7){
		Aisle7[item.distance] = item.name;
	}
	if(item.aisle == 8){
		Aisle8[item.distance] = item.name;
	}
	list.head = list.head->next;
}

bool Aisle1Empty = 1;
bool Aisle2Empty = 1;
bool Aisle3Empty = 1;
bool Aisle4Empty = 1;
bool Aisle5Empty = 1;
bool Aisle6Empty = 1;
bool Aisle7Empty = 1;
bool Aisle8Empty = 1;

for(int i = 1; i < 11; i++){
	if(Aisle1[i] != "0"){
		Aisle1Empty = 0;
	}
}
for(int i = 1; i < 11; i++){
	if(Aisle2[i] != "0"){
		Aisle2Empty = 0;
	}
}
for(int i = 1; i < 11; i++){
	if(Aisle3[i] != "0"){
		Aisle3Empty = 0;
	}
}
for(int i = 1; i < 11; i++){
	if(Aisle4[i] != "0"){
		Aisle4Empty = 0;
	}
}
for(int i = 1; i < 11; i++){
	if(Aisle5[i] != "0"){
		Aisle5Empty = 0;
	}
}
for(int i = 1; i < 11; i++){
	if(Aisle6[i] != "0"){
		Aisle6Empty = 0;
	}
}
for(int i = 1; i < 11; i++){
	if(Aisle7[i] != "0"){
		Aisle7Empty = 0;
	}
}
for(int i = 1; i < 11; i++){
	if(Aisle8[i] != "0"){
		Aisle8Empty = 0;
	}
}
if(Aisle1Empty && Aisle2Empty && Aisle3Empty && Aisle4Empty && Aisle5Empty && Aisle6Empty && Aisle7Empty && Aisle8Empty){
	cout << "We Don't Carry Any Items You Are Looking For, Sorry!" << endl;
	return 0;
}
bool UpDownOrder = 1;
bool Aisle7Printed = 0;
bool Aisle8Printed = 0;

if(!Aisle1Empty){
	for(int i = 1; i < 11; i++){
		if(Aisle1[i] != "0"){
		ShoppingList.push(Aisle1[i]);
		}
	}
	for(int i = 1; i < 11; i++){
		if(Aisle7[i] != "0"){
		ShoppingList.push(Aisle7[i]);
		}
	}
	Aisle7Printed = !Aisle7Printed;
	UpDownOrder = !UpDownOrder;
}
if(!Aisle2Empty){
	if(UpDownOrder){
		for(int i = 1; i < 11; i++){
			if(Aisle2[i] != "0"){
			ShoppingList.push(Aisle2[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
	}
	else{
		for(int i = 10; i > 0; i--){
			if(Aisle2[i] != "0"){
			ShoppingList.push(Aisle2[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
	}
	if(!Aisle7Printed){
		for(int i = 1; i < 11; i++){
			if(Aisle7[i] != "0"){
			ShoppingList.push(Aisle7[i]);
			}
		}
		Aisle7Printed = !Aisle7Printed;
	}
}
if(!Aisle3Empty){
	if(UpDownOrder){
		for(int i = 1; i < 11; i++){
			if(Aisle3[i] != "0"){
			ShoppingList.push(Aisle3[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
	}
	else{
		for(int i = 10; i > 0; i--){
			if(Aisle3[i] != "0"){
			ShoppingList.push(Aisle3[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
	}
	if(!Aisle7Printed){
		for(int i = 1; i < 11; i++){
			if(Aisle7[i] != "0"){
			ShoppingList.push(Aisle7[i]);
			}
		}
		Aisle7Printed = !Aisle7Printed;
	}
}

if(!UpDownOrder){
	if(!Aisle8Printed){
		for(int i = 1; i < 11; i++){
			if(Aisle8[i] != "0"){
			ShoppingList.push(Aisle8[i]);
			}
		}
		Aisle8Printed = !Aisle8Printed;
	}
}
if(!Aisle7Printed){
	for(int i = 1; i < 11; i++){
		if(Aisle7[i] != "0"){
		ShoppingList.push(Aisle7[i]);
		}
	}
	Aisle7Printed = !Aisle7Printed;
}
if(!Aisle4Empty){
	if(UpDownOrder){
		for(int i = 1; i < 11; i++){
			if(Aisle4[i] != "0"){
			ShoppingList.push(Aisle4[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
		if(!Aisle8Printed){
			for(int i = 1; i < 11; i++){
				if(Aisle8[i] != "0"){
				ShoppingList.push(Aisle8[i]);
				}
			}
			Aisle8Printed = !Aisle8Printed;
		}
	}
	else{
		for(int i = 10; i > 0; i--){
			if(Aisle4[i] != "0"){
			ShoppingList.push(Aisle4[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
	}
}
if(!Aisle5Empty){
	if(UpDownOrder){
		for(int i = 1; i < 11; i++){
			if(Aisle5[i] != "0"){
			ShoppingList.push(Aisle5[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
		if(!Aisle8Printed){
			for(int i = 1; i < 11; i++){
				if(Aisle8[i] != "0"){
				ShoppingList.push(Aisle8[i]);
				}
			}
			Aisle8Printed = !Aisle8Printed;
		}
	}
	else{
		for(int i = 10; i > 0; i--){
			if(Aisle5[i] != "0"){
			ShoppingList.push(Aisle5[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
	}
}
if(!Aisle6Empty){
	if(UpDownOrder){
		for(int i = 1; i < 11; i++){
			if(Aisle6[i] != "0"){
			ShoppingList.push(Aisle6[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
		if(!Aisle8Printed){
			for(int i = 1; i < 11; i++){
				if(Aisle8[i] != "0"){
				ShoppingList.push(Aisle8[i]);
				}
			}
			Aisle8Printed = !Aisle8Printed;
		}
	}
	else{
		for(int i = 10; i > 0; i--){
			if(Aisle6[i] != "0"){
			ShoppingList.push(Aisle6[i]);
			}
		}
		UpDownOrder = !UpDownOrder;
	}
}
if(!Aisle8Printed){
	for(int i = 1; i < 11; i++){
		if(Aisle8[i] != "0"){
		ShoppingList.push(Aisle8[i]);
		}
	}
	Aisle8Printed = !Aisle8Printed;
}

////////////////////////////////////////////////////////////////////////////////
cout << "The Most Optimal Route Is: " << endl;  //Prints out the queue on items after it was sorted and inserted into queue.
while(!ShoppingList.empty()){
	cout << ShoppingList.front() << " -> ";
	ShoppingList.pop();
}
}
