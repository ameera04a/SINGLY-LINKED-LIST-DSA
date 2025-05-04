#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList{
    Node* tail;
    Node* head;
    public:
    LinkedList():tail(nullptr), head(nullptr){}

    void insertAtHead(int value){
        Node * nn = new Node(value);
        if(head==nullptr){
            head = tail = nn;
            
        }
        nn->next = head;
        head = nn;
    }
    void insertAtTail(int value){
        Node * nn = new Node(value);
        if(tail==nullptr){
            head = tail = nn;
            
        }
        tail->next = nn;
        tail = nn;
    }
    void reverse(){
        Node*curr=head;
        Node*prev=nullptr;
        Node*n;//next
        
        while(curr!=nullptr){
            n = curr->next;
            curr->next= prev;
            prev=curr;
            curr=n;
        }
        //swap head n tail
        Node*temp = head;
        head = tail;
        tail = temp;
    }
    void display(){
        Node*temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    ~LinkedList() { 
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
    }
};
int main(){
    LinkedList l;
    l.insertAtHead(10);
    l.insertAtHead(20);
    l.insertAtTail(5);
    // l.display();
    l.reverse();
    l.display();

}