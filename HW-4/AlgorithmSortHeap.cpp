#include "AlgorithmSortHeap.h"
#include "SelectionAlgorithm.h"
#include "BinaryHeap.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
AlgorithmSortHeap::AlgorithmSortHeap(int k) :SelectionAlgorithm(k) {
    this->k = k;
}

int AlgorithmSortHeap::select() {
    int sizeofarray = 0;
    int next;
    cin >> sizeofarray;
    BinaryHeap* heapy = new BinaryHeap(sizeofarray);

    for (int i = 0; i <= sizeofarray; i++) {
        cin >> next;
        heapy->insert(next);
    }

    for (int j = 0; j < k; j++) {
        heapy->deleteMin();
    }

    cout << "Result: " << heapy->getMin() << endl;
    return(heapy->getMin());
}