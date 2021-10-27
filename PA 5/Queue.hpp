#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "QueueNode.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

class Queue
{
public: // Member functions
    Queue(QueueNode* pNewHead = nullptr, QueueNode* pNewTail = nullptr);

    Queue(const Queue& copyQueue);

    ~Queue();

    bool isEmpty() const;

    bool enqueue(const Data& pNewData);

    Data* dequeue();

    void printQueueRecursive();
    void printQueue(QueueNode* pMem);

private:
    QueueNode* pHead;
    QueueNode* pTail;
};