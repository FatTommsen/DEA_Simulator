#pragma once
#include "stdincl.h"
#include "deltadomain.h"


using namespace std;
class DFSM {
private:
	int numStates;
	unordered_set<char> alphabet;
	unordered_set<int> acceptingStates;
	unordered_map<DeltaDomain, int> transistionFunction;
	int startingState;

public:
	DFSM(int numStates, char alphabet[]);
	void setStartingState(int state);
	void setAccetpting(int state);
	void setREjectsion(int state);
	void addTransition(int from, char with, int to);
	bool run(string s);


};

