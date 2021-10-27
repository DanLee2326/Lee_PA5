#include "Test.hpp"

void runQueue(void)
{
	Queue expressLane;
	Queue normalLane;

	int t = 0, sim = 0;
	cout << "Input the run time for the simulation in minutes: ";
	cin >> t; 
	cout << endl;
	
	srand(time(0));

	int ArrivalTime = rand() % 5 + 1;
	int curServiceTime = 0;
	int curCustomer = 0;
	int finServiceTime = 0;
	int lastCustomer = 0;
	int tTime = 0;
	
	int ArrivalTime2 = rand() % 6 + 3;
	int curServiceTime2 = 0;
	int curCustomer2 = 0;
	int finServiceTime2 = 0;
	int tTime2 = 0;

	while (sim <= t)
	{
		while ((curServiceTime != 0 || expressLane.isEmpty()) && (curServiceTime2 != 0 || normalLane.isEmpty()) && sim < t)
		{
			sim++;
			ArrivalTime--;
			ArrivalTime2--;
			curServiceTime = getMax(curServiceTime - 1, 0);
			finServiceTime = getMax(finServiceTime - 1, 0);
			curServiceTime2 = getMax(curServiceTime2 - 1, 0);
			finServiceTime2 = getMax(finServiceTime2 - 1, 0);

			if (ArrivalTime == 0)
			{
				Data express;

				ArrivalTime = rand() % 5 + 1;
				express.setServiceTime(rand() % 5 + 1);
				express.setCustomerNumber(lastCustomer + 1);
				lastCustomer++;

				cout << "Customer #" << lastCustomer << " is in the express lane at minute: " << sim << endl;

				finServiceTime += express.getServiceTime();
				express.setTotalTime(finServiceTime);

				expressLane.enqueue(express);
			}

			if (ArrivalTime2 == 0)
			{
				Data normal;

				ArrivalTime2 = rand() % 6 + 3;
				normal.setServiceTime(rand() % 6 + 3);
				normal.setCustomerNumber(lastCustomer + 1);
				lastCustomer++;

				cout << "Customer #" << lastCustomer << " is in the normal lane at minute: " << sim << endl;

				finServiceTime2 += normal.getServiceTime();
				normal.setTotalTime(finServiceTime2);

				normalLane.enqueue(normal);
			}

			if (sim % 10 == 0)
			{
				cout << endl << "Express Queue:" << endl;
				expressLane.printQueueRecursive();
				cout << endl << "Normal Queue:" << endl ;
				normalLane.printQueueRecursive();
				cout << endl;
			}
		}

		if (sim >= t)
		{
			break;
		}

		if (curServiceTime == 0 && !expressLane.isEmpty())
		{
			if (curCustomer != 0)
			{
				cout << "Customer #" << curCustomer << " was in the express lane for " << tTime << " minutes" << endl;
			}

			Data* temp = expressLane.dequeue();
			curCustomer = temp->getCustomerNumber();
			curServiceTime = temp->getServiceTime();
			tTime = temp->getTotalTime();
		}

		if (curServiceTime2 == 0 && !normalLane.isEmpty())
		{
			if (curCustomer2 != 0)
			{
				cout << "Customer #" << curCustomer2 << " was in the normal lane for " << tTime2 << " minutes" << endl;
		
			}

			Data* temp2 = normalLane.dequeue();
			curCustomer2 = temp2->getCustomerNumber();
			curServiceTime2 = temp2->getServiceTime();
			tTime2 = temp2->getTotalTime();
		}
	}
}

int getMax(int n1, int n2)
{
	if (n1 >= n2)
	{
		return n1;
	}
	else
	{
		return n2;
	}
}

void Test::testEnqueueEmptyQueue(void)
{
	cout << endl << "-----------------------------------------------------------------------------" << endl;
	cout << "Tests:" << endl << endl;

	Queue eEmpty;
	
	cout << "Testing enqueue on an empty queue:" << endl;

	if (eEmpty.isEmpty() == true)
	{
		cout << "Queue is Empty: " << endl;
		eEmpty.printQueueRecursive();
		cout << endl;
	}
	else
	{
		cout << "Queue is Not Empty: " << endl;
		eEmpty.printQueueRecursive();
		cout << endl;
	}

	cout << "Enqueue data of 1, 2, 3" << endl;
	if (eEmpty.enqueue(Data(1, 2, 3)) == true)
	{
		cout << "Enqueue Successful: " << endl;
		eEmpty.printQueueRecursive();
		cout << endl;
	}
	else
	{
		cout << "Enqueue Failed: " << endl;
		eEmpty.printQueueRecursive();
		cout << endl;
	}
}

void Test::testEnqueueOneNode(void)
{
	Queue eOne;
	eOne.enqueue(Data(1, 2, 3));

	cout << "Testing enqueue on a queue with one node:" << endl;

	if (eOne.isEmpty() == false)
	{
		cout << "Queue Has One Node: " << endl;
		eOne.printQueueRecursive();
		cout << endl;
	}
	else
	{
		cout << "Queue is Empty: " << endl;
		eOne.printQueueRecursive();
		cout << endl;
	}

	cout << "Enqueue data of 4, 5, 6" << endl;
	if (eOne.enqueue(Data(4, 5, 6)) == true)
	{
		cout << "Enqueue Successful: " << endl;
		eOne.printQueueRecursive();
		cout << endl;
	}
	else
	{
		cout << "Enqueue Failed: " << endl;
		eOne.printQueueRecursive();
		cout << endl;
	}
}

void Test::testDequeueOneNode(void)
{
	Queue dOne;
	dOne.enqueue(Data(1, 2, 3));

	cout << "Testing dequeue on a queue with one node:" << endl;

	if (dOne.isEmpty() == false)
	{
		cout << "Queue contains one node: " << endl;
		dOne.printQueueRecursive();
		cout << endl;
	}
	else
	{
		cout << "Queue is Empty" << endl;
	}

	cout << "Dequeue data of 1, 2, 3" << endl;
	dOne.dequeue();

	if (dOne.isEmpty() == true)
	{
		cout << "Dequeue Successful: " << endl;
		dOne.printQueueRecursive();
		cout << endl;
	}
	else
	{
		cout << "Dequeue Failed: " << endl;
		dOne.printQueueRecursive();
		cout << endl;
	}
}

void Test::testDequeueTwoNodes(void)
{
	Queue dTwo;
	dTwo.enqueue(Data(1, 2, 3));
	dTwo.enqueue(Data(4, 5, 6));

	cout << "Testing dequeue on a queue with two nodes:" << endl;

	if (dTwo.isEmpty() == false)
	{
		cout << "Queue contains two nodes: " << endl;
		dTwo.printQueueRecursive();
		cout << endl;
	}
	else
	{
		cout << "Queue is Empty or Only Has One Node: " << endl;
		dTwo.printQueueRecursive();
		cout << endl;
	}

	cout << "Dequeue data of 1, 2, 3 and 4, 5, 6" << endl;
	dTwo.dequeue();
	dTwo.dequeue();

	if (dTwo.isEmpty() == true)
	{
		cout << "Dequeue Successful: " << endl;
		dTwo.printQueueRecursive();
		cout << endl;
	}
	else
	{
		cout << "Dequeue Failed: " << endl;
		dTwo.printQueueRecursive();
		cout << endl;
	}
}

void Test::testRun24Hours(void)
{
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "24-hour Test Run:" << endl;
	timeSetFunction(1440);
}

void Test::timeSetFunction(int n)
{
	Queue expressLane;
	Queue normalLane;

	int t = n, sim = 0;

	srand(time(0));

	int ArrivalTime = rand() % 5 + 1;
	int curServiceTime = 0;
	int curCustomer = 0;
	int finServiceTime = 0;
	int lastCustomer = 0;
	int tTime = 0;

	int ArrivalTime2 = rand() % 6 + 3;
	int curServiceTime2 = 0;
	int curCustomer2 = 0;
	int finServiceTime2 = 0;
	int tTime2 = 0;

	while (sim <= t)
	{
		while ((curServiceTime != 0 || expressLane.isEmpty()) && (curServiceTime2 != 0 || normalLane.isEmpty()) && sim < t)
		{
			sim++;
			ArrivalTime--;
			ArrivalTime2--;
			curServiceTime = getMax(curServiceTime - 1, 0);
			finServiceTime = getMax(finServiceTime - 1, 0);
			curServiceTime2 = getMax(curServiceTime2 - 1, 0);
			finServiceTime2 = getMax(finServiceTime2 - 1, 0);

			if (ArrivalTime == 0)
			{
				Data express;

				ArrivalTime = rand() % 5 + 1;
				express.setServiceTime(rand() % 5 + 1);
				express.setCustomerNumber(lastCustomer + 1);
				lastCustomer++;

				cout << "Customer #" << lastCustomer << " is in the express lane at minute: " << sim << endl;

				finServiceTime += express.getServiceTime();
				express.setTotalTime(finServiceTime);

				expressLane.enqueue(express);
			}

			if (ArrivalTime2 == 0)
			{
				Data normal;

				ArrivalTime2 = rand() % 6 + 3;
				normal.setServiceTime(rand() % 6 + 3);
				normal.setCustomerNumber(lastCustomer + 1);
				lastCustomer++;

				cout << "Customer #" << lastCustomer << " is in the normal lane at minute: " << sim << endl;

				finServiceTime2 += normal.getServiceTime();
				normal.setTotalTime(finServiceTime2);

				normalLane.enqueue(normal);
			}

			if (sim % 10 == 0)
			{
				cout << endl << "Express Queue:" << endl;
				expressLane.printQueueRecursive();
				cout << endl << "Normal Queue:" << endl;
				normalLane.printQueueRecursive();
				cout << endl;
			}
		}

		if (sim >= t)
		{
			break;
		}

		if (curServiceTime == 0 && !expressLane.isEmpty())
		{
			if (curCustomer != 0)
			{
				cout << "Customer #" << curCustomer << " was in the express lane for " << tTime << " minutes" << endl;
			}

			Data* temp = expressLane.dequeue();
			curCustomer = temp->getCustomerNumber();
			curServiceTime = temp->getServiceTime();
			tTime = temp->getTotalTime();
		}

		if (curServiceTime2 == 0 && !normalLane.isEmpty())
		{
			if (curCustomer2 != 0)
			{
				cout << "Customer #" << curCustomer2 << " was in the normal lane for " << tTime2 << " minutes" << endl;

			}

			Data* temp2 = normalLane.dequeue();
			curCustomer2 = temp2->getCustomerNumber();
			curServiceTime2 = temp2->getServiceTime();
			tTime2 = temp2->getTotalTime();
		}
	}
}