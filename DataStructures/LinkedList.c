#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *link;
};
struct node *head=NULL;
struct node* createnode()
{

    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return(n);
}
void insertnode()
{
    struct node *temp,*t;
    temp=createnode();
    printf("Enter number:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        t=head;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
}
void viewlist()
{
    struct node *t;
    if(head==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        t=head;
        while(t!=NULL)
        {
            printf("%d",t->data);
            t=t->link;
        }
    }
}
int main()
{
    int n;
    while(1)
{
    printf("Enter 1 to enter data and 2 to display and 3 to exit\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        insertnode();
        break;
    case 2:
        viewlist();
        break;
    case 3:
        exit(0);
    deafault:
        printf("Wrong choice");

    }
}
return 0;
}
