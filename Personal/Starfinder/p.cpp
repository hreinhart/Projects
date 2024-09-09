#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fstream>

using namespace std;

/* book 1 specification
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
   */

typedef struct enemy{
    
    string archetype[20];
    string name[20];
    int str;
    int dex;
    int con;
    int intel;
    int wis;
    int chr;


} enemy;

void enemycatalog(int CR, int rndm, ofstream &encfile){


}

typedef struct weapon
{
    string type;
    string cata;
    string name;
    int lvl;
    string handed;
    string dmg;
    string crit;
    string capacity;
    string special;
    int ID;
    
} weapon;

void weaponcatalog(int CR, int rndm, ofstream &encfile, int i){

    weapon Batontact; Batontact.type = "Basic Melee"; Batontact.cata = "N/A"; Batontact.name = "Baton, tactical"; Batontact.lvl = 1;
    Batontact.handed = "One-Handed"; Batontact.dmg = "1d4 Bludge"; Batontact.crit = "N/A"; Batontact.capacity = "N/A"; 
    Batontact.special = "Analog, operative"; Batontact.ID = 1;
    
    weapon Batgloveces; Batgloveces.type = "Basic Melee"; Batgloveces.cata = "N/A"; Batgloveces.name = "Battleglove, cestus";
    Batgloveces.lvl = 1; Batgloveces.handed = "One-Handed"; Batgloveces.dmg = "1d4 Bludge"; Batgloveces.crit = "N/A";
    Batgloveces.capacity = "N/A"; Batgloveces.special = "Analog";Batgloveces.ID = 2;

}

/*typedef struct armor
{   
    string name;
    string resist;
    string type;
    int ID;
//Integrated into robotic creatures
} armor;
*/

/* void armorcatalog(int b, ofstream &encfile){
    
    armor example;
    example.name = "Example";
    example.resist = "Rock";
    example.type = "Light";
    example.ID = 1001;

        if(b == 0){
        cout << example.name << endl << example.resist << endl << example.type << endl << example.ID << endl;
    } 

    encfile << "Armor: " << example.name << endl << "Resistances: " << example.resist << endl << "Type: " << example.type << endl << example.ID << endl << endl;
    // DO NOT NEED FOR ROBOTS THEY HAVE THEIR OWN CR FROM THEIR PLATING
} */  




typedef struct equipment
{   
    string cata;
    string name;
    int lvl;
    string handed;
    string dmg;
    string crit;
    string capacity;
    string special;
    int ID;

} equipment;

void equipmentcatalog(int CR, int rndm, ofstream &encfile, int i){

    
}


void CRCalc(int &CR){
    /* 
    Used to Calculate the CR of the encounter to help decide
    differences between police encounters by adding a variable
    to the random number generated in the other functions. 
    */
   
    int lvl, num = -1, total = 0; // num needs -1 to account for 0 at end
    int dif;
    cout << "Enter a new characters level. Enter 0 to end." << endl;
    cin >> lvl; // get lvl
    if(lvl < 21){
     total += lvl; // add to total
    num++; // num of players
    }
    else{
        cout << "Not valid." << endl;
    }
    while(lvl != 0){
        cout << "Enter a new characters level. Enter 0 to end." << endl;
        cin >> lvl; // get lvl
        if(lvl < 21){
        total += lvl; // add to total
        num++; // num of players
        }
        else{
        cout << "Not valid." << endl;
        }
    }

    // CR boost for large party
    if(num >= 6){
        CR = (total / num) + 1;

    }
    // CR reduction for small party
    else if(num < 4){
        CR = (total / num) - 1;
    }
    //CR for normal party
    else{
        CR = (total / num);
    }

    cout << "Enter difficulty of Encounter." << endl << "1 for Easy, 2 for Average, 3 for Challenging, 4 for Hard, 5 for Epic." << endl;
    cin >> dif;

    if(dif == 1){
        CR = CR -1;
    }
    else if(dif == 2){
        CR = CR;
    }
    else if(dif == 3){
        CR = CR + 1;
    }
    else if(dif == 4){
        CR = CR + 2;
    }
    else{
        CR = CR + 3;
    }
    
    if(CR < 1){
        CR = 1;
    }
    

    cout << "The CR for the encounter is " << CR << "." << endl;

}

void enemyselect(int CR, ofstream &encfile){
    
    int enrnd = rand() % 1;
    encfile << "Enemy " << enrnd << endl;
    
    enemycatalog(CR, enrnd, encfile);
}

/*void armorselect(int CR, ofstream &encfile){
    //Define and select some armor for npcs
    //use time as seed for random numbers
    // Will produce different numbers every time
    int rndarm = rand() % 1;

    armorcatalog(rndarm, encfile);
//No need for robots
}*/
void weaponselect(int CR, ofstream &encfile, int j){ 
    // Define and select 1 or 2 weapon(s)
    int weprnd = rand() % 1;
    
    weaponcatalog(CR, weprnd, encfile, j);
    
}

void equipmentselect(int CR, ofstream &encfile, int l){
    //Define and select some equipment specifically 1-3
    
    int rndequip = CR + rand() % 1;

    encfile << "Equip: " << rndequip << endl;
     
    equipmentcatalog(CR, rndequip, encfile, l);
}

int main(){
    ofstream encfile;
    encfile.open("Encounter.txt");

    int CR;
    CRCalc(CR);

/* Check CRCalc with this.
cout << CR << endl;
*/
    srand(time(0));

    int enact = 0;
    int ennum = 2 + (rand() % 4);
    double enCRpos[] = { 0.3, 0.5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double enCRact[5];
    double sum = CR + 0.00000000001;
    int rndm;
    double avg = sum / (ennum);
   // cout << sum << " <=sum avg=>  "<< avg << endl;
    
     //Need this to loop and randomly divide up the CR into 2-5 parts.
    
    for(int i = 0; i < ennum; i++){
        
        rndm = rand() % 12;
        if(sum < enCRpos[rndm] || enCRpos[rndm] +0.11 < avg){
            //int t = 0;
            while(sum < enCRpos[rndm] || enCRpos[rndm] + 0.11 < avg){
                
                rndm = rand() % 12;
                //cout << enCRpos[rndm] <<" <=rndm=>  " << rndm << " avg =>" << avg << endl;
                /*if(t > 10){
                    break;
                }
                t++;*/
            }
        }
        enCRact[i] = enCRpos[rndm];
        sum = sum - enCRact[i];
        enact++;
       // cout << sum << " <=sum " << avg << " <=avg act=> "<< enCRact[i]  << " actnumen =>" << enact<< endl;
        avg = (sum / (ennum - enact));

        if(sum < 0.3 ){
            break;
        }
        
        

        
    }

    for(int i = 0; i < enact; i ++){

        cout <<"Creature:" << i + 1 <<" is CR " << enCRact[i] << endl;
    }
    
   
   for(int i = 0; i < enact; i ++){
    //armorselect(enCRact[i], encfile); //DO not need for robots
    enemyselect(enCRact[i], encfile);
    encfile << endl;
    for(int j = 0; j <= rand() % 2; j++){
        weaponselect(enCRact[i], encfile, j);
        }
    encfile << endl;
    for(int l = 0; l <= rand() % 3; l++){
    equipmentselect(enCRact[i], encfile, l);
        }
    encfile << endl;
    }

    
   encfile.close();
    return 0;
}