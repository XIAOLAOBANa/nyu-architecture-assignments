#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

typedef struct  bst_node {
    char * data;
    struct bst_node * right;
    struct bst_node * left;
} bst_node ;

void add ( bst_node ** root, char * word );
void inorder ( bst_node * root ) ;
char * removeSmallest (  bst_node ** root );
char * removeLargest (  bst_node ** root );


void add ( bst_node ** root, char * word ) {
    if(*root == NULL)
    {
        *root = (bst_node *)malloc(sizeof(bst_node));
        (*root)->data = word;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        if(strcmp(word, (*root)->data))
            add(&((*root)->left), word);
        else
            add(&((*root)->right), word);
    }
    
}

 
void inorder ( bst_node * root ) {
    
}


 
char * removeSmallest (  bst_node ** root ){
    
    return NULL;
}

 
char * removeLargest (  bst_node ** root ){
    
    return NULL;
}




