#include <string>
#include <iostream>        //Hashtable hpp I basically recycled from the hungar games assignment but used a Template to change it
#include <vector>
using namespace std;
struct GroceryItem
{
    string name;
    int aisle;
    int distance;

	GroceryItem* next;

	GroceryItem() : name(""), aisle(-1), distance(-1), next(nullptr) {}
	GroceryItem(string n, int a, int d) : name(n), aisle(a), distance(d), next(nullptr) {}
};


template <typename T>
class HashTable{
public:
	HashTable(int hashTableSize);
	~HashTable();
	void addGroceryItem(GroceryItem item);
	bool isInTable(string word);
	T getFromtTable(string word);

private:
	int getHash(string word);
	T* searchTable(string word);
	int hashTableSize;
	T** hashTable;
};
///////////////////////////////////////////////////////////////////////////////
template <typename T>
HashTable<T>::HashTable(int hashTableSize) {
	this->hashTableSize = hashTableSize;
	this->hashTable = new T*[hashTableSize];
	for (int i = 0; i < hashTableSize; i++) {
		hashTable[i] = nullptr;
	}
}
///////////////////////////////////////////////////////////////////////////////
template <typename T>
void deleteHelper(T *toDelete) {
	if (toDelete->next != NULL) {
		deleteHelper(toDelete->next);
	}
	delete toDelete;
}

template <typename T>
HashTable<T>::~HashTable() {
	for (int i = 0; i < this->hashTableSize; i++) {
		if (hashTable[i] != NULL) {
			deleteHelper(hashTable[i]);
		}
	}
	delete[] this->hashTable;
	this->hashTable = nullptr;
}
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void HashTable<T>::addGroceryItem(GroceryItem item)
{
	int Hashvalue = getHash(item.name);
	T* prev = NULL;
	T* enter = hashTable[Hashvalue];
	while (enter != NULL) {
		if (isInTable(item.name)) {
			return;
		}
		prev = enter;
		enter = enter->next;
	}
	if (enter == NULL) {
		enter = new GroceryItem();

		*enter = item;

		if (prev == NULL) {
			hashTable[Hashvalue] = enter;
		}
		else {
			prev->next = enter;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool HashTable<T>::isInTable(string word) {
	T* tempHash = searchTable(word);
	return tempHash ? true : false;
}

template<typename T>
inline T HashTable<T>::getFromtTable(string word)
{
	T* t = searchTable(word);
	return t ? (*t) : T();
}


/////////////////////////////////////////////////////////////////////////////////
template <typename T>
int HashTable<T>::getHash(string word) {
	int hash = 5381;
	int c;
	for (int i = 0; i < (int)word.length(); i++) {
		c = (int)word[i];
		hash = hash * 33 + c;
	}
	hash = hash % hashTableSize;
	if (hash < 0) {
		hash += hashTableSize;
	}
	return hash;
}
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
T* HashTable<T>::searchTable(string word) {
	int Hashvalue = getHash(word);
	T* current = hashTable[Hashvalue];
	while (current != NULL) {
		if (current->name == word) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}
