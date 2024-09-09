#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <limits.h>
#include <strings.h>
#include <algorithm>

using namespace std;

void mergeint(int array[], int const left, int const mid, int const right)
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
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeintSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeintSort(array, begin, mid);
    mergeintSort(array, mid + 1, end);
    mergeint(array, begin, mid, end);
}

void mergestr(string array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new string[subArrayOne],
         *rightArray = new string[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergestrSort(string array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergestrSort(array, begin, mid);
    mergestrSort(array, mid + 1, end);
    mergestr(array, begin, mid, end);
}

int main(int argc, char *argv[]){

    ifstream f1;
    ifstream f2;
    f1.open(argv[2]);
    f2.open(argv[3]);
        int first = 0;
        int second = 0;
        string fuk = argv[1];
        int count = 0;
        
        if(fuk == "s"){
            string f1str[20001];
            string f2str[20001];
            string same[20001];

        while(f1 >> f1str[first]){
            for(int b = 0; b < f1str[first].length(); b++){
            f1str[first].at(b) = tolower(f1str[first].at(b));}
            f1str[first].erase(remove(f1str[first].begin(), f1str[first].end(), '.'), f1str[first].end());
            f1str[first].erase(remove(f1str[first].begin(), f1str[first].end(), ','), f1str[first].end());
            f1str[first].erase(remove(f1str[first].begin(), f1str[first].end(), ' '), f1str[first].end());
            f1str[first].erase(remove(f1str[first].begin(), f1str[first].end(), ':'), f1str[first].end());
            f1str[first].erase(remove(f1str[first].begin(), f1str[first].end(), '"'), f1str[first].end());
            f1str[first].erase(remove(f1str[first].begin(), f1str[first].end(), ';'), f1str[first].end());
            f1str[first].erase(remove(f1str[first].begin(), f1str[first].end(), '!'), f1str[first].end());
            f1str[first].erase(remove(f1str[first].begin(), f1str[first].end(), '?'), f1str[first].end());
            first++;
            
        }
        while(f2 >> f2str[second]){
            for(int b = 0; b < f2str[second].length(); b++){
            f2str[second].at(b) = tolower(f2str[second].at(b));
            }
            f2str[second].erase(remove(f2str[second].begin(), f2str[second].end(), '.'), f2str[second].end());
            f2str[second].erase(remove(f2str[second].begin(), f2str[second].end(), ','), f2str[second].end());
            f2str[second].erase(remove(f2str[second].begin(), f2str[second].end(), ' '), f2str[second].end());
            f2str[second].erase(remove(f2str[second].begin(), f2str[second].end(), ':'), f2str[second].end());
            f2str[second].erase(remove(f2str[second].begin(), f2str[second].end(), '"'), f2str[second].end());
            f2str[second].erase(remove(f2str[second].begin(), f2str[second].end(), ';'), f2str[second].end());
            f2str[second].erase(remove(f2str[second].begin(), f2str[second].end(), '!'), f2str[second].end());
            f2str[second].erase(remove(f2str[second].begin(), f2str[second].end(), '?'), f2str[second].end());
            second++;
            
        }
        int k = 0;
        for(int i = 0; i < first; i++){
            count = 0;
            for(int o = 0; o < k; o++){
                if(f1str[i] == same[o]){
                    count++;
                }
            }
            for(int j = 0; j < second; j++){
                if(f1str[i] == f2str[j] && count == 0){
                    same[k] = f1str[i];
                    k++;
                    count++;
                }
            }
        }
        mergestrSort(same, 0, k-1);

        for(int l = 0; l < k; l++){
            cout << same[l] << endl;
        }
        cout << k << " words in common." << endl;
        }
        else if(fuk == "i"){
            int f1int[20001];
            int f2int[20001];
            int sameint[20001];

            while(f1 >> f1int[first]){
            //cout << f1int[first] << endl;
            first++;
            
        }
        //cout << endl;
        while(f2 >> f2int[second]){
            //cout << f2int[second]<< endl;
            second++;
            
        }
        int k = 0;
        //cout << endl;
        for(int i = 0; i < first; i++){
            count = 0;
            for(int o = 0; o < k; o++){
                if(f1int[i] == sameint[o]){
                    count++;
                }
            }
            for(int j = 0; j < second; j++){
                if(f1int[i] == f2int[j]&& count == 0){
                    sameint[k] = f1int[i];
                    //cout << sameint[k] << endl;
                    k++;
                    count++;
                }
            }
        }
        mergeintSort(sameint, 0, k-1);
        //cout << endl;
        for(int l = 0; l < k; l++){
            cout << sameint[l] << endl;
        }
        }


    f1.close();
    f2.close();

return 0;
}