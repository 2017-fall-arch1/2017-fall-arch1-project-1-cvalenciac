#include <stdio.h>
#include<stdlib.h>
#include "BST.h"
#define  true 1


void printFile(){
  FILE *file;
  file = fopen("EmployeeNames.txt", "w");
  fprintf(file, "some test...\n");
  fputs("another test...\n", file);
  fclose(file);
}

void listEmployees(node *root, FILE *f){
  if(root == NULL){
    return;
  }
  listEmployees(root->left, f);
  printf("%s\n", root->name);
  fprintf(f, "%s\n", root->name);
  listEmployees(root->right, f);

}

void UI(){
  int opt;
  char *name;
  name = (char *) malloc(26);
  node *root;
  root = NULL;
  FILE *file = fopen("EmployeeNames.txt", "w");

  while(true){
    printf("Select an option:\n 1 - to list all employee names;\n 2 - to add a new employee; \n 3 - to remove an employee;\n 0 - to exit\n");
    scanf("%d",&opt);

    if(opt == 0)
      break;
    if(opt == 1){
      listEmployees(root, file);
    }
    if(opt == 2){
      fgets(name, 26, stdin);
      printf("Enter name of employee: \n");
      fgets(name,26, stdin);
      // printf("%s\n",name);
      root = addEmployee(name, root);
      name = (char*)malloc(26);
    } 
    if(opt == 3){
      fgets(name, 26, stdin);
      printf("Enter name of employee: \n");
      fgets(name, 26, stdin);
      root = deleteEmployee(name, root);
      name = (char*)malloc(26);
    }
  }fclose(file);
}
int main(){
   UI();
  
}
