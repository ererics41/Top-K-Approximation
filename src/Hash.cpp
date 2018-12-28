#include "Hash.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int size){
	TABLE_SIZE = size;
	table = new HashNode* [TABLE_SIZE];
	for(int i = 0; i < TABLE_SIZE; i++){
		table[i] = NULL;
	}
}

void HashTable::insert(HeapNode* entry, int index){
	string word = entry->word;
	int found = search(word);
	int sum = 0;
	if(found == -1){
		for(string::iterator it = word.begin(); it != word.end(); it++){
			sum += *it;
		}
		sum = sum%TABLE_SIZE;
		HashNode* node = new HashNode(entry, index);
		if(table[sum] != NULL){
			node->next = table[sum];
		}else{
			node->next = NULL;
		}
		table[sum] = node;
	}
}

//search is case sentitive
int HashTable::search(string word){
	int index = 0;
	for(string::iterator it = word.begin(); it != word.end(); it++){
		index += *it;
	}
	//cout << "index: " <<index <<endl;
	index = index%TABLE_SIZE;
	HashNode *current = table[index];
	//cout << "Inside search index is " << index <<endl;
	while(current != NULL){
		//cout << "inside while" <<endl;
		if(current->word == word){
			//cout << "current word is " <<current->word <<endl;
			return current->index;
		}
		current = current->next;
	}
	//cout << "Finishing search" << endl;
	return -1;
}

//removes the word from the has table but does not delete the removed object
void HashTable::remove(std::string word){
	//cout << "Inside remove" << endl;
	int index = 0;
	for(string::iterator it = word.begin(); it != word.end(); it++){
		index += *it;
	}
	index = index%TABLE_SIZE;
	HashNode *previous = NULL;
	HashNode *current = table[index];
	//cout << "index is " <<index <<endl;
	//print();
	while(current != NULL){
		if(current->word == word){
			if(previous != NULL){
				previous->next = current->next;
			}else{
				table[index] = current->next;
			}
			return;
		}
		previous = current;
		current = current->next;
	}
}

void HashTable::print(){
	cout << "Printing the hash table." <<endl;
	HashNode* current;
	for(int i = 0; i < TABLE_SIZE; i++){
		current = table[i];
		cout << "At index " << i << " ";
		if(current == NULL){
			cout << "No Entry";
		}else{
			while(current!=NULL){
				cout <<"{"<< current->word << " [" << current->index << "]}";
				if(current->next != NULL){
					cout << " ---> ";
				}
				current = current->next;
			}
		}
		cout << "\n";
	}
}

