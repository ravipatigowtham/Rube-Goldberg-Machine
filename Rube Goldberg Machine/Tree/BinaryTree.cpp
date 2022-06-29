#include "BinaryTree.hpp"

BinaryTree::BinaryTree(Node *val) 
{ 
		data = new Node();
		data->age = val->age;
     	strcpy(data->dob, val->dob);
     	strcpy(data->fname, val->fname);
     	strcpy(data->lname, val->lname);
     	data->next = NULL;
  
        // Left and right child for node to NULL as it is the first element to be inserted into tree
        left = NULL; 
        right = NULL;
		weight = 0; 
} 
    
void BinaryTree::setLeft (BinaryTree* l) 
{ 
		left  = l;
		weight++;
}
	
void BinaryTree::setRight(BinaryTree* r)
{
		right = r;
	    weight++;
} 
	
int BinaryTree::getWeight() 
{ 
		return weight; 
}
	
// insert a Node element into the Tree
void BinaryTree::insert(BinaryTree* bt) 
{
	        if(left == NULL){
	            setLeft(bt);
	        }else if(right == NULL){
	            setRight(bt);
	        }else{
	            if(left->getWeight() <= right->getWeight()){
	                left->insert(bt);
	                weight++;
	            }else{
	                right->insert(bt);
	                weight++;
	            }
	        }
	}
	
void BinaryTree::inOrderInsertToLL(BinaryTree *tree, LinkedList *ll) 
{
			// return if the current node is empty
			if (tree == NULL)
				return;
	
			// Traverse the tree in-order and add to Linked list
			inOrderInsertToLL(tree->left, ll);
			ll->insert(tree->data);	
			inOrderInsertToLL(tree->right, ll);
}		  

void BinaryTree::preorder(BinaryTree *tree) 
{
			// return if the current node is empty
			if (tree == NULL)
				return;
	
			// Display the data part of the root (or current node)
			cout << tree->data->fname << " " << tree->data->lname << " , "<<tree->data->age<<" , "<<tree->data->dob<<endl;
	
			// Traverse the left subtree
			preorder(tree->left);
	         
			// Traverse the right subtree
			preorder(tree->right);
}

void BinaryTree::postorder(BinaryTree *tree) 
{
			// return if the current node is empty
			if (tree == NULL)
				return;
	
			// Traverse the left subtree
			postorder(tree->left);
	         
			// Traverse the right subtree
			postorder(tree->right);
			// Display the data part of the root (or current node)
              cout << tree->data->fname << " " << tree->data->lname << " , "<<tree->data->age<<" , "<<tree->data->dob<<endl;	
}
