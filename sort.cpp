#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void append(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

void sortLinkedList(Node* head) {
    if (!head) return;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data > j->next->data) {
                swap(j->data, j->next->data);
            }
        }
    }
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    append(head, 30);
    append(head, 10);
    append(head, 50);
    append(head, 20);
    append(head, 40);

    sortLinkedList(head);
    display(head);  // Output: 10 20 30 40 50
}
