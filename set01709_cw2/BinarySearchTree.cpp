/*


Author : Sadeem Rashid
Date last modified : 7 April 2019
The provided binary search tree class in which helper functions are made and called in the methods.



*/

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

// **Constructors **
BinarySearchTree::BinarySearchTree()
{
  root = nullptr; 
}


BinarySearchTree::BinarySearchTree(std::string word)
{
	root = new Node;
	root->word = word;
	root->left = nullptr;
	root->right = nullptr;

}



// Helper function for insert , if tree has nothing a new node is made , if there is already something the tree then adds to its left if its bigger
// and if its smaller it adds to its right
// as the words are added they are counted
void insert_worker(Node **tree, std::string word) {
	if ((*tree) == nullptr) {
		*tree = new Node;
		(*tree)->word = word;
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;
	
	}
	else
	{
		if (word < (*tree)->word) {
			insert_worker(&(*tree)->left, word);
		}
		else if (word > (*tree)->word) {
			insert_worker(&(*tree)->right, word);
		}
		else {
			(*tree)->count++;
			return;
		}
	}
 }


// The copy helper function for copying oldtree to newtree , if its null the new is set to null or else if it has content on left it is 
// deep copied to new trees left and same with right.
void deepcopy(Node* oldtree, Node*& tree2) {
	
	if (oldtree == nullptr) {
		tree2 = nullptr;
	}
	else
	{
		tree2 = new Node;


		tree2->word = oldtree->word;

		deepcopy(oldtree->left, tree2->left);

		deepcopy(oldtree->right, tree2->right);
	}

}

 
//helper function for exits

bool check(Node* tree, std::string word) {
	
	Node *temp = tree;
	while (temp != nullptr)
	{
	if (word == temp->word) {
		break;
	}
	if (word > temp->word) {
		temp = temp->right;
	}
	else if (word < temp->word) {
		temp = temp->left;	
	}
	}
	if (temp == nullptr) {
		return false;
	}
	if (temp->word == word)
		return true;

	return false;
}




BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{
	deepcopy(rhs.root, root);
}

// the helper function for vectors , goes through a for loop of all the words 
BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
	for (int i = 0; i < words.size(); i++)
		insert_worker(&root, words[i]);
}

// the helper function to print tree inorder
string inorder_worker(Node *tree) {
	if (tree != nullptr)
	{
			return inorder_worker(tree->left) + tree->word + " " + inorder_worker(tree->right);

	}
	else
	{
		return "";

	}
	
}
// the helper function to print tree preorder
std::string prehelper(Node *tree) {
	if (tree != nullptr) {
		return tree->word + " " + prehelper(tree->left) + prehelper(tree->right);
	}
	else {
		return "";
	}
}
// helper function to print tree postorder
std::string posthelper(Node *tree) {
	if (tree != nullptr) {
		return posthelper(tree->left) + "" + posthelper(tree->right) + tree->word + " ";
	}
	else {
		return "";
	}
}

// helper function for destructor it is called on both left and right sides to deleter from the tree
void del(Node *root) {
	if (root != nullptr) {
		if (root->left != nullptr) {
			del(root->left);
		}
		if (root->right != nullptr) {
			del(root->right);
		}
		delete root;
	}
}

//destructor
BinarySearchTree::~BinarySearchTree()
{
	del(root);
}



// **Methods**

void BinarySearchTree::insert(std::string word)
{
	insert_worker(&root, word);
}

bool BinarySearchTree::exists(std::string word) const
{
	return check(root, word);
	
}

// for inorder method the pop back is used to bring back the space.
std::string BinarySearchTree::inorder() const
{
	string value = inorder_worker(root);
	if (value.length() > 1)
		value.pop_back();
	return value; 
	
}

// for preorder method the pop back is used to bring back the space.
std::string BinarySearchTree::preorder() const
{
	string value = prehelper(root);
	if (value.length() > 1)
		value.pop_back();
	return value;
	
}

// for postorder method the pop back is used to bring back the space.
std::string BinarySearchTree::postorder() const
{
	string value = posthelper(root);
	if (value.length() > 1)
		value.pop_back();
	return value;
	
}
    
// **Operator overloads**
    
// temporary tree created and all words inserted into it .
BinarySearchTree& BinarySearchTree::operator+(std::string word)
{
	BinarySearchTree *temp = new BinarySearchTree(*this);
	temp->insert(word);
	return *temp; 
}
//called destructor function on the tree
//then deep copy function to copy all content from root to rhs
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)
{ 

	del(this->root);
	deepcopy(rhs.root, root);
	return *this;
}
/*


Functions and method for word count



*/

//count helper function , if the root is nullptr nothing is returned else the words orderly and with count returned
std::string count_helper(Node* root) {
	if (root == nullptr)
		return "";
	else {
		return count_helper(root->left) + root->word + ": " + std::to_string(root->count) + "\n" + count_helper(root->right);
	}
}
std::string BinarySearchTree::count() const {
	return count_helper(root);
}