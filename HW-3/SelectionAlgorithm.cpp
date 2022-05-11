#include "SelectionAlgorithm.h"


SelectionAlgorithm::SelectionAlgorithm(int k) {
	this->k = k;
}

int SelectionAlgorithm::select() {
	return 0;
}


/*SelectionAlgorithm is an abstract class that is not directly used. It has a protected member
variable k, which is initialized by the constructor. The select() method is actually
implemented by the subclasses of the SelectionAlgorithm class (i.e., it should be declared
as virtual). */