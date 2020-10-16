 //bubble sort iterative
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
  node* bubble_sort_LinkedList_itr(node* head)
{

  node* prev =NULL;
    node*cur = head;
    while(cur->next!=NULL)
    {
        if(cur->data > cur->next->data)
        {

            if(prev==NULL)
            {
                //first node
                node* nxt = cur->next ;
                cur->next = nxt->next ;
                nxt->next = cur ;
                head = nxt ;
                prev = head ;

            }

            else
            {

                node* nxt = cur->next ;
                prev->next = nxt ;
                cur->next = nxt->next ;
                nxt->next = cur ;
                prev = nxt ;

            }

        }
        else
        {
            cur=cur->next ;
            prev = prev->next ;
        }




    }
return head ;
}



    node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}
