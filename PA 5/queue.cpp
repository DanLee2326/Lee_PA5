#include "Queue.hpp"

Queue::Queue(QueueNode* pNewHead, QueueNode* pNewTail)
{
	this->pHead = pNewHead;
	this->pTail = pNewTail;
}

Queue::Queue(const Queue& copyQueue)
{
	
}

Queue::~Queue()
{
	while (pHead != nullptr)
	{
		dequeue();
	}
}

bool Queue::Queue::isEmpty() const
{
	return this->pHead == nullptr;
}

bool Queue::enqueue(const Data& pNewData)
{
	QueueNode* pMem = new QueueNode(pNewData); // replaces makeNode ()
	bool success = false;

	if (pMem != nullptr)
	{
		// allocated space for a Node
		success = true;

		// check if empty?
		if (this->pHead == nullptr)
		{
			// it's empty
			this->pHead = this->pTail = pMem;
		}
		else
		{
			// it's not empty
			this->pTail->setNextPtr(pMem);
			this->pTail = pMem;
		}
	}
	return success;
}

Data* Queue::dequeue()
{
	QueueNode* pTemp = this->pHead; // set to first node in queue
	Data* rData;

	// check if only 1 node in queue
	if (this->pHead == this->pTail)
	{
		//there's only 1 node in queue
		this->pHead = this->pHead = nullptr;
	}
	else // more than 1 node in queue
	{
		this->pHead = this->pHead->getNextPtr();
	}
	rData = pTemp->getData();
	delete pTemp;

	return rData;
}

void Queue::printQueueRecursive()
{
	printQueue(this->pHead);
}

void Queue::printQueue(QueueNode* pMem)
{
	Data* print;
	if (pMem == nullptr)
	{
		return;
	}
	else
	{
		print = pMem->getData();
		cout << "Customer #" << print->getCustomerNumber() << endl;
		printQueue(pMem->getNextPtr());
	}
}