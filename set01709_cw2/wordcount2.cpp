/*


Author : Sadeem Rashid
Date last modified : 7 April 2019
This class is made to count the words in sentences , the input has been provided as a text file.



*/
#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;
char str[500];

int main(int argc, char **argv) {
	ifstream input_file;
	input_file.open("sentences_test.txt");
	if (!input_file) {
		std::cout << "the file could not be opened";
			exit(1);
	}


	string word;
	BinarySearchTree *tree = new BinarySearchTree();
	while (input_file >> word)
	{

		for (int i = 0, len = word.size(); i < len; i++)
		{
			if (ispunct(word[i]))
			{
				word.erase(i--, 1);
				len = word.size();
			}
		}
		
		tree->insert(word);


	}
		input_file.getline(str, 500);
		char* tempPtr = strtok(str, " ");
		while (tempPtr)
		{
			
			tempPtr = (NULL, " ,.");
		}

        input_file.close();
		cout << tree->count() << endl;
	


	return 0;
 }
