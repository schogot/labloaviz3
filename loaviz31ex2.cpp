#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(const string& data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return "";
        }

        string data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool remove(const string& data) {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return false;
        }

        if (top->data == data) {
            Node* temp = top;
            top = top->next;
            delete temp;
            return true;
        }

        Node* current = top;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        return false;
    }

    string peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return "";
        }

        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Stack stack;

    string data;
    char choice;

    while (true) {
        cout << "Enter data: ";
        cin >> data;

        stack.push(data);

        cout << "You want add element? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    cout << "Choose action:\n";
    cout << "1. Delete top element of stack \n";
    cout << "2. Delete specific element\n";
    cout << "Your choice: ";

    int action;
    cin >> action;

    if (action == 1) {
    
        stack.pop();
        cout << "Top element of stack deleted" << endl;
    }
    else if (action == 2) {
        cout << "Enter element what you want to delete: ";
        cin >> data;
        bool removed = stack.remove(data);
        if (removed) {
            cout << "Element succesfully deleted from stack" << endl;
        }
        else {
            cout << "Element not found in stack" << endl;
        }
    }
    else {
        cout << "Incorrect action choice" << endl;
    }

    cout << "Stack content: ";
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    return 0;
}