#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

 
    void enqueue(const string& data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    string dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty" << endl;
            return "";  
        }

        string data = head->data;
        Node* temp = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
        }

        delete temp;
        return data;
    }

    
    void printQueue() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Queue queue;

    string data;
    char choice;

    while (true) {
        cout << "Enter data: ";
        cin >> data;

        queue.enqueue(data);

        cout << "You want add element? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    cout << "Queue content: ";
    queue.printQueue();

    while (true) {
        cout << "You want delete element? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            string dequeuedData = queue.dequeue();
            cout << "Deleted element: " << dequeuedData << endl;
        }
        else {
            break;
        }

        cout << "You want add element? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }

        cout << "Enter data: ";
        cin >> data;

        queue.enqueue(data);
    }

    cout << "Queue content after operations: ";
    queue.printQueue();

    return 0;
}
