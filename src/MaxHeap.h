#ifndef MAXHEAP_H
#define MAXHEAP_H 

#include "Hash.h"

class MaxHeap{
public:
	MaxHeap();
	void insert(std::string w);
	void insert(HeapNode* entry);
	void print(int num);
	//void print();
	HeapNode* removeMax();

private:
	int MAX_SIZE;
	int size;
	HeapNode **heap;
	HashTable *table;
	void heapifyUp(int index);
	void heapifyDown(int index);
};

#endif