#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BST.h"


int compare(char *n1, char *n2){
  int val = strcmp(n1, n2);
  return val;
}

char *minWord(node *r){
  if(r->left == NULL){
     return r->name;
  }
  return minWord(r->left);
}

char *maxWord(node *r){
  if(r->right == NULL){
    return r->name;
  }
   return  maxWord(r->right);
}


node* newNode(char* name){
  node *new = (node*) malloc(sizeof(node));
  new->name = name;
  new->left = NULL;
  new->right = NULL;
  return new;
}

node* addEmployee(char *name, node *node){
  if(node == NULL){
   return newNode(name); 
  }
  else if(compare(name, node->name) < 0){ //new employee name is smaller
   node->left = addEmployee(name, node->left);
  }
  else if(compare(name, node->name) > 0){
   node->right = addEmployee(name, node->right);
  }
  return node;
}

node* deleteEmployee(char *name, node *root){
  if(root == NULL){ //name is not found
    return root; 
  }
  else if(compare(name, root->name) == 0){    //name is found
    if(root->left == NULL && root->right == NULL){
      free(root);
      root = NULL;
      return root;;
    }
    else if(root->left == NULL){
      char *replace = (char*)minWord(root->right);
      root->name = replace;
      deleteEmployee(name,root->left); //find duplicate and remove
    }
    else if(root->right == NULL){
      char *replace =(char*) maxWord(root->left);
      root->name = replace;
      deleteEmployee(name, root->right); //delete duplicate
    }
  }
  else if(compare(name, root->name) >0){ //name is greater than name at root
    root->right = deleteEmployee(name, root->right);
  }
  else if(compare(name, root->name) < 0){
    root->left = deleteEmployee(name, root->left);
  }
  return root;
}
