#include<stdio.h>
#include<stdlib.h>

//function to print the Title if library
void printTitle() {
  printf("  ----------------------------------\n");
  printf("  |                                |\n");
  printf("  | WELCOME TO THE CENTRAL LIBRARY |\n");
  printf("  |                                |\n");
  printf("  ----------------------------------\n");
  printf("\n");
}

void listBooks() {
  FILE *file;
  file = fopen("libraryRecords/books.txt", "r");
  printf("\n");
  int nm;
  fscanf(file, "%d", &nm);
  if(nm != 0) {
    printf("The available books are:\n");
    for(int i = 0; i < nm; i++) {
      char books[50];
      fscanf(file, "%s", books);
      printf("\t%d)%s\n", i+1, books);
    }
  }
  else {
    printf("Sorry,No books available!\n");
  }
  fclose(file);
  printf("\n");

}
void returnBook() {
  char book[50],
  name[50];
  printf("Enter the name of book to return:");
  scanf("%s", book);
  printf("Enter your name:");
  scanf("%s", name);
  FILE *file;
  file = fopen("libraryRecords/userbooks.txt", "r");
  int lendSt = 1;
  char lendBook[101]="";
  strcat(lendBook, name);
  strcat(lendBook, "=");
  strcat(lendBook, book);
  while(1) {
    char TempBook[101];
    fscanf(file, "%s", TempBook);
    if(!feof(file)) {
      lendSt = strcmp(TempBook, lendBook);
      if(lendSt == 0) {
        break;
      }
    }else {
      break;
    }
  }
  fclose(file);
  if(lendSt != 0) {
    printf("\nYou haven,t lend any book of that name.Enter correct name and book\n\n");
  }
  else {
    //storing all file data in temporary file
    FILE *temp;
    file = fopen("libraryRecords/userbooks.txt", "r");
    temp = fopen("libraryRecords/tempbooks.txt", "w");
    while(1) {
      char tempLn[101];
      fscanf(file, "%s", tempLn);
      if(!feof(file)) {
        if(strcmp(tempLn, lendBook) != 0) {
          fprintf(temp, "%s\n", tempLn);
        }
      }else {
        break;
      }
    }
    fclose(file);
    fclose(temp);

    //Storing in original file
    file = fopen("libraryRecords/userbooks.txt", "w");
    temp = fopen("libraryRecords/tempbooks.txt", "r");
    while(1) {
      char tempLn[101];
      fscanf(temp, "%s", tempLn);
      if(!feof(temp)) {
        if(strcmp(tempLn, lendBook) != 0) {
          fprintf(file, "%s\n", tempLn);
        }
      }else {
        break;
      }
    }
    fclose(file);
    fclose(temp);

    //Manipulation over book
    file = fopen("libraryRecords/books.txt", "r");
    temp = fopen("libraryRecords/tempbooks.txt", "w");
    int nm;
    fscanf(file, "%d", &nm);
    fprintf(temp, "%d\n", nm+1);
    for(int i = 0; i < nm; i++) {
      char indBook[50];
      fscanf(file, "%s", indBook);
      fprintf(temp, "%s\n", indBook);
      }
    fclose(file);
    fclose(temp);

    //copying data of temporary file to main file
    file = fopen("libraryRecords/books.txt", "w");
    temp = fopen("libraryRecords/tempbooks.txt", "r");
    fscanf(temp, "%d", &nm);
    fprintf(file, "%d\n", nm);
    for(int i = 0; i < nm-1; i++) {
      char indBook[50];
      fscanf(temp, "%s", indBook);
      fprintf(file, "%s\n", indBook);
    }
    fprintf(file,"%s\n",book);
    fclose(file);
    fclose(temp);
printf("\nYour book have been accepted.Thank you for returning\n\n");
    //deleting temporary file
    remove("libraryRecords/tempbooks.txt");
  }
}

void requestBook() {
  char book[50],
  name[50];
  printf("Enter the name of book you want:");
  scanf("%s", book);
  printf("Enter your name:");
  scanf("%s", name);
  FILE *file;
  file = fopen("libraryRecords/books.txt", "r");
  int bookSt = 1;
  int nm;
  fscanf(file, "%d", &nm);
  for(int i = 0; i < nm; i++) {
    char books[50];
    fscanf(file, "%s", books);
    bookSt = strcmp(book, books);
    if(bookSt == 0) {
      break;
    }
  }
  if(bookSt != 0) {
    printf("\nSorry,The book you entered is not available at the momemt\n\n");
    fclose(file);
  }
  else {
    //writing in user records
    file = fopen("libraryRecords/userbooks.txt", "a");
    fprintf(file, "%s=%s\n", name, book);
    fclose(file);

    //storing all file data in temporary file
    FILE *temp;
    file = fopen("libraryRecords/books.txt", "r");
    temp = fopen("libraryRecords/tempbooks.txt", "w");
    fscanf(file, "%d", &nm);
    fprintf(temp, "%d\n", nm-1);
    for(int i = 0; i < nm; i++) {
      char indBook[50];
      fscanf(file, "%s", indBook);
      if(strcmp(book, indBook) != 0) {
        fprintf(temp, "%s\n", indBook);
      }
    }
    fclose(file);
    fclose(temp);

    //copying data of temporary file to main file
    file = fopen("libraryRecords/books.txt", "w");
    temp = fopen("libraryRecords/tempbooks.txt", "r");
    fscanf(temp, "%d", &nm);
    fprintf(file, "%d\n", nm);
    for(int i = 0; i < nm; i++) {
      char indBook[50];
      fscanf(temp, "%s", indBook);
      fprintf(file, "%s\n", indBook);
    }
    printf("\nYou have been allocated the %s📓📓.Return it within 30 days!\n\n", book);
    fclose(file);
    fclose(temp);

    //deleting temporary file
    remove("libraryRecords/tempbooks.txt");
  }
}

//function to print options and take the usrInput and redirect to the options
void printOptions() {
  printf("Options: \n");
  printf("\t1) List all books\n");
  printf("\t2) Request a book\n");
  printf("\t3) Return a book\n");
  printf("\t4) Exit Library\n");
  int usrInp;
  printf("\n");
  printf("Choose a option: ");
  scanf("%d", &usrInp);
  switch(usrInp) {
    case 1:
    listBooks();
    printOptions();
    break;
    case 2:
    requestBook();
    printOptions();
    break;
    case 3:
    returnBook();
    printOptions();
    break;
    case 4:
    break;
    default:
    printf("The option doesn't exist.Please enter a valid option");
    printOptions();
  }}

int main() {
  printTitle();
  printOptions();
  printf("Thank you for choosing Central Library\n");
  return 0;
}