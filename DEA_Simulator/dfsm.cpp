#include "stdincl.h"
#include "dfsm.h"
#include "dfsmexception.h"

using namespace std;

DFSM::DFSM(int numStates, const vector<char>& alphabet)
	:numStates(numStates)
{
	setAlphabet(alphabet);
	//random generator seed for possible random strings
	srand(time(NULL));
}

DFSM::DFSM(DFSM::setup setup) {
	if (setup == DFSM::MOD3) {
		mod3DeaInit();
	}
	if (setup == DFSM::Search001001) {
		searchDeaInit();
	}
}

DFSM::~DFSM() {

}

void DFSM::setStartingState(int state) {
	if (state >= numStates || state < 0 ) {
		DFSMExcpetion e ("Invalid index of state chosen as starting state.");
		throw e;
	}
	this->startingState = state;
}

void DFSM::setAccepting(int state) {
	if (state >= numStates || state < 0) {
		DFSMExcpetion e("Invalid index of state chosen as accepting state.");
		throw e;
	}
	// returns iterator at the end of map if ke
	if (acceptingStates.find(state) == acceptingStates.end()) {
		this->acceptingStates.insert(state);
	}
}

void DFSM::setRejecting(int state) {
	if (state >= numStates || state < 0) {
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
	if (from >= numStates || from < 0 || to >= numStates || to < 0 || alphabet.find(with) == alphabet.end() ) {
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
	return runImpl(s, false, NULL, false);
}

void DFSM::runWithOutput(string s) {
	runImpl(s, true, NULL, false);
}

bool DFSM::runWithListener(string input, DFSMListener& listener){
	//listener.resetCounter();
	return runImpl(input, false, &listener, true);
}

bool DFSM::runImpl(string input, bool bVerbose, DFSMListener* listener, bool bListen) {
	if (bVerbose) {
		cout << "\nTesting: '" << input << "' :\n";
	}
	
	int pos = 0;
	int curState = startingState;

	for (unsigned int i = 0; i < input.length(); i++) {
		char curChar = input.at(i);
		if (alphabet.find(curChar) == alphabet.end()) {
			DFSMExcpetion e("The given alphabet does not contain current character.");
			throw e;
		}
		DeltaDomain curDD(curState, curChar);
		if (transistionFunction.find(curDD) == transistionFunction.end()) {
			DFSMExcpetion e("Undefined transistion.");
			throw e;
		}
		curState = transistionFunction.at(curDD);
		++pos;
		if (acceptingStates.find(curState) != acceptingStates.end() && bListen) {
			listener->accepted(pos);
		}
	}

	if (acceptingStates.find(curState) != acceptingStates.end()) {
		if (bVerbose) {
			cout << "true\n";
		}
		return true;
	}
	if (bVerbose) {
		cout << "false\n";
	}
	return false;
}

string DFSM::genString(int size, const vector<char>& alphabet) {
	string generated = "";
	for (int i = 0; i < size; ++i) {
		int randomNumber = rand() * alphabet.size() / RAND_MAX;
		char toAppend = alphabet[randomNumber];
		generated.append(1,toAppend);
	}
	return generated;
}

int DFSM::bfSearch(string source, string pattern) {
	int counter = 0;
	for (int i = 0; i <= source.length() - pattern.length(); ++i) {
		for (int j = 0; j < pattern.length(); ++j) {
			if (source.at(i + j) == pattern.at(j)) {
				if (j == pattern.length() - 1) {
					++counter;
				}
			}
			else {
				break;
			}
		}
	}
	return counter;
}

int DFSM::dea_search_001001(string input) {
	DFSMListener listener;
	runWithListener(input, listener);
	return listener.getCounter();
}

void DFSM::searchDeaInit() {
	cleanup();

	vector<char> alphabet;
	alphabet.push_back('0');
	alphabet.push_back('1');
	setAlphabet(alphabet);

	numStates = 7;
	setAccepting(6);
	setStartingState(0);

	addTransition(0, '0', 1);
	addTransition(0, '1', 0);
	addTransition(1, '0', 2);
	addTransition(1, '1', 0);
	addTransition(2, '0', 2);
	addTransition(2, '1', 3);
	addTransition(3, '0', 4);
	addTransition(3, '1', 0);
	addTransition(4, '0', 5);
	addTransition(4, '1', 0);
	addTransition(5, '0', 2);
	addTransition(5, '1', 6);
	addTransition(6, '0', 4);
	addTransition(6, '1', 0);
}

void DFSM::mod3DeaInit() {
	cleanup();
	vector<char> alphabet;
	alphabet.push_back('0');
	alphabet.push_back('1');
	setAlphabet(alphabet);

	setAccepting(0);
	setStartingState(0);

	addTransition(0, '0', 0);
	addTransition(0, '1', 1);
	addTransition(1, '0', 2);
	addTransition(1, '1', 0);
	addTransition(2, '0', 1);
	addTransition(2, '1', 2);
}

void DFSM::cleanup() {
	alphabet.clear();
	transistionFunction.clear();
	acceptingStates.clear();
	numStates = 0;
	startingState = 0;
}

void DFSM::setAlphabet(const vector<char>& alphabet) {
	for (char a : alphabet) {
		this->alphabet.insert(a);
	}
}

vector<char> DFSM::getAlphabet() {
	vector<char> alpha;
	for (auto a : alphabet) {
		alpha.push_back((char)a);
	}
	return alpha;
}