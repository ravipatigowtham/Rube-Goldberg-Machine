#ifndef __NODE__
#define __NODE__
// Node structure stores the details of a person
struct Node
{
	char 	fname[30];
	char 	lname[30];
	int 	age;
	char 	dob[30];
	Node 	*next;
};
#endif
