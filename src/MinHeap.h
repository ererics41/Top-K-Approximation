#ifndef MINHEAP_H
#define MINHEAP_H 

#include "Hash.h"

class MinHeap{
public:
	MinHeap(int size);
	void insert(std::string w);
	void replaceMin(std::string word);
	void print();
	void printHash();
	void printApprox();

private:
	int MAX_SIZE;
	int size;
	HeapNode **heap;
	HashTable *table;
	void heapifyUp(int index);
	void heapifyDown(int index);
};

#endif