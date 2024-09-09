#include <bits/stdc++.h>
using namespace std;

int main(){
float total, net, change;

cout << "Input your annual salary." << endl;
cin >> total;
if(total < 12000){
change = total * 0.06;
net = total - change;
}
else if(total > 12000 && total < 38001){
change = total * 0.27;
net = total - change;
}
else if(total > 38000 && total < 55001){
change = total * 0.33;
net = total - change;
}
else{
change = total * 0.39;
net = total - change;
}
cout << "This year you paid $" << change << " dollars in tax. So, your net salary after taxes are taken out is $" << net << "." << endl;
    return 0;
}