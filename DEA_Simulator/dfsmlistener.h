#pragma once
#include "stdincl.h"

using namespace std;

class DFSMListener {
	public:
		DFSMListener();
		~DFSMListener();
		
		void accepted(int pos);
		void resetCounter();
		int getCounter();
	private:
		int counter;
};