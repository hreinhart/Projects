// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
	int *harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	// Constructor
	MinHeap(int capacity);

	// to heapify a subtree with the root at given index
	void MinHeapify(int );

	int parent(int i) { return (i-1)/2; }

	// to get index of left child of node at index i
	int left(int i) { return (2*i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2*i + 2); }

	// to extract the root which is the minimum element
	int extractMin();

	// Decreases key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// Returns the minimum key (key at root) from min heap
	int getMin() { return harr[0]; }

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print2DUtil(MinHeap *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 2;
 
    // Process right child first
    print2DUtil(root->right(), space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = 2; i < space; i++)
        cout<<" ";
    cout<<root->next<<"\n";
 
    // Process left child
    print2DUtil(root->left(i), space);
}
 
// Wrapper over print2DUtil()
void print2D(MinHeap *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// Driver program to test above functions
int main()
{   string input;
    MinHeap h = MinHeap(17);
    int in1, in2;
	while(input != "quit"){
        cout << "Input a command or Help for help." << endl;
        cin >> input;
        if(input == "Help"){
            cout << "Available Commands:" << endl << "Heapify" << endl << "Delete" << endl << "ExtractMin" << "DecreaseKey"
            << endl << "InsertKey" << endl << "Print" << endl;;
        }
        else if(input == "Heapify"){
            cout << "Enter the height you would like to heapify." << endl;
            cin >> in1;
            h.MinHeapify(in1);
        }
        else if(input == "Delete"){
            cout << "Enter a number you would like to delete." << endl;
            cin >> in1;
            h.deleteKey(in1);
        }
        else if(input == "ExtractMin"){
            cout << "Removing the minimum number." << endl;
            cout << h.extractMin() << endl;
        }
        else if(input == "DecreaseKey"){
            cout << "Enter a number you would like to decrease followed by a smaller number." << endl;
            cin >> in1; in2;
            h.decreaseKey(in1, in2);
        }
        else if(input == "InsertKey"){
            cout << "Enter a number you would like to insert." << endl;
            cin >> in1;
            h.insertKey(in1);
        }
		/*else if(input == "Print"){
			cout << "Printing." << endl;
			print2D(h);
		}*/
    }
	return 0;
}
