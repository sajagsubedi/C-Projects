//Rock_Paper_Scissor 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  printf("Welcome to Rock,Paper and Scissor");
  srand(time(0));
  int compN=(rand()%3)+1;
  char compInp;
  char usrInp;
  int att=0;
  printf("Choose Rock(r),paper(p) or scissor(s):");
   scanf("%c",&usrInp);
   if(compN==1){
     printf("Computer choosed Rock.");
     if(usrInp==114){
       printf("It,s a ties!");
     }
     else if(usrInp==112){
       printf("You won!");
     }
     else{
       printf("Computer won!");
     }
     printf("\n");
   }
   else if(compN==2){
  printf("Computer choosed Paper.");
     if(usrInp==114){
       printf("Computer won!");
     }
     else if(usrInp==112){
       printf("It,s a ties!");
     }
     else{
       printf("You won!");
     }
     printf("\n");
      }
   else{
  printf("Computer choosed Scissor.");
     if(usrInp==114){
       printf("You won!");
     }
     else if(usrInp==112){
       printf("Computer won!");
     }
     else{
       printf("It,s a ties!");
     }
     printf("\n");
      }
  return 0;
}