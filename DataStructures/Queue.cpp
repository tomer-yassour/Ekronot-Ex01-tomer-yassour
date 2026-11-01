#include <iostream>
#include "Queue.h"

const unsigned int maxSize = 5;
void printQueue(Queue* q);
int main()
{
	Queue *q0 = new Queue;
	initQueue(q0, maxSize);
	std::cout << "initQueue: " << q0->rear->num << std::endl;

	printQueue(q0);

	enqueue(q0, 32);
	std::cout << "enqueue: " << q0->rear->num << std::endl;
	printQueue(q0);

	dequeue(q0);
	std::cout << "dequeue: " << q0->rear->num << std::endl;

	std::cout << "is it empty: " << isEmpty(q0) << std::endl;
	std::cout << "is it full: " << isFull(q0) << std::endl;

	cleanQueue(q0);
	if (q0->front == nullptr && q0->rear == nullptr)
	{
		std::cout << "success" << std::endl;
	}

	std::cout << "is it empty: " << isEmpty(q0) << std::endl;
	std::cout << "is it full: " << isFull(q0) << std::endl;

	return 0;
}

void printQueue(Queue* q)
{
	Node* current = q->front;
	while (current != nullptr)
	{
		std::cout << current->num;

		if (current->next != nullptr)
			std::cout << " -> ";
		current = current->next;
	}
	std::cout << std::endl;
}

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
	//delete current;
	//current = nullptr;
	//std::cout << q->front->next->num << std::endl;

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
		std::cout << "isEmpty" << std::endl;

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