
#include "AlgorithmSortAll.h"
#include "SelectionAlgorithm.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/*The constructors of the subclasses of the SelectionAlgorithm class directly call the constructor
    of their superclass.*/
AlgorithmSortAll::AlgorithmSortAll(int k) :SelectionAlgorithm(k){
    this->k = k;
}

/*The method takes N, and then a total of N numbers via the cin command(these
	values are not provided as arguments) and prints out the kth largest element.*/
int AlgorithmSortAll::select() {

    int sizeofarray = 0;              //initiazlized an array
    cin >> sizeofarray;
    int* nums = 0;
    nums = new int[sizeofarray];

    int n, i, j;
    for (n = 0; n < sizeofarray; n++)  //added all the elements to array using cin
        cin >> nums[n];

    int tmp = 0;
    for (i = 1; i < sizeofarray; i++)  //sorted the elements
    {
        tmp = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] < tmp)
        {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = tmp;
    }
    cout << "Result: " << nums[k-1] << endl;
    return nums[k-1];               //returns kth largest number 
    delete[] nums;
    nums = 0;
}