#ifndef HEAPNODE_H
#define HEAPNODE_H 

#include <string>

struct HeapNode{
	std::string word;
	int frequency;
	HeapNode(std::string word);
	std::string toString();
};

#endif