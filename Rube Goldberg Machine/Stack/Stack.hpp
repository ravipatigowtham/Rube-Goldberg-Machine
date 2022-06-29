#include<iostream>
#include"../include/Node.hpp"
using namespace std;

//Stack class stores top of the stack 
// and pushes and pops elements
class Stack
{
	Node *top=NULL;
	public:
		void push(Node*);
		Node* pop();
};
