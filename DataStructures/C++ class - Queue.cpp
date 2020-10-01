// Implementation of Queue using classes

#include<bits/stdc++.h>

using namespace std;

class Queue {
    int *Q;
    int front, rear, size;
    public:
    Queue() {
        front=rear=-1;
        size = 10;
        Q = new int[size];
    }
    Queue(int x) {
        front=rear=-1;
        size = x;
        Q = new int[size];
    }
    void enqueue(int x) {
        if(isFull()) 
            cout<<"Queue is full";
        else {
            if(front==-1)
                front=0;
            rear++;
            Q[rear] = x;
        }
    }
    int dequeue() {
        int x=-1;
        if(isEmpty())
            cout<<"Queue is Empty";
        else {
            x=Q[front];
            front++;
        } 
        return x;
    }
    void display() {
        for(int i=front; i<=rear; i++) {
            cout<<Q[i]<<" ";
        }
        cout<<endl;
    }
    bool isEmpty() {
        if(front>rear)
            return true;
        return false;
    }
    bool isFull() {
        if(rear==size-1)
            return true;
        return false;
    }
    ~Queue() {
        delete Q;
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    q.display();
    return 0;
}