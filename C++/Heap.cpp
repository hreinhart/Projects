/*  Program Info
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    File: Heap.cpp
    Description: Provides the Heap class, which builds a minHeap
        using the CircularDynamicArray class. 
    Author: Jace McClenny
    Course: CS 201: Introduction to Algorithms
    Date: November 3, 2022
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*/
#ifndef HEAP
#define HEAP

#include "CircularDynamicArray.cpp"
using namespace std;

template<typename keyType> class Heap {
    public:
    // Construct and Destruct

    // Standard Constructor.
    // Time complexity: O(1)
        Heap() { info = new CircularDynamicArray<keyType>; }
    // Constructs a heap with keys K and values V of size s
    // Time complexity: O(n), n = s
        Heap(keyType K[], int s) {
            info = new CircularDynamicArray<keyType>(s);
            
            for (int i = 0; i < s; i++) {
                (*info)[i] = K[i];
            }

            heapify();
        }
    // Destructor
    // Time complexity: O(n), n = info->length()
        ~Heap() {
            delete info;
        }

    // Simple Return Functions

    // Returns a reference to the ket at index 0.
    // Time complexity: O(1)
        keyType peekKey() {
            return (*info)[0];
        }

    // Public Functions

    // Inserts a new node with key k and value v.
    // Time complexity: O()
        void insert(keyType k) {
            info->addEnd(k);
            siftUp(info->length() - 1);
        }
    // Prints all keys in the heap in min->max order. 
    // Time complexity: O(1)
        void printKey() {
            for (int i = 0; i < info->length(); i++) {
                cout << (*info)[i] << " ";
            }
            if (info->length() != 0) {cout << endl;}
        }
    // Removes the minimum value then restores heap priority.
    // Time complexity: O()
        keyType extractMin() {
            keyType min = (*info)[0];
            (*info)[0] = (*info)[info->length() - 1];
            info->delEnd();
            siftDown(0);
            return min;
        }

    private:
    // Values

        CircularDynamicArray<keyType> *info;

    // Support Functions

    // Turns the array into a minHeap.
    // Time complexity: O()
        void heapify() {
            for (int i = info->length() / 2; i >= 0; i--) {
                siftDown(i);
            }
        }
    //
    //
    void siftDown(int i) {
        int l = lIndex(i), r = rIndex(i), min = i;

        if (l < info->length() && (*info)[l] < (*info)[i]) { min = l; }
        if (r < info->length() && (*info)[r] < (*info)[min]) { min = r; }
        if (min != i) { swap(i, min); siftDown(min); }
    }
    //
    //
    void siftUp(int i) {
        for (i; i != 0 && (*info)[i] < (*info)[pIndex(i)]; i = pIndex(i)) {
            swap(i, pIndex(i));
        }
    }
    //
    //
    void swap(int a, int b) {
        keyType temp = (*info)[a];
        (*info)[a] = (*info)[b];
        (*info)[b] = temp;
    }
    // Returns the index of the parent of the node at index i, -1 if invalid.
    // Time complexity: O(1)
        int pIndex(int i) {
            return (i-1) / 2;
            // if (index >= 0 && index < info->length()) {
            //     return index;
            // } else {
            //     return -1;
            // }
        }
    // Returns the index of the left child of the node at index i, -1 if invalid.
    // Time complexity: O(1)
        int lIndex(int i) {
            return (i*2) + 1;
            // if (index >= 0 && index < info->length()) {
            //     return index;
            // } else {
            //     return -1;
            // }
        }
    // Returns the index of the right child of the node at index i, -1 if invalid.
    // Time complexity: O(1)
        int rIndex(int i) {
            return (i*2) + 2;
            // if (index >= 0 && index < info->length()) {
            //     return index;
            // } else {
            //     return -1;
            // }
        }
};
#endif