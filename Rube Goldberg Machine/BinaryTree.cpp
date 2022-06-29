#include <iostream>
#include "../include/Node.hpp"
using namespace std;
/*
struct Node {
	char fname[30];
	char lname[30];
	int age;
	char dob[30];
	node *left;
	node *right;
};
*/
class BinaryTree {
	private:
	     BinaryTree right;
	     BinaryTree left;
	     Node* data;
	     int weight;
    public:
    	void setLeft(BinaryTree);
    	void setRight(BinaryTree);
    	int getWeight();
    	void Insert(BinaryTree);
		BinaryTree(Node* s) { 
	        data = new Node();
	        strcpy(data->fname, s->fname);
	        strcpy(data->lname, s->lname);
	        strcpy(data->dob, s->dob);
	        data->age=s->age;
	        right = null;
	        left = null; 
	        weight = 1;
    	}    

		void setLeft (BinaryTree l){ 
	        left  = l;
	        weight++;
	    }
	    void setRight(BinaryTree r){
	        right = r;
	        weight++;
	    } 
	    int getWeight(){ return weight; }
	    
	    void insert(BinaryTree bt){
	        if(left == null){
	            setLeft(bt);
	        }else if(right == null){
	            setRight(bt);
	        }else{
	            if(left.getWeight() <= right.getWeight()){
	                left.insert(bt);
	                weight++;
	            }else{
	                right.insert(bt);
	                weight++;
	            }
	        }
	    }
	    
		void inorder() {
			// return if the current node is empty
			if (data == NULL)
				return;
	
			// Traverse the left subtree
			inorder(data->left);
	
			// Display the data part of the root (or current node)
			cout << data->fname << " " << data->lname << ", ";
	
			// Traverse the right subtree
			inorder(root->right);
		}		  
	
};
