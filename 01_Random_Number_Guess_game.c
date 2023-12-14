//Random Number guesssing game 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  printf("---Welcome to Random Number Guess game!---\n");
  srand(time(0));
  int randomN=(rand()%100)+1;
  int guess;
  int att=0;
  do{
    printf("Guess a number between 1 and 100:");
    scanf("%d",&guess);
    att++;
    if(guess<randomN){
      printf("Higher number please!");
    }
    else if(guess>randomN){
      printf("Lower number please!");
    }
    else{
      printf("Congratulations,You guessed it correct in %d attempts",att);
    }
      printf("\n");
  }while(randomN!=guess);
  return 0;
}