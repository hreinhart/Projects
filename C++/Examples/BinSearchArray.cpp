using namespace std;
#include <iostream>
#include <cstdlib>

int binSearch(int a[], int x, int l, int r)
{
	if(r >= l){
		int mid = (l + r) / 2;
		//cout << a[mid] << " ";

		if(a[mid] == x){
			return mid;
		}
		else if(a[mid] > x){ 
		return binSearch(a, x, l, mid-1);
		}
		else if(a[mid] < x){
		return binSearch(a, x, mid + 1, r);}
		}
	return -1;
}

int main(int argc, char *argv[])
{
	#define MAX 100000
	int a[MAX];
	int prev = 0;
	for (int i=0; i<MAX; i++) prev = a[i] = prev + rand()%5;
	int x = atoi(argv[1]);
	int result = binSearch(a, x, 0, MAX-1);
	(result == -1)
		? cout << "Element "<< x <<" is not present in array \n"
		: cout << "Element is present at index " << result << endl;

	return 0;
}
