#include "stdincl.h"
#include "dfsm.h"
#include "dfsmexception.h"

using namespace std;

DFSM::DFSM(int numStates, char alphabet[])
	:numStates(numStates)
{
	size_t size = sizeof(alphabet) / sizeof(alphabet[0]);
	for (unsigned int i = 0; i < size; i++) {
		this->alphabet.insert(alphabet[i]);
	}
}

void DFSM::setStartingState(int state) {
	if (state > numStates || state <= 0 ) {
		DFSMExcpetion e ("Invalid index of state chosen as starting state.");
		throw e;
	}
	this->startingState = state;
}

void DFSM::setAccepting(int state) {
	if (state > numStates || state <= 0) {
		DFSMExcpetion e("Invalid index of state chosen as accepting state.");
		throw e;
	}
	// If key not found in map iterator to end is returned
	if (acceptingStates.find(state) == acceptingStates.end()) {
		this->acceptingStates.insert(state);
	}
}

void DFSM::setRejecting(int state) {
	if (state > numStates || state <= 0) {
		DFSMExcpetion e("Invalid index of state chosen as rejecting state.");
		throw e;
	}
	unordered_set<int>::const_iterator iter;
	iter = acceptingStates.find(state);
	if ( iter != acceptingStates.end()) {
		acceptingStates.erase(iter);
	}
}

void DFSM::addTransition(int from, char with, int to) {
	if (from > numStates || from <= 0 || to > numStates || to <= 0 || alphabet.find(with) == alphabet.end() ) {
		DFSMExcpetion e("Invalid parameter for transition-function.");
		throw e;
	}
	DeltaDomain dd(from, with);
	unordered_map<DeltaDomain, int, DeltaDomain::KeyHasher>::const_iterator iter;
	iter = transistionFunction.find(dd);
	if (iter == transistionFunction.end()) {
		transistionFunction.insert_or_assign(dd, to);
	}
}

bool DFSM::run(string s) {
	int curState = startingState;

	for (unsigned int i = 0; i < s.length(); i++) {
		char curChar = s.at(i);
		if (alphabet.find(curChar) == alphabet.end()) {
			DFSMExcpetion e("The given alphabet does not contain current character.");
			throw e;
		}
		DeltaDomain curDD(curState, curChar);
		if( transistionFunction.find(curDD) == transistionFunction.end() ){
			DFSMExcpetion e("Undefined transistion.");
			throw e;
		}
		curState = transistionFunction.at(curDD);
	}

	if (acceptingStates.find(curState) != acceptingStates.end()) {
		return true;
	}
	return false;
	
}