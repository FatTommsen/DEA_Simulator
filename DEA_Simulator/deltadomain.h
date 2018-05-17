#pragma once
#include "stdincl.h"

class DeltaDomain {

public:
	static struct KeyHasher {
		std::size_t operator()(const DeltaDomain& dd) const
		{
			return ( ((const int)dd.getA()) * (dd.getQ()) );
		}
	};

private:
	int q;
	char a;
	int hash;
public:
	DeltaDomain(int q, int a);
	~DeltaDomain();
	bool operator == ( const DeltaDomain ddomain);
	bool const operator == (const DeltaDomain ddomain) const;

	int getQ();
	const int getQ() const;
	char getA();
	const char getA() const;
};
