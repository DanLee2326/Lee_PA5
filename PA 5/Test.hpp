#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Queue.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

void runQueue(void);
int getMax(int n1, int n2);

class Test
{
public:
	void testEnqueueEmptyQueue(void);
	void testEnqueueOneNode(void);
	void testDequeueOneNode(void);
	void testDequeueTwoNodes(void);
	void testRun24Hours(void);

private:
	void timeSetFunction(int n);
};