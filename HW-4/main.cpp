#include <iostream>
#include <string>
#include <fstream>
#include "TestBed.h"

using namespace std;

int main(int argc, char* argv[]) {
	string testfile;
	if (argc < 2) {
		cout << "Enter a test file name:" << endl;
		cin >> testfile;
	}
	else {
		testfile = argv[1];
	}
	ifstream file(testfile.c_str());
	if (file.is_open()) {
		cin.rdbuf(file.rdbuf());
	}
	else {
		cout << "Error: cannot read the test file!" << endl;
		return -1;
	}
	int algorithmType = 0;
	int k = 0;

	// Numbers are obtained from the file line by line with cin
	cin >> algorithmType;
	cin >> k;

	// Create a TestBed object, initialize and execute the algorithm
	TestBed* obj = new TestBed();

	obj->SetAlgorithm(algorithmType, k);
	obj->execute();

	//At the end of the main function, the TestBed object should be deleted
	delete obj;

	return 0;
}
/*The main function will create an object of type TestBed and it will first consume two
inputs (i.e., via the cin command as explained later in Section 5) to obtain; i) the type of
the algorithm (can be either 1 or 2), and ii) k. It will set up the test bed accordingly, using
the setAlgorithm method.*/