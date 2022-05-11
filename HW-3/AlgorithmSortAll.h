#ifndef ALGORITHMSORTALL_H
#define ALGORITHMSORTALL_H

#include "SelectionAlgorithm.h"


class AlgorithmSortAll : public SelectionAlgorithm {
public:
	AlgorithmSortAll(int);
	int select();
};

#endif