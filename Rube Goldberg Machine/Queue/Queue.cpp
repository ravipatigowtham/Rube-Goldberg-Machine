#include<iostream>
#include <string.h>
#include "../include/Node.hpp"
#include "Queue.hpp"
using namespace std;

void Queue::enqueue(Node *data) 
{
		Node *temp = new Node();
		temp->age = data->age;
     	strcpy(temp->dob, data->dob);
     	strcpy(temp->fname, data->fname);
     	strcpy(temp->lname, data->lname);
     	temp->next = NULL;
		
		if (front == NULL) {
     		 front = rear = temp;
     		 return;
     	} 
     	rear->next = temp;
     	rear = temp;
}
 
Node* Queue:: dequeue() 
{
	// Queue is empty
    if (front == NULL) {
    	return NULL;
	}
    Node* temp = front; 
    front = front->next; 
 	if(front == NULL)
 		rear = NULL;
	return temp;		
}
