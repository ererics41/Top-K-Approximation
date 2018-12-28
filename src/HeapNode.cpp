#include "HeapNode.h"
#include <sstream>

using namespace std;

HeapNode::HeapNode(string word){ 
	this->word = word; 
	frequency = 1; 
}

string HeapNode::toString(){
	ostringstream oss;
  
	oss << "{ word: " 
	    << word 
	    << ", frequency: "
	    << frequency
	    << " }";

	return oss.str();
}