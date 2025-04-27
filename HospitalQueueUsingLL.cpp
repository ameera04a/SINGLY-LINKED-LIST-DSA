#include<iostream>
using namespace std;

class Patient{ 
    public:
    int id;
    Patient* next;
    Patient(int ID):id(ID),next(nullptr){}

};
class PatientQueue{
    Patient* head;
    Patient* tail;
    public:
    PatientQueue():head(nullptr), tail(nullptr){}
    void addPatient(int id){
        //add to queue insert at tail
        Patient* nn = new Patient(id);
        if(head == nullptr && tail == nullptr){
            //empty
            head = tail = nn;
        }
        else{
            tail->next = nn;
            tail= nn;

        }
        cout<<"\nPatient added to queue";
    }
    void removePatient(int id) {
        if (head == nullptr) {
            cout << "\nNo patient in queue.";
            return;
        }
    
        Patient* curr = head;
        Patient* prev = nullptr;
    
        // If the patient to remove is at the head
        if (head->id == id) {
            if (head == tail) {
                // Only one patient in the list
                tail = nullptr;
            }
            head = head->next;
            delete curr;
            cout << "\nPatient " << id << " removed from queue.";
            return;
        }
    
        // Traverse to find the patient
        while (curr != nullptr && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }
    
        if (curr == nullptr) {
            cout << "\nPatient not found in queue.";
            return;
        }
    
        // Patient found somewhere after head
        prev->next = curr->next;
        
        // If deleting the last patient, update tail
        if (curr == tail) {
            tail = prev;
        }
    
        delete curr;
        cout << "\nPatient " << id << " removed from queue.";
    }
    void displayQueue(){
        if(head == nullptr){
            cout<<"No Pateint in queue";
            return;
        }
        Patient *temp = head;
        cout<<"\nPateints in queue: ";
        while(temp!= nullptr){
            cout<<"\nPateint "<<temp->id;
            temp = temp->next;
        }
    }
    
    int countPatients(){
        Patient *temp = head;
        int count =0;
        while(temp!= nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

};
int main() {
    PatientQueue pq;
    int choice;
    int id;

    do {
        cout << "\nHospital Queue Management\n";
        cout << "1. Add Patient\n2. Remove Patient\n3. Display Queue\n4. Count Patients\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter patient id: "; cin >> id; pq.addPatient(id); break;
            case 2: cout << "Enter patient id to remove: "; cin >> id; pq.removePatient(id); break;
            case 3: pq.displayQueue(); break;
            case 4: cout << "Total patients in queue: " << pq.countPatients() << endl; break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}