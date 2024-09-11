#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

uint64_t djb2(string str) {
    const char *ptr = str.c_str();
    uint64_t hash = 5381;
    int c;
    while ((c = *ptr++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

class Person {
public:
    string id;
    string first;
    string last;
    string email;
    string phone;
    string city;
    string state;
    string postalCode;
};

class HashTable {
        int size;
        list<Person> *htable;
    public:
        HashTable(int tsize){
            this->size = tsize;
            htable = new list<Person>[size];
        }
        void search(string key);
        void insert(string key, Person p);

        void print(string key);
};

void HashTable::search(string key){
    int i = djb2(key) % size;
    i ++;
    i--;
    int l = 0;
    for(auto x : htable[i]){
        if(x.id == key || x.first == key || x.last == key || x.phone == key || x.email == key || x.city == key || x.state == key || x.postalCode == key){
        l++;}
    }
    if(l > 0){
        cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
    }
    for(auto x : htable[i]){
        if(x.id == key || x.first == key || x.last == key || x.phone == key || x.email == key || x.city == key || x.state == key || x.postalCode == key){
            cout << x.id <<"," << x.first <<"," << x.last <<"," << x.email <<"," << x.phone <<"," << x.city <<"," << x.state <<"," << x.postalCode << endl;
            l++;
        }
    }
    if(l == 0){
        cout << "No results" << endl;
    }
}
void HashTable::insert(string key, Person p){
    string key2;
    // "Id", "FirstName", "LastName", "Email", "Phone", "City", "State", "PostalCode"
    if(key == "Id"){
        key2 = p.id;
    }
    else if(key == "FirstName"){
        key2 = p.first;
    }
    else if(key == "LastName"){

        key2 = p.last;
    }
    else if(key == "Email"){
        key2 = p.email;
    }
    else if(key == "Phone"){
        key2 = p.phone;
    }
    else if(key == "City"){
        key2 = p.city;
    }
    else if(key == "State"){
        key2 = p.state;
    }
    else{
        key2 = p.postalCode;
    }
    int i = djb2(key2) % size;
    i++;
    i--;
    htable[i].push_back(p);
}
void HashTable::print(string key){
    int j;
    int k;
    
    //int tempcount[100] = [0];
    int count = 0;
    string tempsin;
    int n = 99;
    if(key == "Id"){
        for (int i = 0; i < size; i++){
            j = 0;
            
            string temp[100][20];
            string temp2[100][20];
        for(auto x : htable[i]){
            if(j == 0){
            cout << i << ": ";
            }
            
            temp[j][20] = x.id;
            j++;
            }
            for(int i = 0; i < n; i++){
                count = 0;
                tempsin = temp[i][20];
                //cout << "tempsin " << tempsin << endl;
                    for(int m = 0; m < n; m++){
                        if(tempsin == temp2[m][20]){
                            count++;
                        }
                    }
                if(count == 0){
                    temp2[i][20] = temp[i][20];
                }
            }
            for(int i = 0; i < n; i++){
                count = 0;
                if(temp[i][20] != ""){
                cout << temp2[i][20];}
                    for (int l = 0; l < n; l++)
                    {
                        if(temp2[i][20] == temp[l][20]){
                            count++;
                        }
                    }
                if(temp2[i][20] != ""){
                cout << " (" << count << "),";}    
            }
            if(j > 0){
            cout << endl;
        }
        }
    }
    else if(key == "FirstName"){
        for (int i = 0; i < size; i++){
            j = 0;
            
            string temp[100][20];
            string temp2[100][20];
        for(auto x : htable[i]){
            if(j == 0){
            cout << i << ": ";
            }
            
            temp[j][20] = x.first;
            j++;
            }
            for(int i = 0; i < n; i++){
                count = 0;
                tempsin = temp[i][20];
                //cout << "tempsin " << tempsin << endl;
                    for(int m = 0; m < n; m++){
                        if(tempsin == temp2[m][20]){
                            count++;
                        }
                    }
                if(count == 0){
                    temp2[i][20] = temp[i][20];
                }
            }
            for(int i = 0; i < n; i++){
                count = 0;
                if(temp[i][20] != ""){
                cout << temp2[i][20];}
                    for (int l = 0; l < n; l++)
                    {
                        if(temp2[i][20] == temp[l][20]){
                            count++;
                        }
                    }
                if(temp2[i][20] != ""){
                cout << " (" << count << "),";}    
            }
            if(j > 0){
            cout << endl;
        }
        }
    }
    else if(key == "LastName"){
     for (int i = 0; i < size; i++){
            j = 0;
            
            string temp[100][20];
            string temp2[100][20];
        for(auto x : htable[i]){
            if(j == 0){
            cout << i << ": ";
            }
            
            temp[j][20] = x.last;
            j++;
            }
            for(int i = 0; i < n; i++){
                count = 0;
                tempsin = temp[i][20];
                //cout << "tempsin " << tempsin << endl;
                    for(int m = 0; m < n; m++){
                        if(tempsin == temp2[m][20]){
                            count++;
                        }
                    }
                if(count == 0){
                    temp2[i][20] = temp[i][20];
                }
            }
            for(int i = 0; i < n; i++){
                count = 0;
                if(temp[i][20] != ""){
                cout << temp2[i][20];}
                    for (int l = 0; l < n; l++)
                    {
                        if(temp2[i][20] == temp[l][20]){
                            count++;
                        }
                    }
                if(temp2[i][20] != ""){
                cout << " (" << count << "),";}    
            }
            if(j > 0){
            cout << endl;
        }
        }
    }
    else if(key == "Email"){
        for (int i = 0; i < size; i++){
            j = 0;
            
            string temp[100][20];
            string temp2[100][20];
        for(auto x : htable[i]){
            if(j == 0){
            cout << i << ": ";
            }
            
            temp[j][20] = x.email;
            j++;
            }
            for(int i = 0; i < n; i++){
                count = 0;
                tempsin = temp[i][20];
                //cout << "tempsin " << tempsin << endl;
                    for(int m = 0; m < n; m++){
                        if(tempsin == temp2[m][20]){
                            count++;
                        }
                    }
                if(count == 0){
                    temp2[i][20] = temp[i][20];
                }
            }
            for(int i = 0; i < n; i++){
                count = 0;
                if(temp[i][20] != ""){
                cout << temp2[i][20];}
                    for (int l = 0; l < n; l++)
                    {
                        if(temp2[i][20] == temp[l][20]){
                            count++;
                        }
                    }
                if(temp2[i][20] != ""){
                cout << " (" << count << "),";}    
            }
            if(j > 0){
            cout << endl;
        }
        }
    }
    else if(key == "Phone"){
        for (int i = 0; i < size; i++){
            j = 0;
            
            string temp[100][20];
            string temp2[100][20];
        for(auto x : htable[i]){
            if(j == 0){
            cout << i << ": ";
            }
            
            temp[j][20] = x.phone;
            j++;
            }
            for(int i = 0; i < n; i++){
                count = 0;
                tempsin = temp[i][20];
                //cout << "tempsin " << tempsin << endl;
                    for(int m = 0; m < n; m++){
                        if(tempsin == temp2[m][20]){
                            count++;
                        }
                    }
                if(count == 0){
                    temp2[i][20] = temp[i][20];
                }
            }
            for(int i = 0; i < n; i++){
                count = 0;
                if(temp[i][20] != ""){
                cout << temp2[i][20];}
                    for (int l = 0; l < n; l++)
                    {
                        if(temp2[i][20] == temp[l][20]){
                            count++;
                        }
                    }
                if(temp2[i][20] != ""){
                cout << " (" << count << "),";}    
            }
            if(j > 0){
            cout << endl;
        }
        }
    }
    else if(key == "City"){
        for (int i = 0; i < size; i++){
            j = 0;
            
            string temp[100][20];
            string temp2[100][20];
        for(auto x : htable[i]){
            if(j == 0){
            cout << i << ": ";
            }
            
            temp[j][20] = x.city;
            j++;
            }
            for(int i = 0; i < n; i++){
                count = 0;
                tempsin = temp[i][20];
                //cout << "tempsin " << tempsin << endl;
                    for(int m = 0; m < n; m++){
                        if(tempsin == temp2[m][20]){
                            count++;
                        }
                    }
                if(count == 0){
                    temp2[i][20] = temp[i][20];
                }
            }
            for(int i = 0; i < n; i++){
                count = 0;
                if(temp[i][20] != ""){
                cout << temp2[i][20];}
                    for (int l = 0; l < n; l++)
                    {
                        if(temp2[i][20] == temp[l][20]){
                            count++;
                        }
                    }
                if(temp2[i][20] != ""){
                cout << " (" << count << "),";}    
            }
            if(j > 0){
            cout << endl;
        }
        }
    }
    else if(key == "State"){
        for (int i = 0; i < size; i++){
            j = 0;
            
            string temp[100][20];
            string temp2[100][20];
        for(auto x : htable[i]){
            if(j == 0){
            cout << i << ": ";
            }
            
            temp[j][20] = x.state;
            j++;
            }
            for(int i = 0; i < n; i++){
                count = 0;
                tempsin = temp[i][20];
                //cout << "tempsin " << tempsin << endl;
                    for(int m = 0; m < n; m++){
                        if(tempsin == temp2[m][20]){
                            count++;
                        }
                    }
                if(count == 0){
                    temp2[i][20] = temp[i][20];
                }
            }
            for(int i = 0; i < n; i++){
                count = 0;
                if(temp[i][20] != ""){
                cout << temp2[i][20];}
                    for (int l = 0; l < n; l++)
                    {
                        if(temp2[i][20] == temp[l][20]){
                            count++;
                        }
                    }
                if(temp2[i][20] != ""){
                cout << " (" << count << "),";}    
            }
            if(j > 0){
            cout << endl;
        }
        }
    }
    else{
        for (int i = 0; i < size; i++){
            j = 0;
            
            string temp[100][20];
            string temp2[100][20];
        for(auto x : htable[i]){
            if(j == 0){
            cout << i << ": ";
            }
            
            temp[j][20] = x.postalCode;
            j++;
            }
            for(int i = 0; i < n; i++){
                count = 0;
                tempsin = temp[i][20];
                //cout << "tempsin " << tempsin << endl;
                    for(int m = 0; m < n; m++){
                        if(tempsin == temp2[m][20]){
                            count++;
                        }
                    }
                if(count == 0){
                    temp2[i][20] = temp[i][20];
                }
            }
            for(int i = 0; i < n; i++){
                count = 0;
                if(temp[i][20] != ""){
                cout << temp2[i][20];}
                    for (int l = 0; l < n; l++)
                    {
                        if(temp2[i][20] == temp[l][20]){
                            count++;
                        }
                    }
                if(temp2[i][20] != ""){
                cout << " (" << count << "),";}    
            }
            if(j > 0){
            cout << endl;
        }
        }
    }
    
}
string getVal(istream &is, string &str) {
    char ch;
    string line;

    is >> ch;
    getline(is, line);

    str = ch + line;
    return str;
}

bool isValidKey(const string &key) {
    string validKeys[8] = { "Id", "FirstName", "LastName", "Email", "Phone", "City", "State", "PostalCode" };
    for (int i = 0; i < 8; i++) {
        if (key == validKeys[i]) {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        cout << "Usage: ./a.out filename.txt table_size key" << endl;
        return 1;
    }

    string filename = argv[1];
    int tableSize = stoi(argv[2]);
    string key = argv[3];

    ifstream file(filename);
    if (!file) {
        cout << "Unable to open " << filename << endl;
        return 2;
    }

    if (!isValidKey(key)) {
        cout << "Invalid key: " << key << endl;
        return 3;
    }
   
    // This is an example of how to retreive the tokens from the input file
    // You will need to modify this to fit your needs to build the hash table
    string line, token;
    HashTable h(tableSize);
    getline(file, line); // consume header line
    while (getline(file, line)) {
        istringstream iss(line);
        Person p;
        int yay = 0;
        while (getline(iss, token, '\t')) {
            if(yay == 0){
                p.id = token;
                
            }
            else if(yay == 1){
                p.first = token;
                
            }
            else if(yay == 2){
                p.last = token;
                
            }
            else if(yay == 3){
                p.email = token;
                
            }
            else if(yay == 4){
                p.phone = token;
                
            }
            else if(yay == 5){
                p.city = token;
                
            }
            else if(yay == 6){
                p.state = token;
                
            }
            else{
                p.postalCode = token;
                
            }
            yay++;
            
        }
        // cout << "ID " << p.id << endl;
        // cout << "First " << p.first << endl;
        // cout << "Last " << p.last << endl;
        // cout << "Email " << p.email << endl;
        // cout << "Phone " << p.phone << endl;
        // cout << "City " << p.city << endl;
        // cout << "State " << p.state << endl;
        // cout << "Postal " << p.postalCode << endl;
        h.insert(key, p);
    }

    cout << "Commands:" << endl << "\tprint" << endl << "\tlookup <key>" << endl << "\tquit" << endl;
    string cmd, val;
    while (1) {
        cout << endl << "Enter a command:" << endl;
        cin >> cmd;
        if (cmd == "quit") {
            break;
        }
        else if (cmd == "print") {
            h.print(key);
        }
        else if (cmd == "lookup") {
            string search = getVal(cin, val);
            
            h.search(search);
            
        }
        else {
            getline(cin, val);
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
