#include "MaxHeap.h"
#include <iostream>

using namespace std;

MaxHeap::MaxHeap(){
	MAX_SIZE = 100;
	this->size = 0;
	heap = new HeapNode* [MAX_SIZE];
	table = new HashTable(10000);
}

void MaxHeap::insert(string w){
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
		heapifyUp(found);
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
	}
	//increase heap size if size is now equal to max size
	if(size >= MAX_SIZE-1){
		if(MAX_SIZE < 1000){
			MAX_SIZE *= 3;
		}else if(MAX_SIZE < 13000){
			MAX_SIZE *= 5;
		}else{
			MAX_SIZE += 2000;
		}
		HeapNode **temp = new HeapNode* [MAX_SIZE];
		for(int i = 1; i <=size; i++){
			temp[i] = heap[i];
		}
		heap = temp;
	}
}

void MaxHeap::insert(HeapNode *entry){
	size++;
	heap[size] = entry;
	table->insert(entry,size);
	heapifyUp(size);
}

HeapNode* MaxHeap::removeMax(){
	HeapNode *rtn = heap[1];
	table->remove(heap[size]->word);
	table->insert(heap[size],1);
	if(size>1){
		heap[1] = heap[size];
		size--;
		heapifyDown(1);
	}
	return rtn;
}

void MaxHeap::print(int num){
	if(size == 0){
		cout << "File was empty." << endl;
		return;
	}
	cout << "Printing most frequent words." << endl;
	if(num < size){
		num = size;
	}
	HeapNode **frequent = new HeapNode* [num];
	for(int i = 0; i < num; i++){
		frequent[i] = removeMax();
	}
	cout << "removed top nodes " <<endl;
	for(int i = 0; i < num; i++){
		cout << frequent[i]->word << " occurs " << frequent[i]->frequency << " times." << endl;
		insert(frequent[i]);
	}
}

/*void MaxHeap::print(){
	for(int i = 1; i <= 15; i++){
		cout << heap[i]->word << " occurs " << heap[i]->frequency << " times." << endl;
	}
}*/


void MaxHeap::heapifyUp(int index){
	//cout << "Inside heap up" <<endl;
	if(index <= 1 || heap[index]->frequency <= heap[index/2]->frequency){
		return;
	}else{
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

void MaxHeap::heapifyDown(int index){
	if(index*2 > size){
		return;
	}else{
		HeapNode* left = heap[index*2];
		HeapNode* right = left;
		if(index*2+1 <= size){
			right = heap[index*2+1];
		}
		int maxIndex;
		if(left->frequency >= right->frequency){
			maxIndex = index*2;
		}else{
			maxIndex = index*2+1;
		}
		//swap if min is less than parent
		if(heap[maxIndex]->frequency > heap[index]->frequency){
			//swap
			table->remove(heap[index]->word);
			table->remove(heap[maxIndex]->word);
			HeapNode *temp = heap[index];
			heap[index] = heap[maxIndex];
			heap[maxIndex] = temp;
			table->insert(heap[index],index);
			table->insert(heap[maxIndex],maxIndex);

			//continue checking recursively
			heapifyDown(maxIndex);
		}
	}
}

