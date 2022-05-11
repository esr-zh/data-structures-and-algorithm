#ifndef ALGORITHMSORTQUICK_H
#define ALGORITHMSORTQUICK_H

#include "SelectionAlgorithm.h"


class AlgorithmSortQuick : public SelectionAlgorithm {
public:
	AlgorithmSortQuick(int);
	int insertionSort(int a[], int left, int right, int k);
	int median(int numbers[], int left, int right);
	//int QuickSelect(int, int, int, int);
	int QuickSelect(int numbers[], int left, int right, int k);
	int select();
};

#endif