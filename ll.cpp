#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
}*head = NULL;

node* createNewNode(int value)
{
	node *newNode = new node();
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void insertAtEnd(int data)
{
	node *newNode = createNewNode(data);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	node *ptr;
	for(ptr = head;ptr->next!=NULL;ptr=ptr->next);
	ptr->next = newNode;	
} 
void insertAtBeginning(int data)
{
	node *newNode = createNewNode(data);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;
}
void displayLL()
{
	for(node *ptr =head;ptr!=NULL;ptr = ptr->next)
		cout<<ptr->data;
}

int  main()
{
	insertAtEnd(2);
	insertAtEnd(4);
	insertAtEnd(7);
	displayLL();
}
