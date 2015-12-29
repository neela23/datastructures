#include<iostream>

struct AdjListNode
{
	int data;
	AdjListNode *next;
};

struct AdjList
{
	AdjListNode *head;
};

struct Graph
{
	int V;
	AdjList* array;
};


int main()
{
	std::cout<<"Hello World\n Test";
	return 0;
}
