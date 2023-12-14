#include<stdio.h>

void showOptions();
void encrypt();
void decrypt();

int main(){
  printf("Welcome to encrypt and decrypt algorithm\n\n");
  showOptions();
  return 0;
}
void showOptions(){
  printf(" Choose options: \n");
  printf("  1)Encryption \n");
  printf("  2)Decryption\n");
  printf("  3)Exit\n");
  int ch;
  printf("Enter your choice: ");
  scanf("%d",&ch);
  printf("\n");
  switch(ch){
    case 1:
      encrypt();
      break;
    case 2:
      decrypt();
      break;
    default:
      break;
  }
}
void encrypt(){
  char tx[30];
  int chI;
  printf("Enter the text for encryption: ");
  scanf("%s",tx);
  printf("Enter the skip value : ");
  scanf("%d",&chI);
  char *ad=tx;
  while(*ad!='\0'){
    *ad=*ad+chI;
    ad++;
  }
  printf("The cipher text is %s\n",tx);
  showOptions();
}
void decrypt(){
 char tx[30];
  int chI;
  printf("Enter the text for Decryption: ");
  scanf("%s",tx);
  printf("Enter the skip value : ");
  scanf("%d",&chI);
  char *ad=tx;
  while(*ad!='\0'){
    *ad=*ad-chI;
    ad++;
  }
  printf("The Decrypted text is %s\n",tx);
  showOptions();
}