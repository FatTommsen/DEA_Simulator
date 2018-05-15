#pragma once
#include "stdincl.h"

using namespace std;

class DFSMExcpetion : exception {
private:
	string errormsg;
public:
	DFSMExcpetion(string strErrorMsg);
};
