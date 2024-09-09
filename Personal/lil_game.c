#include <stdio.h>

typedef struct character {
    char name[50];
    int maxhp;
    int curhp;
    int dmg;
    int lvl;

}character;

typedef struct item{
    char name;
    int armor;
    int dmg;
    int lvl;
    int item_id;

}item;

int main(){
character hero;
character goblin;
character kobold;
character bandit;
item helmet;
item shield;
item chestplate;
item greaves;
item boots;
item sword;
   
    hero.lvl = 1;
    goblin.name == "Goblin";
    kobold.name == "Kobold";
    bandit.name == "Bandit";

    int act;
    int loop = 1;
    printf("Hello adventurer!\n");
    printf("What is your name?\n");
    scanf("%[^\n]%*c", hero.name);
    printf("You, %s, stand before a deep and dark dungeon!\n", hero.name);
    printf("What would you like to do?\n");
    printf("Press 1 to advance. Press 2 to rest and heal. Press 3 to end.\n");
    scanf("%d", &act);

    while(act !=3){
        if(loop / 2){
            hero.lvl ++;
        }
        if(act == 1){
            hero.maxhp = 10 * hero.lvl;
            hero.dmg = 2 * hero.lvl;
            

            goblin.maxhp = 6 * hero.lvl;
            goblin.dmg = 2 * hero.lvl;

            kobold.maxhp = 4 * hero.lvl;
            kobold.dmg = 3 * hero.lvl;

            bandit.maxhp = 8 * hero.lvl;
            bandit.dmg = 1 * hero.lvl;

            printf("You travel deeper into the dungeon!\n");
        }
    loop++;
    printf("What would you like to do now?\n");
    printf("Press 1 to advance. Press 2 to rest and heal. Press 3 to end.\n");
    scanf("%d", &act);
    }

    return 0;
}