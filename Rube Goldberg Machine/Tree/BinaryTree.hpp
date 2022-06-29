#include <iostream>
#include "../include/Node.hpp"
#include "../LinkedList/LinkedList.hpp"
#include <cstring>
using namespace std;

class BinaryTree  
{ 
private:
  Node* 		data; 
  BinaryTree*	left; 
  BinaryTree*	right; 
  int 			weight;
  
public:
    BinaryTree(Node *val);
	// Set element to the left
    void setLeft (BinaryTree* l);
    
	// Set element to the right
	void setRight(BinaryTree* r);

	// Balance the tree
	int getWeight();

	void insert(BinaryTree* bt);

	void inOrderInsertToLL(BinaryTree*, LinkedList*);

	void preorder(BinaryTree *tree);

	void postorder(BinaryTree *tree);

}; 

