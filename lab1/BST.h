#ifndef BST_H
#define BST_H
#include <stdio.h>


typedef struct Node {
  char *name;
  struct Node *left;
  struct Node *right;
}node;

int compare(char *n1, char *n2);
node* newNode(char* name);
char *minWord(node *r);
char *maxWord(node *r);
node* newNode(char* name);
node* addEmployee(char *name, node *node);
node* deleteEmployee(char *name, node *root);

#endif
