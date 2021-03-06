#include "stdafx.h"
#include "stdincl.h"
#include "dfsm.h"
#include "dfsmexception.h"

using namespace std;

int main()
{
	try {
		DFSM dfsm(DFSM::Search001001);
		vector<char> alphabet = dfsm.getAlphabet();

		string input;
		input = dfsm.genString(20, alphabet);
		cout << "\ninput: " << input;
		cout << "\nDea-Found:" << dfsm.dea_search_001001(input);
		cout << "\nDea-BruteForce:" << dfsm.bfSearch(input, "001001");
		input = dfsm.genString(20, alphabet);
		cout << "\ninput: " << input;
		cout << "\nDea-Found:" << dfsm.dea_search_001001(input);
		cout << "\nDea-BruteForce:" << dfsm.bfSearch(input, "001001");
		input = dfsm.genString(20, alphabet);
		cout << "\ninput: " << input;
		cout << "\nDea-Found: " << dfsm.dea_search_001001(input);
		cout << "\nDea-BruteForce:" << dfsm.bfSearch(input, "001001");
		input = dfsm.genString(20, alphabet);
		cout << "\ninput: " << input;
		cout << "\nDea-Found:" << dfsm.dea_search_001001(input);
		cout << "\nDea-BruteForce:" << dfsm.bfSearch(input, "001001");




	}
	catch (DFSMExcpetion &e) {
		cout << e.getError();
	}

	string stop;
	cin >> stop;
}


