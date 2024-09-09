#include <iostream>  
#include <string>   
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;  
  
int main(int argc, char *argv[]){

    ifstream f;
    f.open(argv[1]);
    string words[10001];
    string unique[10001];
    string temp;
    string input;
    string search[10001];
    string breaker = "STOP";
    int wordc = 0;
    int index = 0;
    int unic = 0;
    int check = 0;
    int checksame = 0;
    int searchc = 0;
    int times;
    int appearc[10001];
    if (!f.is_open()) {
      cout << "Could not open" << argv[1] << endl;
      return 1;
   }
    while(f >> words[index]){
        
        for(int b = 0; b < words[index].length(); b++){
        words[index].at(b) = tolower(words[index].at(b));}
        
         
         
        for(int j = 0; j < words[index].length(); j ++){
            if(!isalpha(words[index].at(j)) && words[index].length() != 1){
                words[index+1].append(words[index], j+1, words[index].length() + 1 - j);
                words[index].erase(j);
                
                if(0 == words[index + 1].length()){
                    index--;
                    wordc--;
                    
                }
                index++;
                wordc++;
                
            }
        
         }
        if(!isalpha(words[index].at(words[index].length()-1))){
            words[index].erase(words[index].length()-1);
            wordc--;
            index--;
        }
        index ++;
        wordc ++;
    }
    f.close();
    //wordc++;
    for(int i = 0; i < wordc; i++){
        temp = words[i];
        check = 0;
        for(int k = 0; k <= unic; k++){
            if(temp == unique[k]){
                check++;
            }

        }
        if(check == 0){
            unique[unic] = temp;
            unic++;
        }
    }
    cout << "The number of words found was " << wordc << endl;
    cout << "The number of distinct words was " << unic << endl << endl;
        /*for(int a = 0; a < wordc; a++){
            cout << words[a] << " ";
            
        }*/
    while(1){
        searchc = 0;
        cout << "Enter a word: ";
        cin >> input;
        if(input == breaker){
           break;}
        
        for(int p = 0; p < unic; p++){
            checksame = unique[p].length();
            int fuk = 0;
            int len = input.length();
            //cout << checksame << " " << unique[p] << endl;
            for(int l = 0; l < len; l++){
                if(len > checksame)
                {
                    break;
                }
                
                else if(input.at(l) == '?'){
                    fuk++;
                    //cout << fuk << endl;
                } 
                else if(input.at(l) == unique[p].at(l)){
                    fuk++;
                    //cout << fuk << endl;
                }
                
            }
            if(checksame == fuk){
                search[searchc] = unique[p];
                searchc++;
            }
        }
            for(int q = 0; q < searchc; q++){
                times = 0;
            for(int r = 0; r < wordc; r++){
                if(search[q] == words[r]){
                    times++;
                }
            }
            appearc[q] = times;
            }
            
        
    if(searchc == 0){
        cout << "The word " << input << " appears 0 times" << endl;
    } 
    else{
        for(int w = 0; w < searchc; w++){
        cout << "The word " << search[w] << " appears " << appearc[w] << " times" << endl;
        }
    }

    cout << endl;
    }

    return 0;
}