#include "MinHeap.h"
#include "MaxHeap.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	MinHeap minHeap(16);
	MaxHeap maxHeap;

	cout << "Input a file name. ";

	string input;
	getline(cin, input);

	ifstream myfile;
	myfile.open(input);

	while (myfile >> input){
    	minHeap.insert(input);	
    	maxHeap.insert(input);
	}

	myfile.close();

	cout << "Welcome to the popularity tracker." << endl
		 << "1) Add a word to the heap." << endl
		 << "2) Print the Heap." << endl
		 << "3) Print the Hash." << endl
		 << "4) Print an approximation of the most frequent words based on Heap." << endl
		 << "5) Print the most frequent words (true value)." << endl
		 << "6) Exit" << endl
		 << "Which operation would you like to make? (1, 2, 3, 4, 5, 6)." << endl;

	string option;
	while(true){
		getline(cin, option);
		if(option == "1"){
			cout << "Adding a word." << endl
				 << "Please enter a word." << endl;
			string word;
			getline(cin, word);
			minHeap.insert(word);
			maxHeap.insert(word);
			cout << "The word " << word << " has been inserted to the heap." << endl;
			cout << "Please enter 1, 2, 3, 4, 5, 6 to continue." << endl;
		}else if(option == "2"){
			minHeap.print();
			cout << "Please enter 1, 2, 3, 4, 5, 6 to continue." << endl;
		}else if(option == "3"){
			minHeap.printHash();
			cout << "Please enter 1, 2, 3, 4, 5, 6 to continue." << endl;
		}else if(option == "4"){
			minHeap.printApprox();
			cout << "Please enter 1, 2, 3, 4, 5, 6 to continue." << endl;
		}else if(option == "5"){
			maxHeap.print(15);
			cout << "Please enter 1, 2, 3, 4, 5, 6 to continue." << endl;
		}else if(option == "6"){
			cout << "Exitting application";
			break;
		}else{
			cout << "Invalid input. Please select an option from 1, 2, 3, 4, 5, 6." << endl;
		}
	}
}