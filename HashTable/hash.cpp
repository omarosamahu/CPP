#include "hash.h"

Hash::Hash()  {
	for (size_t i = 0; i < table_size; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = nullptr;
	}
}
int Hash::hashFunc(std::string key) {
	int hash = 0, index = 0;
	for (int i = 0; i < key.length(); i++) {
		hash = hash + static_cast<int>(key[i]);
	}
	index = hash % table_size;
	return index;
}


void Hash::addItem(std::string name, std::string drink) {
	int index = hashFunc(name);
	if (HashTable[index]->name == "empty") {
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {
		item* ptr = HashTable[index];
		item* n = new item;
		n->name  = name;
		n->drink = drink;
		n->next  = NULL;

		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

int Hash::getNumberOfItems(int index) {
	int cnt = 0;
	if (HashTable[index]->name == "empty") {
		return cnt;
	}
	else {
		cnt += 1;
		item* ptr = HashTable[index];
		while (ptr->next != nullptr)
		{
			cnt += 1; 
			ptr = ptr->next;
		}
	}
	return cnt;
}

void Hash::printTable() {
	int number;
	for (size_t i = 0; i < table_size; i++)
	{
		number = getNumberOfItems(i);
		std::cout << "----------------\n";
		std::cout << "index = " << i << std::endl;
		std::cout << HashTable[i]->name << std::endl;
		std::cout << HashTable[i]->drink << std::endl;
		std::cout << "# of items = " << number << std::endl;
		std::cout << "----------------\n";
	}
}

void Hash::printItemsInsideIndex(int index) {
	item* ptr = HashTable[index];
	if (ptr->name == "empty") {
		std::cout << "index =" << index << " is empty\n";
	}
	else
	{
		std::cout << "index =" << index << " contains the following items\n";
		while (ptr != nullptr)
		{
			std::cout << "---------------\n";
			std::cout << ptr->name << std::endl;
			std::cout << ptr->drink << std::endl;
			std::cout << "---------------\n";
			ptr = ptr->next;
		}
	}
}