#include<stdio.h>

void printWelcome(){
  printf("      -------------------------------\n");
  printf("      |                             |\n");
  printf("      | WELCOME TO TIC,TAC,TOE GAME |\n");
  printf("      |                             |\n");
  printf("      -------------------------------\n");
  printf("\n");
}

void showTable(char gmData[9]){
  printf("\t\t     |     |     \n");  printf("\t\t  %c  |  %c  |  %c  \n",(gmData[0]=='O' || gmData[0]=='X')?gmData[0]:'1',(gmData[1]=='O'||gmData[1]=='X')?gmData[1]:'2',gmData[2]?gmData[2]:'3');

  printf("\t\t     |     |    \n");
  printf("\t\t------------------\n");
  printf("\t\t     |     |     \n");
  printf("\t\t  %c  |  %c  |  %c  \n",gmData[3]?gmData[3]:'4',gmData[4]?gmData[4]:'5',gmData[5]?gmData[5]:'6');
  printf("\t\t     |     |      \n");
  printf("\t\t------------------\n");
  printf("\t\t     |     |     \n");
  printf("\t\t  %c  |  %c  |  %c  \n",gmData[6]?gmData[6]:'7',gmData[7]?gmData[7]:'8',gmData[8]?gmData[8]:'9');
  printf("\t\t     |     |     \n");
}
int checkIsGame(char provGmData[9]) {
    for (int i = 0; i < 3; i++) {
        if (provGmData[i] &&
            provGmData[i] == provGmData[i + 3] &&
            provGmData[i] == provGmData[i + 6]) {
            return (provGmData[i] == 'O') ? 1 : -1;
        } else if (provGmData[i * 3] &&
                   provGmData[i * 3] == provGmData[i * 3 + 1] &&
                   provGmData[i * 3] == provGmData[i * 3 + 2]) {
            return (provGmData[i * 3] == 'O') ? 1 : -1;
        }
    }

    if (provGmData[0] &&
        provGmData[0] == provGmData[4] &&
        provGmData[0] == provGmData[8]) {
        return (provGmData[0] == 'O') ? 1 : -1;
    } else if (provGmData[2] &&
               provGmData[2] == provGmData[4] &&
               provGmData[2] == provGmData[6]) {
        return (provGmData[2] == 'O') ? 1 : -1;
    }

    return 0;
}
int usrInp(char gmData[9],int in,int Turn){ 
  if(gmData[in-1]!='O' && gmData[in-1] !='X'){
    gmData[in-1]=Turn==1?'O':'X';
  }
  else{
    int nin;
    printf("Invalid option!\n");
    printf("Player %d(%c):",Turn==1?1:2,Turn==1?'O':'X');
    scanf("%d",&nin);
    usrInp(gmData,nin,Turn);
  }
  return checkIsGame(gmData);
}
  
int main(){
  char gmData[9];
  int Turn=1;
  int FirstTurn=1;
  int Game=0;
  int nV=0;
  printWelcome();
  while(Game==0 && nV!=9){
    int in;
  showTable(gmData);
  printf("Player %d(%c):",Turn==1?1:2,Turn==1?'O':'X');
  scanf("%d",&in);
  Game=usrInp(gmData,in,Turn);
  nV++;
  if(Game!=0 || nV==9){
    break;
  }
  Turn=(Turn==1)?2:1;
  }
  if(Game==1){
    printf("Congratulations! Player 1(O) won👏👏\n");
  }
  else if(Game==-1){
    printf("Congratulations! Player 2(C) won👏👏\n");
  }
  else{
    printf("It,s a tie!\n");
  }
  return 0;
  };