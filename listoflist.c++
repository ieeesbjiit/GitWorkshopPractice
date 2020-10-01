#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *right;
    node *down;
};

node *create(int arr[],int n)
{
    node *head,*p;
    head=NULL;
    for(int i=0;i<n;i++)
    {
        if(head==NULL)
        {
            head=p=new node;
            head->data=arr[i];
            
        }
        else
        {
            p->right = new node;
            p = p->right;
        }
        p->data = arr[i];
        p->right = p->down = NULL;
            
        }    
    return head;
        
}

void printflattenhorizontally(node *head)
{
    node* temp,*cur,*tail;
    temp=head;
    while(temp->right!=NULL)
    temp=temp->right;
    tail=temp;

    cur=head;
    while(cur!=tail)
    {
        if(cur->down)
        {
            tail->right=cur->down;
            tail=cur->down;
            while(tail->right!=NULL)
            tail=tail->right;
        }
        cur=cur->right;
    }


    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->right;
    }

}


node *colflatten(node *Node)
{
    if(Node==NULL)
    return NULL;
    static node *last;
    node *next=Node->right;
    last=Node;
    if(Node->down)
    {
        Node->right=colflatten(Node->down);
    }
    if(next)
    {
        last->right=colflatten(next);
    }
    return Node;
}

void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
}





int main()
{
    int arr1[5]={1,2,3,4,5};
    int arr2[2]={6,7};
    int arr3[3]={8,9};
    int arr4[4]={10,11};
    int arr5[5]={12};
    node *head1=create(arr1,5);
    node *head2=create(arr2,2);
    node *head3=create(arr3,2);
    node *head4=create(arr4,2);
    node *head5=create(arr5,1);
    head1->down=head2;
    head2->right->down=head4;
    head1->right->right->down=head3;
    head4->right->down=head5;
    int ch;
    cout<<"\nenter 1 to print rowwise else 2 ";
    cin>>ch;
    if(ch==1)
     printflattenhorizontally(head1);
    else
     {cout<<"\n";

head1=colflatten(head1);
print(head1);
     }
}