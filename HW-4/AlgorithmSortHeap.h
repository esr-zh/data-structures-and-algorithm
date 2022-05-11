#ifndef ALGORITHMSORHEAP_H
#define ALGORITHMSORTHEAP_H

#include "SelectionAlgorithm.h"


class AlgorithmSortHeap : public SelectionAlgorithm {
public:
	AlgorithmSortHeap(int);
	int select();
};

#endif