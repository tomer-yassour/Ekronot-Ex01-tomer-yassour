#include <iostream>
#include "Queue.h"

const unsigned int maxSize = 5;
int count = 0;

int main()
{
	Queue *q0 = new Queue;
	initQueue(q0, maxSize);
	std::cout << "initQueue: " << q0->prev->next->num << std::endl;

	enqueue(q0, 32);
	std::cout << "enqueue: " << q0->prev->num << std::endl;

	dequeue(q0);
	std::cout << "dequeue: " << q0->next->num << std::endl;

	std::cout << "is it empty: " << isEmpty(q0) << std::endl;
	std::cout << "is it full: " << isFull(q0) << std::endl;

	cleanQueue(q0);
	if (q0->prev == nullptr && q0->next == nullptr)
	{
		std::cout << "success" << std::endl;
	}

	std::cout << "is it empty: " << isEmpty(q0) << std::endl;
	std::cout << "is it full: " << isFull(q0) << std::endl;

	return 0;
}

void initQueue(Queue* q, unsigned int size)
{
	Queue* rear = new Queue;
	Queue* front = new Queue;
	Queue* current = new Queue;
	//making sure q is pointing at rear and front
	q->num = 0;
	q->prev = rear;
	rear->num = 1;
	rear->next = current;
	q->next = front;
	front->num = size;
	current->prev = rear;

	for (unsigned int i = 2; i < size - 1; i++)
	{
		//creating a node every cycle
		current->num = i;
		current->next = new Queue;
		current->next->prev = current;
		current = current->next;
		count++;
	}
	current->num = size - 1;
	current->next = front;
	front->prev = current;
}

void cleanQueue(Queue* q)
{
	Queue* current = q->prev;
	Queue* temp = new Queue;

	while (current->next != nullptr)
	{
		temp = current->next;
		delete current;
		current = nullptr;
		current = temp;
	}
	count = 0;
}

void enqueue(Queue* q, unsigned int newValue)
{
	Queue* newNode = new Queue;
	newNode->num = newValue;
	newNode->next = q->prev;
	q->prev->prev = newNode;
	q->prev = newNode;
	count++;
}

int dequeue(Queue* q)
{
	int returnValue = -1;
	Queue* currentFront = q->next;
	Queue* newFront = q->next->prev;

	if (isEmpty(q))
	{
		returnValue = -1;
	}

	else
	{
		delete currentFront;
		currentFront = nullptr;
		q->next = newFront;
		returnValue = newFront->num;
		count--;
	}
	return returnValue;
}

bool isEmpty(Queue* s)
{
	return count == 0;
}

bool isFull(Queue* s)
{
	return count >= maxSize;
}