#include "TestBed.h"
#include "SelectionAlgorithm.h"
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

TestBed::TestBed(){
	this->Algorithm = NULL;
}

void TestBed::SetAlgorithm(int type, int k){
	if (type == 1) {
		Algorithm = new AlgorithmSortAll(k);
	}
	else
	{
		Algorithm = new AlgorithmSortK(k);
	}
}
/*The setAlgorithm method is supposed to initialize this pointer by creating an object of the
class AlgorithmSortAll or AlgorithmSortK depending on the chosen algorithm type(1 or 2, respectively).*/


void TestBed::execute(){

	// Time stamp before the computations
	clock_t start = clock();

	/* Computations to be measured */
	Algorithm->select();

	// Time stamp after the computations
	clock_t end = clock();
	double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	cout << "Duration(sec) :" << cpu_time;
}
/*The execute() method calls the select() method (i.e., the call is made as
“algorithm->select()”, while the actual method being called depends on the active object
instance). This method also measures the time elapsed during the execution of the select()
method and prints the result.*/

TestBed::~TestBed() {
	delete[] Algorithm;
}
/*The destructor of this class should free the resources by
deleting the object pointed by *algorithm.*/