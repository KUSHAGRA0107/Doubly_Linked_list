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
void insert_at_beg(Doubly**head,int data){
    Doubly*new=(Doubly*)malloc(sizeof(Doubly));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;

    (*head)->prev=new;
    new->next=(*head);
    *head=new;
}
void insert_at_end(Doubly** head,int data)
{
    //This implementation is done without using tail pointer in time complexity of O(N)//
    Doubly* start=*head;
    Doubly*new=(Doubly*)malloc(sizeof(Doubly));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    
    while (start->next!=NULL)
    {
        start=start->next;
    }
    new->prev=start;
    start->next=new;
}
void insert_at_given_postion(Doubly**head,int data,int position)
{
    Doubly* start=*head;
    Doubly*new=(Doubly*)malloc(sizeof(Doubly));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    int i=1;//position of initial pointer
    if(position==1)
    {
    (*head)->prev=new;
    new->next=(*head);
    *head=new;
    }
    else{
    while(i<position-1)
    {
        start=start->next;
        i++;
    }
    (start->next)->prev=new;
    new->next=start->next;
    new->prev=start;
    start->next=new;
}}
void insert_after_given_position(Doubly**head,int data,int position)
{
    Doubly* start=*head;
    Doubly*new=(Doubly*)malloc(sizeof(Doubly));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    int i=1;//position of initial pointer
    if(position==1)
    {
    (*head)->prev=new;
    new->next=(*head);
    *head=new;
    }
    else{
    while(i<position)
    {
        start=start->next;
        i++;
    }
    (start->next)->prev=new;
    new->next=start->next;
    new->prev=start;
    // (new->next)->prev=new;
    start->next=new;
}}
int main(){
    Doubly * head=NULL;
    Create(&head,1);
    Create(&head,2);
    Create(&head,3);
    Create(&head,4);
    Create(&head,5);
    Create(&head,6);
    print_Doubly_ll(head);//head-->1-->2-->3-->4-->5-->6-->NULL
    printf("\n");
    insert_at_beg(&head,9);// 9 inserted at beginning therefore head-->9-->1-->2-->3-->4-->5-->6-->NULL   
    print_Doubly_ll(head);
    insert_at_end(&head,10);
    printf("\n");
    print_Doubly_ll(head);
    insert_at_given_postion(&head,13,3);
    printf("\n");
    print_Doubly_ll(head);
    insert_after_given_position(&head,15,5);
    printf("\n");
    print_Doubly_ll(head);
}