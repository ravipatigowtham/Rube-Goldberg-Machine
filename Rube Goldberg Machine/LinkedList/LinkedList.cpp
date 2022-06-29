#include "LinkedList.hpp"
#include <iostream>
#include <cstring>
using namespace std;

// insert a Npde elemen to the end of the list
void LinkedList::insert(Node *cnode)
{
	Node *temp=new Node();
	temp->age = cnode->age;
    strcpy(temp->dob, cnode->dob);
    strcpy(temp->fname,cnode->fname);
    strcpy(temp->lname,cnode->lname);
	cnode->next=NULL;
    
	if(head==NULL) {
	 	head=tail=cnode;
    } else {
 		tail->next = cnode;
 		tail = cnode;
	} 
}

void LinkedList::Print()
{
	Node *temp=head;
	while(temp!=NULL)
	{
	cout<<temp->fname<<" "<<temp->lname<<" , "<<temp->age<<" , "<<temp->dob<<endl;
     temp=temp->next;	
	}
}

// Returns the last node of the list 
 Node* LinkedList::getTail( Node *cur) 
{ 
    while (cur != NULL && cur->next != NULL) 
        cur = cur->next; 
    return cur; 
} 
  
// Partitions the list taking the last element as the pivot 
 Node* LinkedList::partition( Node *head,  Node *end,  Node **newHead,  Node **newEnd) 
{ 
     Node *pivot = end; 
     Node *prev = NULL, *cur = head, *tail = pivot; 
  
    // During partition, both the head and end of the list might change 
    // which is updated in the newHead and newEnd variables 
    while (cur != pivot) 
    { 
        if (strcmp(cur->fname, pivot->fname) < 0) 
        { 
            // First node that has a value less than the pivot - becomes 
            // the new head 
            if ((*newHead) == NULL) 
                (*newHead) = cur; 
  
            prev = cur;  
            cur = cur->next; 
        } 
        else // If cur node is greater than pivot 
        { 
            // Move cur node to next of tail, and change tail 
            if (prev) 
                prev->next = cur->next; 
            Node *tmp = cur->next; 
            cur->next = NULL; 
            tail->next = cur; 
            tail = cur; 
            cur = tmp; 
        } 
    } 
  
    // If the pivot data is the smallest element in the current list, 
    // pivot becomes the head 
    if ((*newHead) == NULL) 
        (*newHead) = pivot; 
  
    // Update newEnd to the current last node 
    (*newEnd) = tail; 
  
    // Return the pivot node 
    return pivot; 
} 
  
  
//here the sorting happens exclusive of the end node 
Node* LinkedList::quickSortRecur( Node *head,  Node *end) 
{ 
    // base condition 
    if (!head || head == end) 
        return head; 
  
    Node *newHead = NULL, *newEnd = NULL; 
  
    // Partition the list, newHead and newEnd will be updated 
    // by the partition function 
    Node *pivot = partition(head, end, &newHead, &newEnd); 
  
    // If pivot is the smallest element - no need to recur for 
    // the left part. 
    if (newHead != pivot) 
    { 
        // Set the node before the pivot node as NULL 
        Node *tmp = newHead; 
        while (tmp->next != pivot) 
            tmp = tmp->next; 
        tmp->next = NULL; 
  
        // Recur for the list before pivot 
        newHead = quickSortRecur(newHead, tmp); 
  
        // Change next of last node of the left half to pivot 
        tmp = getTail(newHead); 
        tmp->next = pivot; 
    } 
  
    // Recur for the list after the pivot element 
    pivot->next = quickSortRecur(pivot->next, newEnd); 
  
    return newHead; 
} 
  
// The main function for quick sort. This is a wrapper over recursive 
// function quickSortRecur() 
void LinkedList::quickSort() 
{ 
     head = quickSortRecur(head, getTail(head)); 
    return; 
} 

// Insert element into the correct position in the list sorted in ascending order based on first name
void LinkedList::insertInSortedList(Node *data) 
{
	Node *temp=head,*prev=NULL;
	while(temp!=NULL)
	{
		if(strcmp(data->fname,temp->fname)<0)
		{
			cout << "data->fname: " << data->fname << " temp->fname: " << temp->fname << endl;
			data->next=temp;
			if(prev==NULL)
			{
				head=data;
			}
			else
			{
				prev->next=data;
			}
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	if(temp == NULL) {
		cout << "Adding at the end" << endl;
		prev->next = data;
		data->next = NULL;
		tail = data;
	}
}
