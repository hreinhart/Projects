#ifndef CDA
#define CDA

#include <bits/stdc++.h>
 
using namespace std;

template <typename T>

class CircularDynamicArray  {
    int size, cap, error = -1, front, end;
    T *array;

public :
    CircularDynamicArray(){
        cap = 2;
        size =0;
        front = 0;
        end = size -1;
        array = new T[cap];
    }
    CircularDynamicArray(int s){
        cap = s;
        size =s;
        front = 0;
        end = size-1;
        array = new T[cap];
    }
    CircularDynamicArray(CircularDynamicArray& copy){
        cap = copy.cap;
        array = new T[cap];
        size = copy.size;
        end = size-1;
        front = 0;
        for(int i = 0; i < copy.size; i ++){
            array[i] = copy.array[(front+i)%cap];
        }
    }
    ~CircularDynamicArray(){
    }
    T& operator[](int i){
        return array[(front+i)%cap];
    }
    CircularDynamicArray& operator=(const CircularDynamicArray& src){
        cap = src.cap;
        array = new T[cap];
        size = src.size;
        end = size-1;
        front = 0;
        for(int i = 0; i < src.size; i++){
            array[i] = src.array[(front+i)%cap];
        }
        return *this;
    }
    void CapOut(){
        if(size == cap){
            T *temp = new T[cap *2];
            for(int i = 0; i < size; i++){
                temp[i] = array[(front+i)%cap];
            }
            delete[] this->array;
            array = temp;
            cap *=2;
            front = 0;
            end = size-1;
        }
    }
    void CapUnder(){
        if((cap/4) > size){
            T *temp = new T[cap/2];
            for(int i = 0; i < size; i++){
                temp[i] = array[(front+i)%cap];
            }
            cap/=2;
            front = 0;
            delete[] array;
            array = temp;

            if(size > 0){
                end = size-1;
            }
            else{
                end = 0;
            }
        }
    }

    void addEnd(T v){
            CapOut();
            array[(end+1)%cap] = v;
            end++;
            end %= cap;
            size++;
            }
        
        void addFront(T v){
            CapOut();
            if(front > 0){
                array[front-1]=v;
            }
            else{
                array[cap-1]=v;
                front = cap;
            }
            front--;
            size++;
            }
            void delEnd(){
                end--;
                if(end == -1){
                    end = cap-1;
                }
                size--;
            CapUnder();
                }
        
        void delFront(){
            front++;
            front %= cap;
            size--;
            CapUnder();
        }
        int length(){
            return size;
        }
        int capacity(){
            return cap;
        }
        void clear(){
            delete []array;
            cap = 2; 
            size =0;
            front = 0;
            end =0;
            array = new T[cap];
        }
        T QuickSelect(int k){
            T *temp = new T[size];
            for(int i = 0; i < size; i++){
                temp[i]=array[(front+i)%cap];
            }
            T x = kthSmallest(temp,0, size-1, k);
            return x;
        }
        int partition(T temp[], int l, int r){
            T x = temp[r], i = l;
            for(int j = l; j <= r-1;j++){
                if(temp[j] <= x){
                    T fuck = temp[i];
                    temp[i] = temp[j];
                    temp[j] = fuck;
                    i++;
                }
            }
            T fuck2 = temp[i];
            temp[i] = temp[r];
            temp[r] = fuck2;
            return i; 
        }
        int partitionwc(T arr, int l, int r, int medomed){
            int i;
            T tmp;
            for(i - l; i < r; i++){
                if(arr[i] == medomed){break;}
            }
            tmp = arr[r];
            arr[r] = arr[i];
            arr[i] = tmp;
            i = l;
            for(int j = l; j <= r -1; j++){
                if(arr[j] <= medomed){
                    tmp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = tmp;
                    i++;
                }
            }
            tmp = arr[r];
            arr[r] = arr[i];
            arr[i] = tmp;
            return i;
        }
        T getMed(T arr, int n){
            for(int i = 0; i < n; i++){
                T sml = arr[0];
                for(int j = i + 1; j < n; j++){
                    if(arr[j] < sml){
                        sml = arr[j];
                    }
                }
                if(arr[i] != sml){
                    T tmp = sml;
                    sml = arr[i];
                    arr[i] = sml;
                }
            }
            return arr[n/2];
        }
        T worstcase(int k, T *arr, int l, int r){
            int n = r -l +1, i;
            T med[((n + 4) /5)];
            for(i = 0; i < n; i++){
                med[i] = getMed(arr + l + (i * 5), 5);
            }
            if(n > (i * 5)){
                med[i] = getMed(arr + l + (i*5), n % 5);
            }
            int medomed;
            
            if(i == 1){
                medomed = med[0];
            }
            else{
                worstcase(med, 0, i-1, i/2);
            }
            int pos = partitionwc(arr, l, r, medomed);
            if(pos - l == k - 1){
                return arr[pos];
            }
            else if(pos - l > k - l){
                return worstcase(arr, l, pos-1,k);
            }
            else{
                return worstcase(arr,pos+1,r,k-pos+l-1);
            }
        }

        T kthSmallest(T arr[], int l, int r, int k){
    if (k > 0 && k <= r - l + 1){
        int index = partition(arr, l, r);
        return array[k-1];
    
        }
        return -1;
        }
        T WCSelect(int k){
            if(k<= 0 || k > size){
                return error;
            }
        }
        void stableSort(){
            T *temp = new T[size];
            for(int i = 0; i < size; i++){
                temp[i] = array[(front+i)%cap];
            }
            mergeSort(temp, 0, size-1);
            array = temp;
            front = 0;
            end = size-1;
        }
void merge(T array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(T array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
        
        int linearSearch(T e){
            for(int i = 0; i < size; i++){
                if(array[(front + i) % cap] == e){
                    return i;
                }
            }
            return -1;
        }
        int binSearch(T e){
            T *temp = new T[size];
            for(int i = 0; i < size; i++){
                temp[i] = array[(front + i)%cap];
            }
            return binarySearch(temp,0, size-1, e);
            
        }
        int binarySearch(T arr[], int l, int r, T x){
            if(r < l){
                return -1;
            }
            
                int mid = (l + r)/2;

                if(arr[mid] == x){
                    return mid;
                }

                else if(arr[mid] > x){
                    return binarySearch(arr,l,mid-1,x);
                }
                else{
                    return binarySearch(arr,mid+1,r,x);
                }
        }
};
#endif
