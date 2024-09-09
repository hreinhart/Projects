#include <stdio.h>
#include <string.h>

int main(){
   
   char str1[20];
   
   printf("From tuscaloosa: new-orleans, nashville, milton or atlanta?\n");
   scanf("%s", str1);
   if (strcmp(str1, "new-orleans") == 0){
      printf("From %s: lafayette or lake-charles?\n",str1);
      scanf("%s", str1);
      if(strcmp(str1, "lafayette") == 0){
         printf("You ended your trip in %s!\n", str1);}
      else if(strcmp(str1, "lake-charles") ==0){
         printf("From %s: shreveport or alexandria?\n", str1);
         scanf("%s", str1);
         if((strcmp(str1, "shreveport") ==0) || (strcmp(str1, "alexandria") == 0)){
         printf("You ended your trip in %s!\n", str1);}}}
   else if(strcmp(str1, "nashville") == 0){
      printf("From %s: memphis or murfreesboro?\n", str1);
      scanf("%s", str1);
      if(strcmp(str1, "memphis") == 0){
         printf("You ended your trip in %s!\n", str1);}
      else if(strcmp(str1, "murfreesboro") == 0){
         printf("From %s: chattanooga or knoxville?\n", str1);
         scanf("%s", str1);
         if(strcmp(str1,"knoxville") == 0){
            printf("You ended your trip in %s!\n", str1);}
         else if(strcmp(str1, "chattanooga") ==0){
            printf("From %s: gatlinburg or asheville?\n", str1);
            scanf("%s",str1);
            if((strcmp(str1, "gatlinburg") ==0) || (strcmp(str1, "asheville") ==0)){
            printf("You ended your trip in %s!\n", str1);}}}}
   else if(strcmp(str1, "milton") == 0){
      printf("From %s: pensacola, destin or panama-city?\n", str1);
      scanf("%s",str1);
      if(strcmp(str1, "pensacola") == 0){
         printf("From %s: tallahassee or st-augustine?\n", str1);
         scanf("%s", str1);
         if(strcmp(str1, "st-augustine") == 0){
            printf("You ended your trip in %s!\n", str1);}
         else if(strcmp(str1, "tallahassee") == 0){
            printf("From %s: gainesville or ocala?\n",str1);
            scanf("%s", str1);
            if((strcmp(str1, "gainesville") == 0) || (strcmp(str1, "ocala") ==0)){
               printf("You ended your trip in %s!\n", str1);}}}
      else if(strcmp(str1, "destin") ==0){
         printf("From %s: daytona or kissimmee?\n",str1);
         scanf("%s",str1);
            if((strcmp(str1, "daytona") ==0) || (strcmp(str1, "kissimmee") ==0)){
               printf("You ended your trip in %s!\n", str1);}}
      else if(strcmp(str1, "panama-city") ==0){
         printf("From %s: tampa or jacksonville?\n",str1);
         scanf("%s",str1);
         if(strcmp(str1, "tampa") == 0){
            printf("You ended your trip in %s!\n", str1);}
         else if(strcmp(str1, "jacksonville") == 0){
            printf("From %s: clearwater, orlando, or st-petersburg?\n",str1);
            scanf("%s",str1);
            if(strcmp(str1, "st-petersburg") == 0){
               printf("You ended your trip in %s!\n", str1);}
            else if(strcmp(str1, "clearwater") == 0){
               printf("From %s: fort-myers or miami?\n", str1);
               scanf("%s",str1);
                  if((strcmp(str1, "fort-myers") == 0) || (strcmp(str1, "miami") == 0)){
                     printf("You ended your trip in %s!\n", str1);}}
            else if(strcmp(str1, "orlando") == 0){
               printf("From %s: west-palm or fort-lauderdale?\n",str1);
               scanf("%s",str1);
                  if((strcmp(str1, "west-palm") == 0) || (strcmp(str1, "fort-lauderdale") == 0)){
                     printf("You ended your trip in %s!\n", str1);}}}}}
   else if(strcmp(str1,"atlanta") == 0){
      printf("From %s: athens or columbus?\n", str1);
      scanf("%s",str1);
      if(strcmp(str1,"athens") ==0){
         printf("From %s: augusta or macon?\n", str1);
         scanf("%s",str1);
         if(strcmp(str1,"macon") ==0){
            printf("You ended your trip in %s!\n", str1);}
         else if(strcmp(str1, "augusta") ==0){
            printf("From %s: savannah or tybee-island?\n",str1);
            scanf("%s",str1);
            if((strcmp(str1, "savannah") ==0) || (strcmp(str1, "tybee-island") ==0)){
               printf("You ended your trip in %s!\n", str1);}}}
      else if(strcmp(str1, "columbus") ==0){
         printf("From %s: warner-robins or albany?\n",str1);
         scanf("%s",str1);
            if(strcmp(str1, "warner-robins") == 0){
               printf("You ended your trip in %s!\n", str1);}
            else if(strcmp(str1, "albany") == 0){
               printf("From %s: fernandina or brunswick?\n",str1);
               scanf("%s",str1);
               if((strcmp(str1, "fernandina") == 0) || (strcmp(str1, "brunswick") ==0)){
                  printf("You ended your trip in %s!\n", str1);}}}}
         
                  
            
         
         
   
   
   
   
   
 return 0;  
}