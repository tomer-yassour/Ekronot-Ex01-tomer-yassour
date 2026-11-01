#include <iostream>
#include "LinkedList.h"


void addNode(Node* head, int newValue)
{
	Node* newNode = new Node;
	newNode->num = newValue;
	newNode->next = head;
	head = newNode;
}

void removeNode(Node* head)
{
	Node* temp = head->next;
	delete head;
	head = nullptr;
	head = temp;
}




	


