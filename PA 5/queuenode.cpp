#include "QueueNode.hpp"

QueueNode::QueueNode(const Data& pNewData)
{
	this->pData = new Data(pNewData);
	this->pNext = nullptr;
}

QueueNode::QueueNode(const QueueNode& copyQueueNode)
{
	this->pData = copyQueueNode.getData();
	this->pNext = copyQueueNode.getNextPtr();
}

QueueNode::~QueueNode()
{
	delete pData;
}

void QueueNode::setNextPtr(QueueNode* const pNewNext)
{
	this->pNext = pNewNext;
}

Data* QueueNode::getData() const
{
	return this->pData;
}

QueueNode* QueueNode::getNextPtr() const
{
	return this->pNext;
}