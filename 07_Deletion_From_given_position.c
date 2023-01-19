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
void delete_from_given_position(Doubly**head, int position)
{
    if(position==-1 )//|| position>n greater than link list//)
    {
        printf(" Wrong I/P ");
    }
    else{
        Doubly*start=*head;
        Doubly*temp=NULL;
        int i=1;//initially placed at the first position of linked list
        while(i<position){
            start=start->next;
            i++;
        }
        temp=start;
        (temp->prev)->next=temp->next;
        (temp->next)->prev=temp->prev;
        free(temp);
    }
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
    printf("\n");
    delete_from_given_position(&head,3);
    print_Doubly_ll(head);

}