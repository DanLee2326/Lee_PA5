#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

class QueueNode
{
public: // Member functions
    QueueNode(const Data& pNewData);

    QueueNode(const QueueNode& copyQueueNode);

    ~QueueNode();

    void setNextPtr(QueueNode* const pNewNext);

    Data* getData() const;

    QueueNode* getNextPtr() const;

private:
    Data* pData; // The memory for Data will need to be allocated on the heap as well!
    QueueNode* pNext;
};
