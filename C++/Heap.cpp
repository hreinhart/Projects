#ifndef HEAP
#define HEAP

#include "CircularDynamicArray.cpp"
 
using namespace std;

template<typename keyType> class Heap{
    public:
    Heap(){
        info = new CircularDynamicArray<keyType>;
    }
    Heap(keyType k[], int s){
        info = new CircularDynamicArray<keyType>(s);
        for(int i = 0; i < s; i++){
            (*info)[i] = k[i];
        }
        heapify();
    }
    ~Heap(){
        delete info;
    }
    keyType extractMin(){
        keyType m = (*info)[0];
        (*info)[0] = (*info)[info->length()-1];
        info->delEnd();
        sDown(0);
        return m;
    }
    keyType peekKey(){
        return (*info)[0];
    }
    void insert(keyType k){
        info->addEnd(k);
        sUp(info->length()-1);
    }
    void printKey(){
        for(int i = 0; i < info->length(); i++){
            cout << (*info)[i] << " ";
        }
        if(info->length() != 0){
            cout << endl;
        }
    }
    private:
    CircularDynamicArray<keyType> *info;
    void heapify(){
       for(int i = info->length()/2; i >=0;i--){
        sDown(i);
       }
    }
    void sDown(int i){
        int l = (i * 2) +1;
        int r = (i * 2) + 2;
        int min = i;
        if(l < info->length()&& (*info)[l] < (*info)[min]){
            min = l;
        }
        if(r < info->length() && (*info)[r] < (*info)[min]){
            min = r;
        }
        if(min != i){
            keyType tmp = (*info)[i];
            (*info)[i] = (*info)[min];
            (*info)[min] = tmp;
            sDown(min);
        }
    }
    void sUp(int i){
        for(i; i != 0 && (*info)[i] < (*info)[(i-1)/2]; i = (i-1)/2){
            keyType tmp = (*info)[i];
            (*info)[i] = (*info)[(i-1)/2];
            (*info)[(i-1)/2] = tmp;
        }
    }
};
#endif