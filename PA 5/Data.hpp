#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

class Data
{
public: // Member functions
	Data(int newCustomerNumber = 0, int newServiceTime = 0, int newTotalTime = 0);

	Data(const Data& copyData);

	~Data();

	void setCustomerNumber(int newCustomerNumber);
	void setServiceTime(int newServiceTime);
	void setTotalTime(int newTotalTime);

	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime() const;

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; // Random time; varies between express and normal lanes; units in minutes
	int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; // This memory needs to be allocated on the heap!