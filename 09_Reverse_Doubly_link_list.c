 #include<stdio.h>
#include<stdlib.h>
struct Doubly_ll
{
    int data;
    struct Doubly_ll* prev;
    struct Doubly_ll* next;
};
typedef struct Doubly_ll Doubly;
void Create(Doubly** head,int data)
{
    Doubly*new=(Doubly*)malloc(sizeof(Doubly));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head==NULL)
    {
        *head=new;
    }
    else{
        Doubly* start=*head;
        while(start->next!=NULL)
        {
            start=start->next;
        }
        start->next=new;
        new->prev=start;
    }
}
void print_Doubly_ll(Doubly* head)
{
    Doubly* start=head;
    while(start!=NULL)
    {
        printf("%d-->",start->data);
        start=start->next;
    }
}
void reverse(Doubly**head)
{
    Doubly*current=*head;
    Doubly*next=NULL;
    while (current->next!=NULL)
    {
        next=current->next;
        current->next=current->prev;
        current->prev=next;
        current=next;
    }
        current->next=current->prev;
        current->prev=NULL;
        (*head)=current;
}
int main(){
    Doubly * head=NULL;
    Create(&head,1);
    Create(&head,2);
    Create(&head,3);
    Create(&head,4);
    Create(&head,5);
    Create(&head,6);
    print_Doubly_ll(head);
    reverse(&head);
    printf("\n");
    print_Doubly_ll(head);
}