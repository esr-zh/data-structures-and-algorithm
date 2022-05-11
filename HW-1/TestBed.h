
#include "SelectionAlgorithm.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include <iostream>

using namespace std;


class TestBed {
public:
	void execute();
	void SetAlgorithm(int, int);
	TestBed();
	~TestBed();


protected:
	SelectionAlgorithm *Algorithm;

	//return_type (class_name::*ptr_name) (argument_type) = &class_name::function_name;
	//void (TestBed::* SelectionAlgorithm) (int);
};
