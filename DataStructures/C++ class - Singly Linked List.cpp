// Implementation of Linked list using classes

#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *next=NULL;
};

class LL {
    Node *start,*last;
    public:
    LL() {
        start = NULL;
        last = NULL;
    }
    LL (vector <int> arr) {
        Node *temp= new Node;
        temp->data = arr[0];
        start=last=temp;
        for(int i=1; i<arr.size(); i++) {
            temp = new Node;
            temp->data = arr[i];
            last->next=temp;
            last=temp;
        }
    }
    void Display() {
        Node *curr=start; 
        while(curr!=NULL) {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    void Insert(int val) {
        Node *temp = new Node;
        temp->data=val;
        if(last==NULL)
            start=last=temp;
        else {
            last->next=temp;
            last=temp;
        }
        Display();
    }
    void Insert(int val, int pos) {
        Node *curr=start,*temp= new Node;
        temp->data=val;
        if(pos==1) {
            temp->next=start;
            start=temp;
        }
        else {
            for(int i=0; i<pos-2 && curr; i++) {
                curr=curr->next;
            }
            if(curr) {
                temp->next=curr->next;
                curr->next=temp;
            }
        }
        Display();
    }
    void SortInsert(int val) {
        Node *temp = new Node,*curr=start,*prev=NULL;
        temp->data = val;
        if(start == NULL)
            start = temp;
        else if(temp->data<start->data) {
            temp->next=start;
            start=temp;
        }
        else {
            while(curr!=NULL && curr->data<val) {
                prev=curr;
                curr=curr->next;
            }
            temp->next=prev->next;
            prev->next=temp;
        }
        Display();
    }
    int Delete(int pos) {
        int x=-1;
        Node *curr=start,*prev=NULL;
        if(pos==1) {
            x=start->data;
            start=start->next;
            delete curr;
        }
        else {
            for(int i=0; i<pos-1 && curr; i++) {
                prev=curr;
                curr=curr->next;
            }
            if(curr) {
                prev->next=curr->next;
                x=curr->data;
                delete curr;
            }
        }
        return x;
    }
    int Search(Node *prev, Node *curr,int key) {
        static int c=0;
        if(curr!=NULL) {
            c++;
            if(curr->data==key) {
                prev->next=curr->next;
                curr->next=start;
                start=curr;
                return c;
            }
            else
                return Search(curr, curr->next,key);
        }
        return -1;
    } 
    bool IsSorted() {
        int x=0;
        Node *curr = start;
        while(curr != NULL) {
            if(curr->data<x)
                return false;
            x=curr->data;
            curr=curr->next;
        }
        return true;
    }
    void Remove() {
        Node *curr = start, *prev = NULL;
        int x = 0;
        while(curr != NULL) {
            if(x == curr->data) {
                prev->next = curr->next;
                delete curr;
                curr=prev->next;
            }
            else {
                x = curr->data;
                prev = curr;
                curr = curr->next;
            }
        }
    }
    void Reverse() {
        Node *curr = NULL, *prev = NULL, *next = start;
        while(next != NULL) {
            prev = curr;
            curr = next;
            next = next -> next; 
            curr -> next = prev;
        }
        start = curr;
    }
    void RReverse (Node *prev, Node *curr) {     
        if(curr != NULL) {
            RReverse(curr, curr->next);
            curr->next = prev;
        }
        else {
            start = prev;
        }
    }
    void Merge (LL l2) {
        Node *first = this->start, *second = l2.start;
        if(first->data < second->data) {
            start = first;
            first = first->next;
        }
        else {
            start = second;
            second = second->next;
        }
        Node *curr = start;
        while(first != NULL && second != NULL) {
            if(first->data < second->data) {
                curr->next = first;
                curr = first;
                first = first->next;
            }
            else {
                curr->next = second;
                curr = second;
                second = second->next;    
            }
        }
        if(first != NULL) {
            curr->next = first;
        }
        else {
            curr->next = second;
        }
    }
    void MakeLoop() {
        start->next->next->next = start->next;
    }
    void IsLoop() {
        Node *fast = start, *slow = start;
        do {
            fast = fast->next;
            fast ? fast = fast->next : fast;
            slow = slow->next;
        }
        while(fast != NULL  &&  fast != slow);
        if(fast == slow) {
            cout<<"This linked list contains a Loop!!!"<<endl;
        }
        else {
            cout<<"This linked list is linear."<<endl;
        }
    }
};

int main() {
    vector <int> arr{1,3,5,7,9};
    vector <int> arr2{2,4,6,8,10};
    LL l(arr),l2(arr2);
    l.Merge(l2);
    l.MakeLoop();      //Adds loop in the linked list
    l.IsLoop();
    return 0;
}