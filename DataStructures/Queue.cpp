#include <iostream>
#include "Queue.h"

int main()
{
	Queue *q0 = new Queue;
	initQueue(q0, 5);
	std::cout << q0->prev->num << std::endl;
	cleanQueue(q0);
	if (q0 == nullptr)
	{
		std::cout << "success" << std::endl;
	}



	return 0;
}

void initQueue(Queue* q, unsigned int size)
{
	Queue* current = new Queue;
	q->num = size;
	q->prev = current;

	for (unsigned int i = size - 1; i > 0; i--)
	{
		//if (i > 2)
		//{
		//	std::cout << current->next << std::endl;
		//	current->next = new Queue;
		//	std::cout << "created new queue for current->next" << std::endl;
		//	current->next->prev = current;
		//	std::cout << "current->next->prev" << std::endl;
		//}
		current->num = i;
		current->prev = new Queue;
		current = current->prev;
	}
}

void cleanQueue(Queue* q)
{
	Queue* current = new Queue;
	Queue* temp = new Queue;
	current = q;
	std::cout << "in func" << std::endl;
	while (current->prev != nullptr)
	{
		temp = current->prev;
		delete current;
		current = nullptr;
		std::cout << "deleted current" << temp->num << std::endl;
		current = temp;
	}
	std::cout << "end of while" << std::endl;
	delete q;
	q = nullptr;
	std::cout << "end of func" << std::endl;
}