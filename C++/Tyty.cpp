#include <bits/stdc++.h>

using namespace std;

int main(){
    string name, lname;
    int scores[3];
    double avg;
    ofstream TestFile("testoutput.txt");

    while(name != "END"){
        cout << "Enter the students name." << endl;
        cin >> name;
        if(name == "END"){
            break;
        }
        cin >> lname;
        cout << "Enter the students 3 grades." << endl;
        cin >> scores[0] >> scores[1] >> scores[2];
        avg = (scores[0] + scores[1] + scores[2]) / 3;

        TestFile << "Name: " << name << lname << endl << "Average Score: " << avg << endl;
    }




    return 0;
}