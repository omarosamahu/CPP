#pragma once
#include <iostream>
#include <string>

#ifndef HASH_H
#define HASH_H

class Hash{
private:
	static const int table_size = 10;

	struct item{
		std::string name;
		std::string drink;
		item* next;
	};

	item* HashTable[table_size]; // array that has some buckts
public:
	Hash();
	int hashFunc(std::string key);
	int getNumberOfItems(int index);
	void addItem(std::string name, std::string drink);
	void printTable();
	void printItemsInsideIndex(int index);
	
};

#endif // !HASH_H

