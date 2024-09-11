#include <iostream>

using namespace std;

template <typename T>

class CircularDynamicArray {
public:
        int size, cap, error = -1, front, end;
        T *array;

        int partition(T arr[],int l, int r){
           T x = arr[size],temp;
           int i=l;
            for(int j = l; j <=size-1; j++){
                if(arr[j]<= x){
                    temp =arr[j];
                    arr[j] = arr[i];
                    arr[i]=temp;
                    i++;
                }
                //cout << "l";
            }
            return i;
        }
        T recurssive(T arr[], int l, int r, int k){
            if(k > 0 && k <= r-l+1){
                int i = partition(arr,l,r);
                //cout << "h";
                if(i-l == k-1){
                    return arr[i];
                }
                else if(i -l > k -1){
                    return recurssive(arr,l,i-1,k);
                }
                else{
                return recurssive(arr,i+1,r,k-i+l-1);}
                
            }
            return -1;
        
        }
        void merge(T arr[], int l, int mid, int r){
            int temp1 = mid - l + 1;
            int temp2 = r - mid;

            T *Temp1Array = new T[temp1];
            T *Temp2Array = new T[temp2];

            for(int i = 0; i < temp1; i++){
                Temp1Array[i] = arr[l + i];
            }
            for(int j = 0; j < temp2; j++){
                Temp2Array[j] = arr[mid +1 + j];
            }
            int i1 = 0, i2 = 0, merged = l;

            while(i1 < temp1 && i2 < temp2){
                if(Temp1Array[i1] <= Temp2Array[i2]){
                    arr[merged] = Temp1Array[i1];
                    i1++;
                }
                else{
                    arr[merged]= Temp2Array[i2];
                    i2++;
                }
                merged++;
            }
            while(i1 < temp1){
                arr[merged]=Temp1Array[i1];
                i1++;
                merged++;
            }
            while(i2 < temp2){
                arr[merged] = Temp2Array[i2];
                i2++;
                merged++;
            }
            delete[] Temp1Array;
            delete[] Temp2Array;
        }
        void mergesort(T arr[], int l, int r){
            
            if(l >= r)
                return;

            int mid = l + (r-l)/2;
            mergesort(arr,l,mid);
            mergesort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        CircularDynamicArray(){
            cap = 2;
            size = 0;
            front = 0;
            error;
            end = size -1;
            array = new T[cap];
        }
        CircularDynamicArray(int s){
            cap = s;
            size = s;
            front = 0;
            error;
            end = size-1;
            array = new T[cap];
        }
        CircularDynamicArray(CircularDynamicArray& copy){
            cap = copy.cap;
            array = new T[cap];
            size = copy.size;
            end = size-1;
            front = 0;
            for(int i = 0; i < copy.size; i++){
                array[i] = copy.array[(front+i)%cap];
            }
        }
        ~CircularDynamicArray(){
            delete []array;
        }
        T& operator[](int i){
                return array[(front+i)%cap];
            }
        
        CircularDynamicArray& operator=(const CircularDynamicArray& src) {
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
        void addEnd(T v){
            if(size == cap){
                cap *=2;
            T *b = new T[cap];
            for(int i = 0; i < size; i++){
                b[i] = array[(front + i) % size];
                //cout << b[i] << " ";
            }
            array = new T[cap];
            //cout <<"Look here" <<endl;
            front = 0;
            end = size -1;
            *array = *b;
            for(int i = 0; i< size; i++){
                array[i] = b[i];
                //cout << array[i] << " ";
            }
            //cout<< "Here too" << endl;
            }
            
           
            end++;
            if(end == cap){
                end = 0;
            }
            array[end % cap] = v;
            size++;
            }
        
        void addFront(T v){
            if(size == cap){
                cap *=2;
                //cout << "dubz" << endl;
            T *b = new T[cap];
            for(int i = 0; i < size; i++){
                b[i] = array[(front + i) % size];
                //cout << b[i] << " ";
            }
            array = new T[cap];
            //cout <<"Look here" <<endl;
            front = 0;
            end = size -1;
            *array = *b;
            
            for(int i = 0; i< size; i++){
                array[i] = b[i];
                //cout << array[i] << " ";
            }
            //cout<< "Here too" << endl;
            }
            
            // if(front == 0){
            //     front = cap-1;
            //     array[front] = v;
            //  }
            front--;
            if(front < 0){
                front = cap -1;
            }
            //cout << "b4" << endl;
            array[front % cap] = v;
            //cout << "aft" << endl;
            size++;
            }
        
        void delEnd(){
            size--;
            end--;
            if(end < 0){
                end = cap-1;
            }
            if (size <= cap /4)
            {
                cap /= 2;
                T *b = new T[cap];
                for(int i = 0; i < size; i++){
                b[i] = array[front + i % size];
                //cout << b[i] << " ";
            }
            //cout <<"Look here" <<endl;
            front = 0;
            end = size -1;
            *array = *b;
            for(int i = 0; i< size; i++){
                array[i] = b[i];
                //cout << array[i] << " ";
            }
            //cout<< "Here too" << endl;
        }
        }
        void delFront(){
            size--;
            front++;
            if(front == cap){
                front = 0;
            }
            if (size <= cap /4)
            {
                cap /= 2;
                T *b = new T[cap];
                for(int i = 0; i < size; i++){
                b[i] = array[front + i % size];
                //cout << b[i] << " ";
            }
            //cout <<"Look here" <<endl;
            front = 0;
            end = size -1;
            *array = *b;
            for(int i = 0; i< size; i++){
                array[i] = b[i];
                //cout << array[i] << " ";
            }
            //cout<< "Here too" << endl;
            }

            
            
            
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
            size = 0;
            front = 0;
            end = 0;
            array = new T[cap];
        }
        T QuickSelect(int k){
            T c[size];
            for(int i = 0; i < size; i++){
                c[i] = array[(front+i)%cap];
                //cout << i <<" ";
            }
           T x = recurssive(c, 0, size-1, k);
           return x;
        }
        T WCSelect(int k){
            return QuickSelect(k);
        }
        void stableSort(){
            T d[size]; 
            for(int i = 0; i < size; i++){
                d[i] = array[(front+i)%cap];
                //cout << d[i];
            }
            mergesort(d,0,size-1);
            for(int i = 0; i < size; i++){
                array[i] = d[i];
                front = 0;
                end = size-1;
            }
            for(int i = 0; i < size; i++){
                array[i] = d[i];
            }
            front = 0;
            end = size-1;
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
            T fuckyou[size];
            for(int i = 0; i < size;i++){
                fuckyou[i] = array[(front+i)%cap];
            }
            int low = 0, high = size,mid;
            while(low != high){
                mid = (low + high)/2;
                if(e == fuckyou[mid]){
                    return mid;
                }
                else if (e > fuckyou[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid-1;
                }
            }
            if(e = fuckyou[mid]){
                return mid;
            }
            return -1;
        }
        
};
