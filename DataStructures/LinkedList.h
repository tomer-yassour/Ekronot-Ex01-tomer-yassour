#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
	int num;
	Node* next;
}Node;

void addNode(Node* head, int newValue);
void removeNode(Node* head);



#endif // LINKEDLIST_H