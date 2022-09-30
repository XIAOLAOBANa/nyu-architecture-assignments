#include <stdio.h>

struct node {
    char * word;
    struct node * next;
};


void addFront(struct node * n, struct node ** head);
void show(struct node ** head);
void reverse(struct node **head);
void delete(struct node **head, int index);
 
int main() 
{
    struct node * head = 0; // head p o i n t e r for the list
    struct node n1 = { "hello", 0}; 
    struct node n2 = { "cso201", 0}; 
    struct node n3 = { "students", 0};
    
    
    addFront ( &n1, &head); 
    addFront ( &n2, &head);
    addFront ( &n3, &head);   
    

    show(&head);

    reverse(&head);
    show(&head);

    // delete(&head, 2);
    // show(&head);

    delete(&head, 1);
    show(&head);


    return 0;
}
 
void addFront(struct node * n, struct node ** head) 
{
    n->next = *head ;
    *head  = n;
    //printf ("%s	", (*head)->word ); 
}

void show(struct node ** head)
{
    struct node * current = *head;
    while (current != 0 ) 
    {
        printf ("%s\n", current->word ); 
        current = current->next;
    }
    printf("\n");
}

void reverse(struct node **head)
{
    struct node *p,*q;
    p = (*head)->next; 
    (*head)->next = NULL;                          
    while(p->next != NULL)
    {
        q = p->next;                      
        p->next = *head;                
        *head = p;
        p = q;
    }
    p->next = *head;                           
    *head = p;                     
 }


 
void delete(struct node **head, int index)
{
    struct node * current = *head;
    if(index == 1)
    {
        struct node * q = (*head)->next;       
        free(*head);
        *head = q;
    }
    else
    {
        int cnt = 1;
        while (current != 0 && cnt < index-1) 
        {
            current = current->next;
            cnt++;
        }
        struct node * p = current->next;
        current->next = p->next;
        free(p);
    } 
}
 
 
