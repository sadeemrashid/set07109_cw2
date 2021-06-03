/*


Author : Sadeem Rashid
Date last modified : 7 April 2019
This class is made to count the single words , the input has been provided as a text file.



*/



#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;


int main(int argc, char **argv) {
	ifstream input_file;
	input_file.open("single_words_test.txt");
	if (!input_file) {
		std::cout << "the file could not be opened";
		exit(1);
	}


	string word;
	BinarySearchTree *tree = new BinarySearchTree();
	while (input_file >> word)
	{
		tree->insert(word);
	}

	input_file.close();
	cout << tree->count() << endl;



	return 0;
}