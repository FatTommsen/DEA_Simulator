
#include "deltadomain.h"


DeltaDomain::DeltaDomain(int q, int a)
	:q(q),
	a(a)
{

}

int DeltaDomain::getQ() {
	return q;
}


char DeltaDomain::getA() {
	return a;
}

bool DeltaDomain::operator == (DeltaDomain ddomain) {
	return ddomain.getA() == a && ddomain.getQ() == q;
}