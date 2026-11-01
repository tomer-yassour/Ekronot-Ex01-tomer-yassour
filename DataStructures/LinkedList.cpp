#include <iostream>
#include "LinkedList.h"


void addNode(Node* head, int newValue)
{
	Node* newNode = new Node;
	newNode->num = newValue;
	newNode->prev = head;
	head = newNode;
}

void removeNode(Node* head)
{


	


