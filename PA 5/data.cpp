#include "Data.hpp"

Data::Data(int newCustomerNumber, int newServiceTime, int newTotalTime)
{
	this->customerNumber = newCustomerNumber;
	this->serviceTime = newServiceTime;
	this->totalTime = newTotalTime;
}

Data::Data(const Data& copyData)
{
	this->customerNumber = copyData.getCustomerNumber();
	this->serviceTime = copyData.getServiceTime();
	this->totalTime = copyData.getTotalTime();
}

Data::~Data()
{

}

void Data::setCustomerNumber(int newCustomerNumber)
{
	this->customerNumber = newCustomerNumber;
}
void Data::setServiceTime(int newServiceTime)
{
	this->serviceTime = newServiceTime;
}
void Data::setTotalTime(int newTotalTime)
{
	this->totalTime = newTotalTime;
}

int Data::getCustomerNumber() const
{
	return this->customerNumber;
}
int Data::getServiceTime() const
{
	return this->serviceTime;
}
int Data::getTotalTime() const
{
	return this->totalTime;
}