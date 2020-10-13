#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left,*right;
};
void insert(struct node **q,int n)
{
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));;
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    if(*q==NULL)
        *q=temp;
    else{
        p=*q;
        while(1)
        {
            if(p->data<temp->data)
            {
                if(p->right==NULL)
               {
                   p->right=temp;
                   break;
               }
                else
                    p=p->right;
            }
            else if(p->data>temp->data)
            {
                if(p->left==NULL)
                {
                    p->left=temp;
                    break;
                }
                else
                    p=p->left;
            }
        }
    }
}
int height(struct node **q)
{
    struct node *p;
    if(*q==NULL)
        return 0;
    else{
        p=*q;
        int lh=height(&(p->left));
        int rh=height(&(p->right));
        if(lh>rh)
            return(lh+1);
        else
            return(rh+1);
    }
}
void lvldisplay(struct node **q,int l)
{
    struct node *p;
    if(*q==NULL)
        return;
    if(l==1)
        {  p=*q;
           printf("%d ",p->data);
        }
    else if(l>1)
    {
        p=*q;
        lvldisplay(&(p->left),l-1);
        lvldisplay(&(p->right),l-1);
    }
}
void lvl(struct node **q)
{
    int h=height(q);
    int i;
    for(i=1;i<=h;i++)
        lvldisplay(q,i);
}

int main()
{
    int k,x;
    struct node *q;
    q=NULL;
    while(1)
    {
            printf("Enter 1)to insert data And 2) to exit\n");
            printf("Enter your choice:\n");
            scanf("%d",&k);
            switch(k)
            {
            case 1:
                printf("Enter your data: ");
                scanf("%d",&x);
                insert(&q,x);
                break;
            case 2:
                break;
            }
            if(k==2)
                break;
    }
    int y;
    y=height(&q);
    printf("Height of tree is:%d",y);
    printf("\nLevel order display is:\n\n");
    lvl(&q);
    return 0;
}
