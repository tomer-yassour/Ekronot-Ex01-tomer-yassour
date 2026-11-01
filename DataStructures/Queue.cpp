#include <iostream>
#include "Queue.h"

const unsigned int maxSize = 5;

void initQueue(Queue* q, unsigned int size)
{
	Node* rear = new Node;
	Node* front = new Node;
	Node* current = new Node;
	//making sure q is pointing at rear and front
	q->rear = rear;
	q->front = front;
	rear->num = size;
	rear->next = nullptr;
	front->num = 1;
	front->next = current;

	for (unsigned int i = 2; i < size - 1; i++)
	{
		//creating a node every cycle
		current->num = i;
		current->next = new Node;
		current = current->next;
	}
	current->num = size - 1;
	current->next = rear;
}

void cleanQueue(Queue* q)
{
	Node* current = q->front;
	Node* temp;

	while (current != nullptr)
	{
		temp = current->next;
		delete current;
		current = nullptr;
		current = temp;
	}
	q->front = nullptr;
	q->rear = nullptr;
}

void enqueue(Queue* q, unsigned int newValue)
{
	Node* newNode = new Node;
	newNode->num = newValue;
	q->rear->next = newNode;
	q->rear = newNode;
	newNode->next = nullptr;
}

int dequeue(Queue* q)
{
	int returnValue = -1;
	Node* newFront = q->front->next;

	if (isEmpty(q))
	{
		returnValue = -1;
	}

	else
	{
		delete q->front;
		q->front = nullptr;
		q->front = newFront;
		returnValue = newFront->num;
	}
	return returnValue;
}

bool isEmpty(Queue* s)
{
	return s->front == nullptr;
}

bool isFull(Queue* s)
{
	int count = 0;
	Node* current = s->front;

	while (current != nullptr)
	{
		count++;
		current = current->next;
	}

	return count >= maxSize;
}