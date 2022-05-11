#include "AlgorithmSortK.h"
#include "SelectionAlgorithm.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/*The
constructors of the subclasses of the SelectionAlgorithm class directly call the constructor
of their superclass.*/
AlgorithmSortK::AlgorithmSortK(int k) :SelectionAlgorithm(k) {
    this->k = k;
}

/*The method takes N, and then a total of N numbers via the cin command(these
	values are not provided as arguments) and prints out the kth largest element. */


int AlgorithmSortK::select() {
    int sizeofarray = k;                //initialized an array of size k
    int nextelement = 0;
    int tmp = 0;
    int* nums = 0;
    int x;
    nums = new int[sizeofarray];
    cin >> x;

    int n, l;
    for (n = 0; n < k; n++){  //added first k elements to array using cin
        cin >> nums[n];
    }

    for (int i = 1; i < sizeofarray; i++) {
        int tmp = nums[i];
        int j = i - 1;
        while (tmp > nums[j] && j >= 0) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = tmp;
    }
    
    for (l = k; l < x; l++){ //check all remaining elements till end of file 

        cin >> nextelement;
        if (nums[k - 1] < nextelement) { //checking if next element > k-1

            nums[k - 1] = nextelement; // if true, insert element

            if (nextelement > nums[k - 2]) {
                for (int i = 1; i < sizeofarray; i++) {
                    int tmp = nums[i];
                    int j = i - 1;
                    while (tmp > nums[j] && j >= 0) {
                        nums[j + 1] = nums[j];
                        --j;
                    }
                    nums[j + 1] = tmp;
                }
            }
        }
    }
    
    cout << "Result: " <<  nums[k-1] << endl;
    return nums[k-1];               //returns kth largest number 
    delete[] nums;
    nums = 0;
}

