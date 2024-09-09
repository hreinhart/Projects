/*  Program Info
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    File: FibHeap.cpp
    Description:
    Author: Jace McClenny
    Course: CS 201: Introduction to Algorithms
    Date: November 3, 2022
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*/
#ifndef FIBHEAP
#define FIBHEAP

#include <cmath>
#include "CircularDynamicArray.cpp"

using namespace std;

template <typename keyType>
class FibHeapNode {
   public:
    // Public Elements

    FibHeapNode<keyType> *left, *right, *parent, *childHead, *childTail;
    keyType key;
    int rank;
    bool marked;

    // Construct and Destruct

    // Standard Constructor. Does not assign value to key
    // Time complexity: O(1)
    FibHeapNode() {
        rank = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        childHead = nullptr;
        childTail = nullptr;
        marked = false;
    }
    // Constructs a new node with key k and val v.
    // Time complexity: O(1)
    FibHeapNode(keyType k) {
        key = k;
        rank = 0;
        left = this;
        right = this;
        parent = nullptr;
        childHead = nullptr;
        childTail = nullptr;
        marked = false;
    }

    // Copy Constructor
    // Time complexity: O(1)
    FibHeapNode(const FibHeapNode<keyType> &src) {
        key = src.key;
        rank = src.rank;
        marked = src.marked;
    }
    // Destructor
    // Time complexity: O(1)
    ~FibHeapNode() {
        // No variables are dynamically allocated, no delete statements needed.
    }
    // Deletes children then siblings of this
    // Time complexity: O(n) n = size of heap
    void avalanche(FibHeapNode<keyType> *start) {
        if (childHead != nullptr) {
            childHead->avalanche(childHead);
        }
        if (right != nullptr) {
            right->avalanche(this);
        }
        delete this;
    }

    // Simple Return Functions

    int getRank() { return rank; }
    void addChild(FibHeapNode<keyType> *newNode) {
        if (childHead == nullptr) {
            childHead = newNode;
            childTail = newNode;
        } else {
            childHead->left = newNode;
            childTail->right = newNode;
            newNode->left = childTail;
            newNode->right = childHead;
            childHead = newNode;
        }
        newNode->parent = this;
        rank++;
    }   
    void cutChild(FibHeapNode<keyType> *cutNode) {
        if (cutNode->right == cutNode) {
            childHead = nullptr;
            childTail = nullptr;
        } else {
            cutNode->left->right = cutNode->right;
            cutNode->right->left = cutNode->left;
            if (childHead == cutNode) {childHead = cutNode->right;}
            if (childTail == cutNode) {childTail = cutNode->left;}
        }
        cutNode->parent = nullptr;
        rank--;
    }
};

template <typename keyType>
class FibHeap {
    public:
    FibHeapNode<keyType> *head, *tail, *min;
    int size;

    // Construct && Destruct

    // Default Constructor
    // Time Complexity: O(1)
    FibHeap() {
        min = nullptr;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    // Constructs a Fibbonacci Heap of size s with nodes K and an array of
    // pointers to the nodes inserted Time Complexity: O(n), n = s
    FibHeap(keyType *K, int s, CircularDynamicArray<FibHeapNode<keyType>*> &handle) {
        min = nullptr;
        head = nullptr;
        tail = nullptr;
        size = 0;
        for (int i = 0; i < s; i++) {
            FibHeapNode<keyType> *newNode = new FibHeapNode<keyType>(K[i]);
            insert(newNode);
            handle.addEnd(newNode);
        }
        size = s;
        consolidate();
    }
    // Destructor
    // Time Complexity: O(n) n = size SPECIFY VARIABLE
    ~FibHeap() {avalanche(head);}

    void avalanche(FibHeapNode<keyType> *start) {
        if (start == nullptr) {return;}
        FibHeapNode<keyType> *node = start;

        do {
            if (node->childHead != nullptr) { avalanche(node->childHead); }
            FibHeapNode<keyType> *r = node->right;
            delete node;
            node = r;
        } while (node != start);
    }
    // Simple Prints and Returns

    // Prints modified preorder of all keys in the tree, starting at the head
    // Time Complexity: O(n)
    void printKey() {
        if (head != nullptr) {
            printKeyRecursion(head);
        }
    }
    // Returns a reference to current head key
    // Time Complexity: O(1)
    keyType peekKey() { return min->key; }

    int getSize() { return size; }
    // Public Functions

    // Returns a reference to current head key and deletes it
    // Amortized Time Complexity: O(lg(n)), n = size
    keyType extractMin() {
        FibHeapNode<keyType> *oldMin = min;
        keyType val = oldMin->key;

        if (oldMin != nullptr) {
            FibHeapNode<keyType> *children = oldMin->childHead;
            while (children != nullptr) {
                oldMin->cutChild(children);
                insert(children);
                children = oldMin->childHead;
            }

            FibHeapNode<keyType> *temp = oldMin->right;
            remove(oldMin);
            if (min != nullptr) {
                min = temp;
                consolidate();
            }
            size--;
        }

        delete oldMin;
        return val;
    }
    // Inserts a key and returns a pointer to its node
    // Amortized Time Complexity: O(1)
    FibHeapNode<keyType> *insert(keyType k) {
        FibHeapNode<keyType> *newNode = new FibHeapNode<keyType>(k);
        insert(newNode);
        size++;
        return newNode;
    }
    // Decrease the node at index h by k
    // Amortized Time Complexity: O(1)
    bool decreaseKey(FibHeapNode<keyType> *h, keyType k) {
        if (k >= h->key) {
            return false;
        }
        h->key = k;
        
        FibHeapNode<keyType> *temp = h->parent;
        if (temp != nullptr && h->key < temp->key) {
            cut(h);
            cascadeCut(temp);
        }
        if (h->key < min->key) {
            min = h;
        }
        return true;
    }
    // Merges R into this, consolidating R and setting it to an empty tree
    // Amortized Time Complexity: O(1)
    void merge(FibHeap<keyType> &R) {
        tail->right = R.head;
        R.head->left = tail;
        
        R.tail->right = head;
        head->left = R.tail;

        tail = R.tail;

        if (R.min < min) {
            min = R.min;
        }

        size += R.size;
        R.min = nullptr;
        R.head = nullptr;
        R.tail = nullptr;
        R.size = 0;
    }

   private:
    

    // Support Functions

    //
    //
    void insert(FibHeapNode<keyType> *node) {
        if (min == nullptr) {
            min = node;
            head = node;
            tail = node;
        } else {
            tail->right = node;
            head->left = node;
            node->left = tail;
            node->right = head;
            tail = node;
            if (node->key < min->key) {min = node;}
        }
    }
    //
    //
    void remove(FibHeapNode<keyType> *node) {
        if (node->right == node) {
            min = nullptr;
            head = nullptr;
            tail = nullptr;
        } else {
            if (node == head) {head = node->right;}
            if (node == tail) {tail = node->left;}
            node->left->right = node->right;
            node->right->left = node->left;
        }
        node->left = node;
        node->right = node;
    }
    //
    //
    void cut (FibHeapNode<keyType> *node) {
        
        node->parent->cutChild(node);

        insert(node);

        node->marked = false;
    }
    //
    //
    void cascadeCut(FibHeapNode<keyType> *temp) {
        FibHeapNode<keyType> *e = temp->parent;
        if (e != nullptr) {
            if (!(temp->marked)) {
                temp->marked = true;
            } else {
                cut(temp);
                cascadeCut(e);
            }
        }
    }
    //
    //
    void link(FibHeapNode<keyType> *a, FibHeapNode<keyType> *b) {
        
        remove(a);
        
        if(b->right == b){
            head = b;
            tail = b;
            min = b;
        }

        b->addChild(a);
    }
    //
    //
    void consolidate() {
        float floatDegree = log2(size);
        int maxDegree = floatDegree;
        FibHeapNode<keyType> *degrees[maxDegree];
        for (int i = 0; i <= maxDegree; i++) {
            degrees[i] = nullptr;
        }

        FibHeapNode<keyType> *a = head;
        do {
            int aDeg = a->rank;

            while(degrees[aDeg] != nullptr && degrees[aDeg] != a){

                FibHeapNode<keyType> *b = degrees[aDeg];

                if(a->key > b->key){
                    FibHeapNode<keyType> *c = a;
                    a = b;
                    b = c;
                }
                link(b,a);

                degrees[aDeg] = nullptr;
                aDeg++;
            }
            degrees[aDeg] = a;
            a = a->right;
        } while (a != head);

        head = nullptr;
        tail = nullptr;
        min = nullptr;

        for(int i = 0; i <= maxDegree; i++){
            if(degrees[i] != nullptr){
                insert(degrees[i]);
            }
        }
    }
    //
    //
    void printKeyRecursion(FibHeapNode<keyType> *start) {
        FibHeapNode<keyType> *node = start;

        do {
            if (node->parent == nullptr) {
                cout << "Rank " << node->rank << endl;
            }
            cout << node->key << " ";

            if (node->childHead != nullptr) {
                printKeyRecursion(node->childHead);
            }
            if (node->parent == nullptr) {
                cout << endl;
                if (node->right != start) {
                    cout << endl;
                }
            }
            node = node->right;
        } while (node != start);
    }
};
#endif