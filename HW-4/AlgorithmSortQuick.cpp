#include "AlgorithmSortQuick.h"
#include "SelectionAlgorithm.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

AlgorithmSortQuick::AlgorithmSortQuick(int k) :SelectionAlgorithm(k) {
    this->k = k;
}

int AlgorithmSortQuick::insertionSort(int a[], int left, int right, int k)
{
    int i, j;
    int tmp = 0;
    int n = sizeof(a);
    for (i = 1; i < right ; i++)  //sorted the elements
    {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < tmp)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = tmp;
    }
    return a[k-1];               //returns kth largest number 
    delete[] a;
    a = 0;
}

int AlgorithmSortQuick::median(int numbers[], int left, int right) {
    int center = (left + right) / 2;
    if (numbers[center] > numbers[left]) {
        swap(numbers[left], numbers[center]);
    }
    if (numbers[right] > numbers[left]) {
        swap(numbers[left], numbers[right]);
    }
    if (numbers[right] > numbers[center]) {
        swap(numbers[right], numbers[center]);
    }
    swap(numbers[center], numbers[right - 1]);
    return numbers[right - 1];
}

int AlgorithmSortQuick::QuickSelect(int numbers[], int left, int right, int k) {
    int result = -1;
    if (right - left <= 10) {
        result = insertionSort(numbers, left, right, k);
    }
    else {
        int pivot = median(numbers, left, right);
        int i = left;
        int j = right-1;
        for (;;) {
            while (numbers[++i] > pivot) {
            }
            while (pivot > numbers[--j]) {
            }
            
            if (i < j) {
                swap(numbers[i], numbers[j]);
            }
            else {
                break;
            }
        }
        swap(numbers[i], numbers[right-1]);
        if (i - left == k + 1 ) {
            result =  numbers[i + 1];
        }
        else {
            if (i - left + 1 > k ) {
                result = QuickSelect(numbers, left, i - 1, k);
            }
            else {
                result = QuickSelect(numbers, i + 1, right, k);
            }
        }
    }
    return result;
}

int AlgorithmSortQuick::select() {
    int sizeofarray = 0;              //initiazlized an array
    cin >> sizeofarray;
    int* nums = 0;
    nums = new int[sizeofarray];

    int n;
    for (n = 0; n < sizeofarray; n++)  //added all the elements to array using cin
        cin >> nums[n];
    int res = QuickSelect(nums, 0, sizeofarray-1, k);
    cout << "Result: " << res << endl;
    return res;
}
