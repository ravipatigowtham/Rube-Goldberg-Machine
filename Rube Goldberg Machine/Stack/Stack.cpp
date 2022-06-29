#include<iostream>
#include <string.h>
#include "../include/Node.hpp"
#include "Stack.hpp"
using namespace std;

//pushes a Node element to the top of the stack and updates top
void Stack:: push(Node *data) {
    Node* temp= new Node();
    temp->age = data->age;
    strcpy(temp->dob, data->dob);
    strcpy(temp->lname, data->lname);
    strcpy(temp->fname, data->fname);
    temp->next = NULL;
     	
    temp->next = top;    
    top = temp;  
}  

// pop an element of the top of the stack and return it
Node* Stack:: pop() {
	Node* temp;  
    if (top == NULL) {  
        return NULL;  
	}
	temp = top;  
    top = top->next;   
    temp->next = NULL;  
	return temp;  
}
