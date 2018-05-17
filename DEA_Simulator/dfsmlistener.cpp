#include "dfsmlistener.h"


DFSMListener::DFSMListener()
	:counter(0)
{

}

DFSMListener::~DFSMListener() {

}

void DFSMListener::accepted(int pos) {
	counter++;
	cout << "accepting state entered, pos: " << pos << "\n";
}

void DFSMListener::resetCounter() {
	counter = 0 ;
}

int DFSMListener::getCounter() {
	return counter;
}