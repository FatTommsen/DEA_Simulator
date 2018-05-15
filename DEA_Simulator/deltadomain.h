#pragma once
#include "stdincl.h"

class DeltaDomain {
private:
	int q;
	char a;
	int hash;
public:
	DeltaDomain(int q, int a);
	bool operator == (DeltaDomain ddomain);

	int getQ();
	char getA();
};