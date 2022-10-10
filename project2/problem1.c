#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
        // const char * str1 = (*root)->data;
        // const char * str2 = word;
        // int flag = strcmp(str2, str1);
        // if(flag > 0)
        if(strcmp(word, (*root)->data) > 0)
            add(&((*root)->right), word);
        else
            add(&((*root)->left), word);
    }
    
}

 
void inorder ( bst_node * root ) {
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%s ", root->data);
    inorder(root->right);
}


 
char * removeSmallest (  bst_node ** root ){
    if((*root) == NULL)
        return NULL;
    bst_node *p = *root;
    bst_node *q = NULL;
    // q是p的父节点
    while(p->left != NULL)
    {
        q = p;
        p = p->left;
    }
    // q存在，说明根节点左子树不为空
    if(q)
    {
        // 最小节点有孩子节点
        if(p->right) 
            q->left = p->right;
        // 最小节点没有孩子节点
        else
            q->left = NULL;
        return p->data;
    }
    // q不存在，根节点左子树为空
    else
    {
        (*root) = (*root)->right;
        return p->data;
    }
}

 
char * removeLargest (  bst_node ** root ){
    if((*root) == NULL)
        return NULL;
    bst_node *p = *root;
    bst_node *q = NULL;
    // q是p的父节点
    while(p->right != NULL)
    {
        q = p;
        p = p->right;
    }
    // q存在，说明根节点右子树不为空
    if(q)
    {
        // 最大节点有孩子节点
        if(p->left) 
            q->right = p->left;
        // 最大节点没有孩子节点
        else
            q->right = NULL;
        return p->data;
    }
    // q不存在，根节点有子树为空
    else
    {
        (*root) = (*root)->left;
        return p->data;
    }
}


int main() {
    
    
	bst_node * root = NULL;
	
    
    char * instruction = (char*) malloc(256*sizeof(char) ) ;
    char * word = NULL; 
    
    while ( scanf("%s", instruction) > 0 ) {
        //printf ( "read: %c\n", instruction); 
        if ( strncmp(instruction,"a", 2) == 0 ) {
            //add a value to the tree
            word = (char*) malloc (256 * sizeof(char) );
            scanf("%s\n", word);
            add(&root, word);
        }
        else if ( strncmp(instruction,"s", 2) == 0 ) {
            //remove the smallest value in the tree 
            word = removeSmallest( &root);
            //free memory that was allocated for the word
            if (word != NULL) {
                free(word);
                word = NULL; 
            }
        }
        else if ( strncmp(instruction,"l", 2) == 0 ){
            //remove the largest value in the tree 
            word = removeLargest( &root);
            //free memory that was allocated for the word
            if (word != NULL) {
                free(word);
                word = NULL; 
            }
        }
        else if ( strncmp(instruction,"p", 2) == 0 ){
            //print the content of the tree in the inorder traversal
            inorder ( root );
            printf ( "\n");
        }
        else {
            printf ("Error: %s is not a valid instruction\n", instruction);
        }
        
    }
	
    if (word != NULL) {
        free(word);
        word = NULL; 
    }
	
    if (instruction != NULL) {
        free(instruction);
        instruction = NULL; 
    }

	return 0;
}




