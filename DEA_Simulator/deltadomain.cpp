
#include "deltadomain.h"


DeltaDomain::DeltaDomain(int q, int a)
	:q(q),
	a(a)
{

}

int DeltaDomain::getQ() {
	return q;
}

const int DeltaDomain::getQ() const {
	return q;
}

char DeltaDomain::getA() {
	return a;
}

const char DeltaDomain::getA() const {
	return a;
}

bool DeltaDomain::operator == (DeltaDomain ddomain) {
	return ddomain.getA() == a && ddomain.getQ() == q;
}

bool const DeltaDomain::operator == (const DeltaDomain ddomain) const {
	return ddomain.getA() == a && ddomain.getQ() == q;
}