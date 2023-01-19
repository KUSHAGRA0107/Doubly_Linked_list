#include<stdio.h>
#include<stdlib.h>
struct Doubly_ll
{
    int data;
    struct Doubly_ll* prev;
    struct Doubly_ll* next;
};
typedef struct Doubly_ll Doubly;
void Create(Doubly** head,Doubly** tail,int data)
{
    Doubly*new=(Doubly*)malloc(sizeof(Doubly));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head==NULL)
    {
        *head=new;
        *tail=new;   }
    else{
        Doubly* start=*head;
        while(start->next!=NULL)
        {
            start=start->next;
        }
        start->next=new;
        new->prev=start;
        *tail=new;    
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
void insert_at_end(Doubly** tail,int data)
{
    //This implementation is done using tail pointer in time complexity of O(1)//
    Doubly*new=(Doubly*)malloc(sizeof(Doubly));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    (*tail)->next=new;
    new->prev=*tail;
}
int main(){
    Doubly * head=NULL;
    Doubly * tail=NULL;
    Create(&head,&tail,1);
    Create(&head,&tail,2);
    Create(&head,&tail,3);
    Create(&head,&tail,4);
    Create(&head,&tail,5);
    Create(&head,&tail,6);
    print_Doubly_ll(head);//head-->1-->2-->3-->4-->5-->6-->NULL
    printf("\n");
    insert_at_beg(&head,9);// 9 inserted at beginning therefore head-->9-->1-->2-->3-->4-->5-->6-->NULL   
    print_Doubly_ll(head);
    insert_at_end(&tail,10);
    printf("\n");
    print_Doubly_ll(head);

}