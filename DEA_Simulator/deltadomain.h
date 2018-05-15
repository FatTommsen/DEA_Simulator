#pragma once
#include "stdincl.h"

class DeltaDomain {

public:
	static struct KeyHasher {
		std::size_t operator()(const DeltaDomain& dd) const
		{
			return (((const int)dd.getA()) * (dd.getQ());
		}
	};

private:
	int q;
	char a;
	int hash;
public:
	DeltaDomain(int q, int a);
	bool operator == (DeltaDomain ddomain);

	int getQ();
	const int getQ() const;
	char getA();
	const char getA() const;
};


class KeyHasher
{
	std::size_t operator()(const DeltaDomain& dd) const
	{
		using std::size_t;
		dd.getA();
	}
};

int main()
{
	std::unordered_map<Key, std::string, KeyHasher> m6 = {
		{ { "John", "Doe", 12 }, "example" },
	{ { "Mary", "Sue", 21 }, "another" }
	};
}