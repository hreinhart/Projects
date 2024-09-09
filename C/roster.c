#include <stdio.h>
#include <ctype.h>

char menu(){
   char m;
   printf("MENU\n");
printf("u - Update player rating\n");
printf("r - Replace player\n");
printf("o - Output roster\n");
printf("q - quit\n");
printf("Choose an option:\n");
scanf("%c", &m);

return m;
}

void printRoster(int jerseyNums[5], int ratingNums[5]){
   
   printf("ROSTER\n");
    for(int i = 1; i <=5; i++){
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i, jerseyNums[i], ratingNums[i]);
    }
    }


int UpdatePR(int jerseyNums[5], int ratingNums[5]){ 
   int newrate;
   int i = -1 ;
   int jernum;
   int j = 0;
   printf("Enter jersey number for rating update: \n");
   scanf("%d", &jernum);
   while(i < 0){
      
   if(jernum == jerseyNums[0]){printf("Found jersey number. Enter new rating for player:\n ");
   scanf("%d", &newrate);
   while(j<1){
      if(newrate > 0 && newrate< 11){
   ratingNums[0] = newrate;
   j=1;
   i= 0;}
   else{printf("Invalid player rating. Enter valid rating: \n");
   scanf("%d", &newrate);
   }}}
   else if(jernum == jerseyNums[1]){printf("Found jersey number. Enter new rating for player:\n ");
   scanf("%d", &newrate);
   while(j<1){
      if(newrate > 0 && newrate< 11){
   ratingNums[1] = newrate;
   j=1;
   i= 1;}
   else{printf("Invalid player rating. Enter valid rating: \n");
   scanf("%d", &newrate);
      }}}
   else if(jernum == jerseyNums[2]){printf("Found jersey number. Enter new rating for player:\n ");
   scanf("%d", &newrate);
   while(j<1){
      if(newrate > 0 && newrate< 11){
   ratingNums[2] = newrate;
   j=1;
   i= 2;}
   else{printf("Invalid player rating. Enter valid rating: \n");
   scanf("%d", &newrate);
   }}}
   else if(jernum == jerseyNums[3]){printf("Found jersey number. Enter new rating for player:\n ");
   scanf("%d", &newrate);
   while(j<1){
      if(newrate > 0 && newrate< 11){
   ratingNums[3] = newrate;
   j=1;
   i= 3;}
   else{printf("Invalid player rating. Enter valid rating: \n");
   scanf("%d", &newrate);
   }}}
   else if(jernum == jerseyNums[4]){printf("Found jersey number. Enter new rating for player:\n ");
   scanf("%d", &newrate);
   while(j<1){
      if(newrate > 0 && newrate< 11){
   ratingNums[4] = newrate;
   j=1;
   i= 4;}
   else{printf("Invalid player rating. Enter valid rating: \n");
   scanf("%d", &newrate);
   }}}
   else{printf("Invalid jersey number. Enter valid jersey number: \n");
   scanf("%d", &jernum);}
   }
   return ratingNums[i];
}
    

int replaceplayer(int jerseyNums[5], int ratingNums[5]){
   int jnum;
   int jnum2;
   int rate;
   printf("Enter jersey number to replace: \n");
      scanf("%d", &jnum);
   for(int i = 0; i < 6; i++){
   if(jnum == jerseyNums[i]){
   printf("Found player. Enter new jersey number: \n");
   scanf("%d", &jnum2);
      while(jnum2 < -1 || jnum2 > 99){
         printf("Invalid jersey number. Enter valid jersey number: \n");
         scanf("%d", &jnum2);}
         jerseyNums[i] = jnum2;
         printf("Enter player rating: \n");
               scanf("%d", &rate);
               while(rate < 1 || rate > 10){
                  printf("Invalid player rating. Enter valid rating: \n");
                  scanf("%d", &rate);}
               ratingNums[i] = rate;
               return jerseyNums[i];
   }
   else if(i == 5){
   printf("Invalid jersey number. Enter valid jersey number: \n");
   scanf("%d",&jnum);
   i = 0;}
   }
}
      
/*Invalid jersey number. Enter valid jersey number:
Invalid jersey number. Enter valid jersey number:
Invalid jersey number. Enter valid jersey number:
Found player. Enter new jersey number:
Invalid jersey number. Enter valid jersey number:
Enter player rating:
Invalid player rating. Enter valid rating:
Invalid player rating. Enter valid rating:*/

   
void jerseyPrompt(int i){
  printf("Enter player %d's jersey number: \n", i);
   
}
int main(){
   char m;
    int jerseyNums[5] = {0,0,0,0,0};
    int ratingNums[5]= {0,0,0,0,0};
   int j;
    int i = 1;
 for(i = 1; i <= 5; i++){
       j = i- 1;
    jerseyPrompt(i);
        scanf("%d", &jerseyNums[i]);
        
        if(jerseyNums[i] > 99 || jerseyNums[i] < 0){
            printf("Invalid jersey number. ");
            i = i -1;
            continue;
        }
        while(j < i){
    printf("Enter player %d's rating: \n", i);
        scanf("%d", &ratingNums[i]);
        
        if(ratingNums[i] > 10 || ratingNums[i] < 1){
            printf("Invalid player rating. ");
            j = j -1;
            
        }
        j++;
        }
    }
    
    printRoster(jerseyNums, ratingNums);


      

while(m != 'q'){
   menu();
   scanf("%c", &m);
if(m == 'q'){ continue;
   }
   else if(m == 'r'){ replaceplayer(jerseyNums, ratingNums);
      char menu();
   }
   else if(m == 'o'){ printRoster(jerseyNums, ratingNums);
       char menu();
      }
   else if(m == 'u'){ UpdatePR(jerseyNums,ratingNums);
       char menu();
       }
   else{printf("Invalid option.\n"); }
}
   
    return 0;
}
