#include "MinHeap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap(int size){
	MAX_SIZE = size;
	this->size = 0;
	heap = new HeapNode* [MAX_SIZE];
	table = new HashTable(MAX_SIZE);
}

void MinHeap::insert(string w){
	//make word lowercase
	if(w == ""){
		return;
	}
	string word = "";
	for(string::iterator it = w.begin(); it != w.end(); it++){
		word += tolower(*it);
	}
	//check if word is in the heap by searching the hash
	int found = table->search(word);
	//if word is already in the heap increment
	if(found > 0){
		heap[found]->frequency++;
		//heapify down from here
		heapifyDown(found);
	}
	//word is not in the heap
	else{
		// heap is not yet full add new element
		if(size < MAX_SIZE-1){
			//create new node to insert
			HeapNode *node = new HeapNode(word);
			size++;
			//insert into heap
			heap[size] = node;
			//insert into hash table
			table->insert(node,size);
			heapifyUp(size);
		}
		//the heap is full so we must replace min
		else{
			replaceMin(word);
		}
	}
}

void MinHeap::replaceMin(string word){
	//remove old entry from hash table
	table->remove(heap[1]->word);
	//replace the min word
	heap[1]->word = word;
	//add new entry to hash table
	table->insert(heap[1],1);
}

void MinHeap::print(){
	cout << "Printing the Heap." << endl;
	for(int i = 1; i <= size; i++){
		cout << "at index " << i << ": " << heap[i]->toString() << endl;
	}
}

void MinHeap::printHash(){
	table->print();
}

void MinHeap::printApprox(){
	cout << "Printing an approximation of the most frequent words." << endl;
	for(int i = 1; i <= size; i++){
		cout << heap[i]->word << " occurs " << heap[i]->frequency << " times." << endl;
	}

}

void MinHeap::heapifyUp(int index){
	//cout << "Inside heap up" <<endl;
	if(index <= 1 || heap[index]->frequency >= heap[index/2]->frequency){
		return;
	}else{
		//swap
		HeapNode *temp = heap[index];
		table->remove(heap[index]->word);
		table->remove(heap[index/2]->word);
		//table->print();
		heap[index] = heap[index/2];
		heap[index/2] = temp;
		table->insert(heap[index],index);
		table->insert(heap[index/2],index/2);
		//continue checking recursively
		heapifyUp(index/2);
	}
}

void MinHeap::heapifyDown(int index){
	if(index*2 > size){
		return;
	}else{
		HeapNode* left = heap[index*2];
		HeapNode* right = left;
		if(index*2+1 <= size){
			right = heap[index*2+1];
		}
		int minIndex;
		if(left->frequency <= right->frequency){
			minIndex = index*2;
		}else{
			minIndex = index*2+1;
		}
		//swap if min is less than parent
		if(heap[minIndex]->frequency < heap[index]->frequency){
			//swap
			table->remove(heap[index]->word);
			table->remove(heap[minIndex]->word);
			HeapNode *temp = heap[index];
			heap[index] = heap[minIndex];
			heap[minIndex] = temp;
			table->insert(heap[index],index);
			table->insert(heap[minIndex],minIndex);

			//continue checking recursively
			heapifyDown(minIndex);
		}
	}
}
