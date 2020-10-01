#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

class DLL
{
    struct node *start;
public:
    DLL () {start=NULL;};
    void add(int);
    void display(void);
    int counts(void);
    int inserts(int,int);
    int deletes(int);
};

int DLL::deletes(int pos)
{
    int result=0;
    if(pos > 0 &&  pos<=counts())
    {
        struct node*q=start;
        if(pos==1)
        {
            start=start->next;
            delete q;
        }
        else
        {
            for(int i=0;i<pos-2;i++)
                q=q->next;
            struct node *temp=q->next;
            q->next=temp->next;
            delete temp;
        }
        result=1;
    }
    return result;
}

int DLL::inserts(int data,int pos)
{
    int result=0;
    if(pos>0 || pos<=counts()+1)
    {
        struct node *q=start,*l;
        if(pos==1)
        {
            start=new(struct node);
            start->prev=NULL;
            start->next=q;
            start->data=data;
        }
        else
        {
            for(int i=0;i<pos-2;i++)
                q=q->next;
            l=q->next;
            q->next=new(struct node);
            q->next->prev=q;
            q->next->next=l;
            q->next->data=data;
        }
        result=1;
    }
    return result;
}

int DLL::counts(void)
{
    int counter=0;
    if(start!=NULL)
    {
        struct node*q=start;
        while(q!=NULL)
        {
            counter++;
            q=q->next;
        }
    }
    return counter;
}

void DLL::display(void)
{
    if(start==NULL)
        cout<<"\nNo list exists";
    else
    {
        struct node *q=start;
        while(q!=NULL)
        {
            cout<<q->data<<"  ";
            q=q->next;
        }
    }
}

void DLL::add(int data)
{
    if(start==NULL)
    {
        start = new(struct node);
        start->prev=start->next=NULL;
        start->data=data;
    }
    else
    {
        struct node*q=start;
        while(q->next!=NULL)
            q=q->next;
        q->next = new(struct node);
        q->next->prev = q;
        q->next->next = NULL;
        q->next->data = data;
    }
}

main()
{
	int data,position,result;
	char choice='y';
	int option;
	DLL lists;
	while(choice=='y'||choice=='Y')
	{
	    cout<<"\n1.Add a number ";
	    cout<<"\n2.Display all number ";
	    cout<<"\n3.Count items of list ";
	    cout<<"\n4.Insert a number ";
	    cout<<"\n5.Delete a number ";
	    cin>>option;

	    switch(option)
	    {
		case 1:
		{
		    cout<<"\nEnter data ";
		    cin>>data;
            lists.add(data);
		    break;
		}

		case 2:
		{
		    cout<<endl;
		    lists.display();
		    break;
		}

		case 3:
		{
		    result=lists.counts();
		    cout<<"\nNo. of entries = "<<result;
		    break;
		}

		case 4:
		{
		    cout<<"\nEnter a number ";
		    cin>>data;
		    cout<<"\nEnter the position ";
		    cin>>position;
		    if(position<=0 || position>lists.counts()+1)
		    {
			cout<<"\nInvalid Position";
			break;
		    }
		    result=lists.inserts(data,position);
		    if(result)
		    cout<<"\nNumber Inserted Successfully";
		    else
		    cout<<"\nNumber couldn't be inserted";
		    break;
		}

		case 5:
            {
                cout<<"\nEnter it's position ";
                cin>>position;
		    if(position<=0 || position>lists.counts())
		    {
			cout<<"\nInvalid Position";
			break;
		    }
		    result=lists.deletes(position);
		    if(result)
		    cout<<"\nNumber deleted Successfully";
		    else
		    cout<<"\nNumber couldn't be deleted";
		    break;
            }

		default:
		cout<<"\nInvalid Choice....Try Again";
	    }

	cout<<"\nDo you want to continue....y/Y??";
	//fflush(stdin);
	cin>>choice;
	}
}
