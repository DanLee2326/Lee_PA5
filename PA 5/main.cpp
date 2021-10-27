#include "Queue.hpp"
#include "Test.hpp"

int main(void)
{
	Test a, b, c, d, e;

	runQueue();
	a.testEnqueueEmptyQueue();
	b.testEnqueueOneNode();
	c.testDequeueOneNode();
	d.testDequeueTwoNodes();
	e.testRun24Hours();

	return 0;
}