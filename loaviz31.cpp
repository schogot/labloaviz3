#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>

using namespace std;

struct Node {
    string data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() {
        head = nullptr;
    }

    // Метод для добавления элемента в приоритетную очередь
    void enqueue(const string& data, int priority) {
        Node* newNode = new Node;               // Создаем новый узел
        newNode->data = data;                   // Присваиваем ему значение данных
        newNode->priority = priority;           // Присваиваем ему значение приоритета

        if (head == nullptr || priority > head->priority) {
            newNode->next = head;               // Если очередь пуста или приоритет нового элемента выше, 
            head = newNode;                     // то новый элемент становится головой очереди
        }
        else {
            Node* current = head;
            while (current->next != nullptr && priority <= current->next->priority) {
                current = current->next;
            }
            newNode->next = current->next;      // Вставляем новый элемент в середину очереди
            current->next = newNode;
        }
    }

    // Метод для удаления элемента из приоритетной очереди и возвращения его значения
    string dequeue() {
        if (head == nullptr) {
            cout << "Очередь пуста" << endl;   // Если очередь пуста, выводим сообщение об этом
            return "";                          // и возвращаем пустую строку
        }
        string data = head->data;                // Сохраняем значение данных первого элемента
        Node* temp = head;
        head = head->next;                       // Перемещаем указатель на следующий элемент
        delete temp;                             // Удаляем первый элемент
        return data;                             // Возвращаем сохраненное значение данных первого элемента
    }

    // Метод для вывода содержимого очереди на экран
    void printQueue() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";        // Выводим значение данных текущего элемента
            current = current->next;             // Перемещаем указатель на следующий элемент
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    PriorityQueue pq;

    string data;
    int priority;
    char choice;

    while (true) {
        cout << "Введите данные: ";
        cin >> data;

        cout << "Введите приоритет: ";
        cin >> priority;

        pq.enqueue(data, priority);

        cout << "Вы хотите добавить элемент? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    cout << "Содержимое приоритетной очереди: ";
    pq.printQueue();

    while (true) {
        cout << "Хотите исключить элемент? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            string dequeuedData = pq.dequeue();
            cout << "Исключенный элемент: " << dequeuedData << endl;
        }
        else {
            break;
        }

        cout << "Хотите добавить элемент? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }

        cout << "Введите данные: ";
        cin >> data;

        cout << "Введите приоритет: ";
        cin >> priority;

        pq.enqueue(data, priority);
    }

    cout << "Содержимое приоритетной очереди после операций: ";
    pq.printQueue();

    return 0;
}