#include<iostream>
using namespace std;

class Student {
public:
    string name;
    int priority;
    Student* next;
    Student(string n, int p) : name(n), priority(p), next(nullptr) {}
};

class ReservationQueue {
private:
    Student* head;
    Student* tail;

public:
    ReservationQueue() : head(nullptr), tail(nullptr) {}

    void addStudent(string name, int priority) {
        Student* newStudent = new Student(name, priority);

        if (head == nullptr) {
            head = tail = newStudent;
        } else {
            tail->next = newStudent;
            tail = newStudent;
        }
        cout << "Student " << name << " added to reservation list.\n";
    }

    void removeStudent(string name) {
        if (head == nullptr) {
            cout << "Reservation list is empty.\n";
            return;
        }

        Student* curr = head;
        Student* prev = nullptr;

        if (head->name == name) {
            // Remove head
            head = head->next;
            // If list became empty
            if (head == nullptr) {
                tail = nullptr;
            }
            delete curr;
            cout << "Student " << name << " removed from reservation list.\n";
            return;
        }

        while (curr != nullptr && curr->name != name) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Student " << name << " not found in reservation list.\n";
            return;
        }

        prev->next = curr->next;

        if (curr == tail) {
            tail = prev;
        }

        delete curr;
        cout << "Student " << name << " removed from reservation list.\n";
    }

    void updatePriority(string name, int newPriority) {
        if (head == nullptr) {
            cout << "Reservation list is empty.\n";
            return;
        }

        Student* curr = head;
        while (curr != nullptr && curr->name != name) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Student " << name << " not found in reservation list.\n";
            return;
        }

        int oldPriority = curr->priority;
        curr->priority = newPriority;
        cout << "Priority updated for student " << name << " from " << oldPriority << " to " << newPriority << ".\n";
    }

    void displayReservationList() {
        if (head == nullptr) {
            cout << "Reservation list is empty.\n";
            return;
        }

        Student* temp = head;
        cout << "\nCurrent Reservation List:\n";
        while (temp != nullptr) {
            cout << "- " << temp->name << " (Priority: " << temp->priority << ")\n";
            temp = temp->next;
        }
    }

    int countStudents() {
        int count = 0;
        Student* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void serveNextStudent() {
        if (head == nullptr) {
            cout << "Reservation list is empty. No student to serve.\n";
            return;
        }

        Student* temp = head;
        cout << "Student " << temp->name << " served and removed from reservation list.\n";
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }
};

int main() {
    ReservationQueue book1;
    ReservationQueue book2;
    int choice, bookChoice;
    string name;
    int priority;

    do {
        cout << "\nLibrary Reservation System\n";
        cout << "1. Add Student\n2. Remove Student\n3. Update Student Priority\n4. Display Reservation List\n5. Count Students\n6. Serve Next Student\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }

        cout << "Choose Book (1 or 2): ";
        cin >> bookChoice;
        ReservationQueue* selectedBook = (bookChoice == 1) ? &book1 : &book2;

        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter priority (3=Research, 2=Assignment, 1=Casual): ";
                cin >> priority;
                selectedBook->addStudent(name, priority);
                break;
            case 2:
                cout << "Enter student name to remove: ";
                cin >> name;
                selectedBook->removeStudent(name);
                break;
            case 3:
                cout << "Enter student name to update priority: ";
                cin >> name;
                cout << "Enter new priority: ";
                cin >> priority;
                selectedBook->updatePriority(name, priority);
                break;
            case 4:
                selectedBook->displayReservationList();
                break;
            case 5:
                cout << "Total students in reservation list: " << selectedBook->countStudents() << endl;
                break;
            case 6:
                selectedBook->serveNextStudent();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (true);

    return 0;
}
