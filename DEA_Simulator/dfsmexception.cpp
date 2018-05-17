#include "dfsmexception.h"



DFSMExcpetion::DFSMExcpetion(string strErrorMsg) {
	errormsg = strErrorMsg;
}

DFSMExcpetion::~DFSMExcpetion() {

}

string DFSMExcpetion::getError() {
	return errormsg;
}