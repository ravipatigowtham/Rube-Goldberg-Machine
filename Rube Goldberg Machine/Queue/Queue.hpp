#include<iostream>
#include"../include/Node.hpp"
using namespace std;

// Queue class stores two ends of queue: front and rear 
// and enqueues and dequeues elements

class Queue
{
	Node *front=NULL,*rear=NULL;
	public:
		void enqueue(Node*);
		Node* dequeue();
};
		

