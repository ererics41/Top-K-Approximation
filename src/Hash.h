#ifndef HASH_H
#define HASH_H 

#include "HeapNode.h"

struct HashNode{
	std::string word;
	int index; 
	HashNode *next; 
	HashNode(HeapNode *entry, int index){ this->word = entry->word; this->index = index; };
	HashNode();
};

class HashTable{
public:
	HashTable(int size);
	void insert(HeapNode* entry, int index);
	int search(std::string word);
	void remove(std::string word);
	void print();
private:
	int TABLE_SIZE;
	HashNode **table;
};

#endif