// implementation of Multi list .Using array of pointer to form rows of table.Column made of linked list can
// dynamically grow. 
#include<iostream>
using namespace std;
class Schedule
{
    public:
    int time_slot;
    char *event_name;
};
class Node {
    public:
    Schedule obj;
    Node *next;
};
void printList(Node *head) 
{
    while (head != NULL)
    {
        cout <<"time slot->"<<head->obj.time_slot<< ",";
        cout <<"event name->" <<head->obj.event_name<< " ";
        head = head->next;
    }
    cout<<endl; 
}
void sortedInsert(Node** head_ref,Node* new_node) 
{
    Node* current;
    if (*head_ref == NULL || (*head_ref)->obj.time_slot>=new_node->obj.time_slot) 
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else 
    {
        current = *head_ref;
        while (current->next != NULL && current->next->obj.time_slot < new_node->obj.time_slot)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    } 
}
int main() 
{
    Node *head[3]={NULL};
    int i,j,data1;
    char name[10];
    int choice;
    do
    { 
        cout<<"1: add node"<<endl;
        cout<<"2: quit"<<endl;
        cin>>choice;
        if(choice==1) 
        {
            cout<<"In which head you wanter to enter data?\n";
            cin>>j;
            cout<<"enter data";
            cin>>data1;
            cout<<"enter name";
            cin>>name;
            Node *p;
            Node *newnode= new Node();
            newnode->obj.time_slot=data1;
            newnode->obj.event_name=name;
            newnode->next=NULL;
            sortedInsert(&head[j],newnode); 
        }
    }while(choice==1);
    for(i=0;i<3;i++) 
        printList(head[i]); 
}