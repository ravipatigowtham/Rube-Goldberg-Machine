#include<fstream>
#include<iostream>
#include<string>
#include<conio.h>
#include<cstring>
#include "Queue/Queue.hpp"
#include "Stack/Stack.hpp"
#include "Tree/BinaryTree.hpp"
#include "LinkedList/LinkedList.hpp"

using namespace std;
void print (Node *data) 
{
	cout << data->fname << " " << data->lname << " , " << data->age << " , " << data->dob << endl;
}

int main() {
	char temp;
	string 		line;
    ifstream 	infile;
	Queue 		myQueue;
	Stack		myStack;
	Node 		tempNode;
	Node 		*nodePtr = NULL;
	int 		count = 0, tmp_count = 0;
	BinaryTree	*myTree = NULL;
	LinkedList	myLinkedList ;

	// Read the file from the root folder of the project
	infile.open("InputFile.txt");
	
	// read all the entries from yhe file and enqueue into a queue
	while(infile.good())
	{
		infile>>tempNode.fname;
		infile>>tempNode.lname;
		infile>>tempNode.age;
		// To remove the comma
		infile>>temp;
		infile>>tempNode.dob;
		tempNode.lname[strlen(tempNode.lname)-1]=0;
		myQueue.enqueue(&tempNode);
		count++;
	}
	infile.close();
	
	tmp_count = count;
	
	// Dequeue each element from the queue, print each item, and requeue each item.
	cout << "Dequeing, printing and Requeing: " << endl << endl;
	while(tmp_count > 0) {
		nodePtr = myQueue.dequeue();
		print(nodePtr);
		myQueue.enqueue(nodePtr);
		delete nodePtr;
		tmp_count--;
	}
	
	// Ask the user to press any key to continue the processing.
	cout << "Enter any key to proceed: " << endl;
	getch();
	cout<<"\n";
	
	// reverse the order of the data in the queue by dequeuing each element and pushing them onto a stack.
	while(nodePtr = myQueue.dequeue()) {
		myStack.push(nodePtr);
		delete nodePtr;
	}
	
	// pop off each element of the stack and re-queue each element back into a queue ADT,
	while(nodePtr = myStack.pop()) {
		myQueue.enqueue(nodePtr);
		delete nodePtr;
	}

	tmp_count = count;
	// dequeue each element from  queue, print, ask  user to press any key to continue. Requeue each item to preserve the queue.
	while(tmp_count > 0) {
		nodePtr = myQueue.dequeue();
		print(nodePtr);
		cout << "Enter any key to proceed: " << endl;
		getch();
		myQueue.enqueue(nodePtr);
		delete nodePtr;
		tmp_count--;
	}
	cout<<"\n";
	// Dequeue elements from the queue and add to an unordered binary tree
	while(nodePtr = myQueue.dequeue()) {
		if(!myTree) {
			myTree = new BinaryTree(nodePtr);
			delete nodePtr;
			continue;
		}
		BinaryTree *tempTree = new BinaryTree(nodePtr);
		myTree->insert(tempTree);
		delete nodePtr;
	}
	
	// Print the contents of the tree in pre-order
    cout<<"Contents of Tree in preorder: "<<endl;
	myTree->preorder(myTree);
	
  	cout << "Enter any key to proceed: " << endl;
	getch();
	cout<<"\n";
	
	// Print the contents of the tree in post-order
	cout<<"Contents of Tree in postorder"<<endl;
	myTree->postorder(myTree);	
	
  	cout << "Enter any key to proceed: " << endl;
	getch();
	cout<<"\n";
	// inserting the details from tree to linked list using in order traversal
	myTree->inOrderInsertToLL(myTree, &myLinkedList);	
   
   	// print the contents of the linked list
   	cout<<"Linked list after insertion"<<endl;
   	myLinkedList.Print();
   	
   	cout << "Enter any key to proceed: " << endl;
	getch();
   cout<<"\n";
     // sorting the names in the list using quick sort (using fname as criteria for sorting)
   	myLinkedList.quickSort();
   	
	cout << "Linked list after quicksort: " << endl;
	myLinkedList.Print();
   	
	cout << "Enter any key to proceed: " << endl;
	getch();
	cout<<"\n";
	
	// Allow the user to interactively enter another name, age, and birthday.r 
	Node info;
	cout<<"Enter another name with proper upper and lowecase combination as <firatname> <lastname>: ";
    cin>>info.fname;
    cin>>info.lname;
    cout<<"Enter age: ";
    cin>>info.age;
    cout<<"Enter date of birth in mm-dd-yy format: ";
    cin>>info.dob;
    
    // Insert the new entry in its proper position in the sorted linked list
    myLinkedList.insertInSortedList(&info);
    
    cout << "Linked list after inserting new element in proper position" << endl;
	myLinkedList.Print();
   	cout << "Enter any key to proceed: " << endl;
	getch();
	
	return 0;

}
 

