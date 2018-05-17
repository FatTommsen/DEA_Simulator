#pragma once
#include "stdincl.h"
#include "deltadomain.h"
#include "dfsmlistener.h"

using namespace std;
class DFSM {
public:
	enum setup {
		MOD3,
		Search001001
	};

private:
	int numStates;
	unordered_set<char> alphabet;
	unordered_set<int> acceptingStates;
	unordered_map<DeltaDomain, int, DeltaDomain::KeyHasher> transistionFunction;
	int startingState;

public:
	DFSM(int numStates, const vector<char>& alphabet);
	DFSM(DFSM::setup setup);
	~DFSM();
	void setStartingState(int state);
	vector<char> getAlphabet();
	void setAccepting(int state);
	void setRejecting(int state);
	void addTransition(int from, char with, int to);
	bool run(string s);
	void runWithOutput(string s);

	bool runWithListener(string input, DFSMListener& listener);
	string genString(int size, const vector<char>& alphabet);
	int bfSearch(string source, string pattern);
	int dea_search_001001(string input);

	void cleanup();

private:
	bool runImpl(string input, bool bVerbose, DFSMListener* listener, bool bListen);
	void setAlphabet(const vector<char>& alphabet);

//Setups:
public:
	void searchDeaInit();
	void mod3DeaInit();
};

