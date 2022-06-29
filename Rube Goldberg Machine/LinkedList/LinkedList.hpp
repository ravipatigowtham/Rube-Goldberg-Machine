#ifndef __LINKEDLIST__
#define __LINKEDLIST__
#include "../include/Node.hpp"
#include <iostream>
#include <cstring>
using namespace std;

//LinkedList classstores front and tail of the list and inserts elements into the list and sorts them
class LinkedList
{
	private:
		Node *head;
		Node *tail;
		public:
			LinkedList() {
				head = tail = NULL;
				cout << "head is NULL" << endl;
			}
		void insert(Node *);
		void Print();
		void quickSort();
		Node* quickSortRecur(Node *head, Node *end);
		Node* partition(Node *head, Node *end, Node **newHead, Node **newEnd);
		Node* getTail(Node *cur);
		void insertInSortedList(Node *);
};
#endif
