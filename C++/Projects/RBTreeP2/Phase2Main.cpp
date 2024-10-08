#include <iostream>
#include <climits>
using namespace std;
#include "RBTree.cpp"

int main(){

	string K[10] = {"A","B","C","D","E","F","G","H","I","K"};
	int V[10] = {10,9,8,7,6,5,4,3,2,1};
	
	RBTree<string,int> T1, T2(K,V,10);
	
	for(int i=0; i<10; i++) T1.insert(K[i],V[i]);
	// T1 and T2 should be identical trees

	cout << *(T2.search("C")) << endl;
	// Should cout 8

	cout << T2.rank("C") << endl;
	//Should cout 3
	
	cout << T2.select(3) << endl;
	//Should cout C 

	T2.preorder();
	//Should cout "D B A C F E H G I K\n"
	//as a string. There should be a single 
	//newline after any of the order 
	//method calls
	
	T2.inorder();
	//Should cout	A B C D E F G H I K\n
	
	cout << T2.remove("D") << endl;
	//Should cout 1
	
	T2.preorder();
	//Should cout F C B A E H G I K\n
	
	T2.inorder();
	//Should cout	A B C E F G H I K\n
	
	T2.printk(3);
	//Should cout	A B C\n
	
	cout << T2.remove("J") << endl;
	//Should cout 0

	cout <<T2.rank("G") << endl;
	//Should cout 6
	
	cout <<*(T1.successor("C"))<<endl;
	//Should cout D
	
	cout <<*(T1.predecessor("C"))<<endl;
	//Should cout B		

    RBTree<int,int> X;
	for (int i=1;i<1001000;i++) X.insert(i,i);
	for (int i=1;i<1001000;i++) {
		if(X.rank(i) != i) cout << "Rank error" << endl;
		if(X.select(i) != i) cout << "Select error" << endl;
		if(*(X.search(i)) != i) cout << "Search error" << endl;
	}  
	//Should be no cout and should take seconds, not minutes

	return 0;
}
