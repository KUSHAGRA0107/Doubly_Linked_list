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
    printf("\n");
}
void delete_from_end(Doubly**head)
{
    Doubly*temp=NULL;
    Doubly*start=*head;
    while (start->next->next!=NULL)
    {
        start=start->next;
    }
    temp=start->next;
    start->next=NULL;
    free(temp);
    
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
    delete_from_end(&head);
    print_Doubly_ll(head);

}