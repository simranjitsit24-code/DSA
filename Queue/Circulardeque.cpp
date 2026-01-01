#include <iostream>
using namespace std;
class MyCircularDeque {
public:
    int size;
    int count;
    class Node
    {
        public:
        int val;
        Node* prev;
        Node* next;
        Node(int a=0):val(a){next = prev = nullptr;}
    };
    Node* front  = nullptr;
    Node* rear  =  nullptr;
    MyCircularDeque(int k):size(k)
    {
        front = rear = nullptr;
        count=0;
    }
    bool insertFront(int value) 
    {
     if (isFull()) return false;
     Node* newn = new Node(value);
     if (isEmpty())
     {
        front = rear = newn;
        newn->next = newn;
        newn->prev = newn;
     }
     else
     {
     newn->next = front;
     front ->prev = newn;
     rear->next = newn;
     newn->prev = rear;
     front = newn;
     }
     count++;
     return true;
    }
    bool insertLast(int value)
     {
     if (isFull()) return false;
     Node* newn = new Node(value);
     if (isEmpty())
     {
        front = rear = newn;
        newn->next = newn;
        newn->prev = newn;
     }
     else{
     rear->next = newn;
     newn->prev = rear;
     rear = rear ->next;
     front->prev = rear;
     rear->next = front;
     }
     count++;
     return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        else if (count==1) 
        {
         delete front;
         front = rear =nullptr;    
        }
        else
        {
            Node* temp = front;
            rear->next = front->next;
            front->next->prev = rear;
            front = front->next;
            delete temp;
        }
        count--;
        return true;
    }
    
    bool deleteLast() 
    {
        if (isEmpty()) return false;
        else if (count==1) 
        {
         delete rear;
         rear = front = nullptr;    
        }
        else
        {
            Node* temp = rear;
            rear = rear->prev;
            rear->next = front;
            front->prev = rear;
            delete temp;
        }
        count--;
        return true;
    }
    int getFront()
     {
         return front?front->val:-1;
    }
    
    int getRear() {
        return rear?rear->val:-1;
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() 
    {
        return count==size;
    }
};
int main()
{
    MyCircularDeque c1(4);
    c1.insertFront(5);
    c1.insertLast(6);
    c1.insertFront(7);
    c1.insertLast(8);
    cout<<"Is it full?"<<c1.isFull();
}