#include "Queue.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

std::string removeElementsAndGetPrintedQueue(Queue* q)
{
	std::stringstream output;
	while (!isEmpty(q))
	{
		output << dequeue(q) << " ";
	}
	// removing the last letter (space)
	std::string outputString = output.str();
	outputString = outputString.substr(0, outputString.length() - 1);
	return outputString;
}

bool test1()
{
	bool result = false;

	try
	{
		// check basic data structure functions
		cout << 
			"*******************************\n"  << 
			"Test 1 - basic queue functions\n" << 
			"*******************************\n" << endl;
			
		Queue* q0;
		try
		{

			cout << " \nInitializing queue with size 5 ... \n \n" << endl;
			q0 = new Queue;
			initQueue(q0, 5);
		}
		catch(...)
		{
			// queue failed to initialize - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n" << endl;
			return 1111;
		}

		bool empty = isEmpty(q0);
		cout << "Checking if queue is empty ... \n";
		cout << "Running Test ... \t";

		if (empty)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			// queue is not empty - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: true\n" 
			<< "Got     : " << (empty ? "true" : "false") << " \n";
			cout << " \n" << endl;
			return 1112;
		}

		const std::string queue0elements = "1 4 9 16 25";

		cout << "Adding elements to queue ... " << queue0elements << "\n" << endl;

		for (int i = 0; i < 5; i++)
		{
			enqueue(q0, (i+1) * (i+1));
		}

		bool full = isFull(q0);
		cout << "Checking if queue is full ... \n";
		cout << "Running Test ... \t";

		if(full)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			// queue is not full - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: true\n"
				<< "Got     : " << (full ? "true" : "false") << " \n";
			cout << " \n" << endl;
			return 1113;
		}

		std::string output = removeElementsAndGetPrintedQueue(q0);
		cout << "Removing elements and printing queue ...\n";
		cout << "Running Test ... \t";

		if(output == queue0elements)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << queue0elements << "\n"
				<< "Got     : " << output
				<< " \n " << endl;
			cout << " \n" << endl;
			return 1114;
		}

		try
		{
			cout << "Cleaning queue...\n" << endl;
			cout << "Running Test ... \t";
			cleanQueue(q0);
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		catch(const std::exception& e)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n " << endl;
			cout << "Received the following error: " << e.what() << "\n"
				<< " \n " << endl;
			return 1115;
		}
		


		delete q0;
	}
	catch (...)
	{
		std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
		std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n.\n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" << 
			"3. Did you remember to initialize array before accessing it?";
		return 2;
	}

	return 0;

}


bool test2()
{
	bool result = false;

	try
	{
		// check basic data structure functions
		cout <<
			"*******************************\n" <<
			"Test 2 - two queues\n" <<
			"*******************************\n" << endl;
		
		Queue* q1;
		try
		{

			cout << " \nInitializing first queue with size 3 ... \n \n" << endl;
			q1 = new Queue;
			initQueue(q1, 3);
		}
		catch(...)
		{
			// queue failed to initialize - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n" << endl;
			return 1111;
		}

		const std::string queue1elements = "10 20 30";

		cout << "Adding elements to first queue ... " << queue1elements << "\n \n" << endl << endl;

		for (int i = 0; i < 3; i++)
		{
			enqueue(q1, (i + 1) * 10);
		}

		Queue* q2;
		try
		{

			cout << " \nInitializing second queue with size 5 ... \n \n" << endl;
			q2 = new Queue;
			initQueue(q2, 5);
		}
		catch(...)
		{
			// queue failed to initialize - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n" << endl;
			return 1121;
		}

		bool empty = isEmpty(q2);
		cout << "Running Test ... \t";
		if (empty)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			// queue is not empty - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: true\n" 
			<< "Got     : " << (empty ? "true" : "false") << " \n";
			cout << " \n" << endl;
			return 1112;
		}

		const std::string queue2elements = "1 2 3 4 5";

		cout << "Adding elements to second queue ... " << queue2elements << "\n" << endl;
		cout << "Running Test ... \t";
		for (int i = 0; i < 5; i++)
		{
			enqueue(q2, i + 1 );
		}

		bool full = isFull(q2);


		if(full)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			// queue is not full - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: true\n"
				<< "Got     : " << (full ? "true" : "false") << " \n";
			cout << " \n" << endl;
			return 1113;
		}

		cout << "Using dequeue() on first queue and printing element... \n" << endl;
		cout << "Running Test ... \t";
		int dequeueResult = dequeue(q1);

		if(dequeueResult == 10)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: 10\n"
				<< "Got     : " << dequeueResult << " \n";
			cout << " \n" << endl;
			return 1122;
		}

		cout << "Using dequeue() twice on second queue and printing queue... \n" << endl;
		cout << "Running Test ... \t";
		dequeue(q2);
		dequeue(q2);

		std::string q2output = removeElementsAndGetPrintedQueue(q2);


		if(q2output == "3 4 5")
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: 3 4 5\n"
				<< "Got     : " << q2output	<< " \n" << endl;
			cout << " \n" << endl;
			return 1114;
		}

		cout << "Checking if first queue is empty ... \n";
		cout << "Running Test ... \t";
		empty = isEmpty(q1);
		
		if (!empty)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			// queue is empty - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: false\n"
				<< "Got     : " << (empty ? "true" : "false") << " \n" << endl;
			cout << " \n" << endl;
			return 1123;
		}

		try
		{
			cout << "Cleaning first queue...\n" << endl;
			cout << "Running Test ... \t";
			cleanQueue(q1);
			delete q1;
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;

			cout << "Cleaning second queue...\n" << endl;
			cout << "Running Test ... \t";
			cleanQueue(q2);
			delete q2;
		}
		catch(const std::exception& e)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n " << endl;
			cout << "Received the following error: " << e.what() << "\n"
				<< " \n " << endl;
			return 1115;
		}
		cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
	}
	catch (...)
	{
		std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
		std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n \n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" << 
			"3. Did you remember to initialize array before accessing it?";
		return 2;
	}

	return 0;

}

int main(int argc, char* argv[])
{
	// check num of arguments
	if (argc < 2 || argc > 3)
	{
		std::cerr <<
			"Wrong number of main arguments\n" <<
			"Expected 1 argument - test number\n" <<
			"Usage example: ./Ex1Part1Test 3" << std::endl;
		exit(3);
	}

	if (atoi(argv[1]) == 1)
	{
		bool result = test1();
		cout << (result == 0 ? "\033[1;32m \n****** Part 1 Test 1 Passed ******\033[0m\n \n" : "\033[1;31mPart 1 Test 1 Failed\033[0m\n \n") << endl;
		return result;
	}
	else if (atoi(argv[1]) == 2)
	{
		bool result = test2();
		cout << (result == 0 ? "\033[1;32m \n****** Part 1 Test 2 Passed ******\033[0m\n \n" : "\033[1;31mPart 1 Test 1 Failed\033[0m\n \n") << endl;
		return result;
	}

	return 0;
}
