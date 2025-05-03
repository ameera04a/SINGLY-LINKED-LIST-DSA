#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class CircularLinkedList{
    Node* tail;
    public:
    CircularLinkedList():tail(nullptr){}

    void insertAtHead(int value){
        Node * nn = new Node(value);
        if(tail==nullptr){
            tail = nn;
            tail->next = tail;
        }
        nn->next = tail->next;
        tail->next = nn;
    }
    void insertAtTail(int value){
        Node * nn = new Node(value);
        if(tail==nullptr){
            tail = nn;
            tail->next = tail;
        }
        nn->next = tail->next;
        tail->next = nn;
        tail = nn;
    }
    void display() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};
int main(){
    CircularLinkedList cll;
    cll.insertAtHead(10);
    cll.insertAtHead(20);
    cll.insertAtTail(5);
    cll.display();

}