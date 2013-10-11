/*
	Takes in a variable number of strings as cmd line args and stores them in a simple doubly-linked list

	@author: Tyler Raborn
*/

#include <stdlib.h>
#include <stdio.h>

#define EXECUTION_HALT 0
#define true 1
#define false 0

typedef struct Node
{
	char* data;
	struct Node* next;
	struct Node* prev;
} Node;

int main(int argc, char** argv)
{
	Node* head; //ptr to head of list
	Node* tail;

	int i = 1;
	
	//create list head
	printf("\nAdding %s to Linked List...", argv[i]);
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	(newNode->data) = argv[1];
	(newNode->next) = NULL;
	(newNode->prev) = NULL;
	head = newNode;
	
	//iterate over all names in argv and add to list
	for(i=2;i<=argc-1;i++)
	{
		printf("\nAdding %s to Linked List...", argv[i]);

		Node* curNode;
		curNode = (Node*)malloc(sizeof(Node));
		(curNode->data) = argv[i];
		(newNode->next) = curNode;
		(curNode->next) = NULL; 
		(curNode->prev) = newNode;
		newNode = curNode;
		tail = curNode;
	}

	//iterate over the Linked List and print the names stored in each node...
	printf("\n\nNow printing the contents of the Linked List: ");
	Node* tempNode;
	tempNode = head;
	//printf("\n%s", (tempNode->data));

	//while((tempNode->next)!=NULL)
	while (tempNode != NULL)
	{
		printf("\n%s", (tempNode->data));
		tempNode = (tempNode->next);
	}

	printf("\n\nNow printing the contents of the Linked List backwards: ");
	tempNode = tail;
	while (tempNode != NULL)
	{
		printf("\n%s", (tempNode->data));
		tempNode = (tempNode->prev);
	}

	return EXECUTION_HALT;
}

