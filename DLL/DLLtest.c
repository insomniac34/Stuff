//a rudimentary demonstration of the usage of my C linked list.
//written by Tyler Raborn

#include <stdlib.h>
#include <stdio.h>
#include "DLL.h"

DLL myDLL;



void deleteValue()
{
	char* string;
	printf("Enter the string you wish to delete: \n");
	scanf("%s", string);
	delete_node(&myDLL, string);
}

void addValue()
{
	char* string;
	printf("Enter the string you wish to add: \n");
	scanf("%s", string);
	insert_front(&myDLL, string);
}

void prompt()
{
	int p;
	printf("\nOPTIONS: To add a value to the list, type 0. To delete a value in the list, type 1. To view the contents of the list, type 2. To exit, type 3.\n");
	scanf("%d", &p);
	if (p==3) exit(1);
	if (p==0) addValue();
	if (p==1) deleteValue();
	if (p==2) printList(&myDLL);
	prompt();
}

int main(int argc, char** argv)
{

	

	//initialize(myDLL);

	int i = 0;
	for(i=1;i<=argc-1;i++)
	{
		insert_front(&myDLL, argv[i]);	
	}

	prompt();

	/*printList(&myDLL);

	pop_front(&myDLL);

	printList(&myDLL);

	pop_back(&myDLL);

	printList(&myDLL);

	delete_node(&myDLL, "is");

	printList(&myDLL);*/

	//myDLL = (DLL*)malloc(sizeof(DLL));
	//myDLL->insert_head(argv[1]);
	//myDLL->print();

	return 0;
}

