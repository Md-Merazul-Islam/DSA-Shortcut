#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        this->data = value;
        this->next = nullptr;
    }
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int size(Node* head) {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void insertAtIndex(Node* head, int position, int value) {
    Node* current = head;
    Node* newNode = new Node(value);
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* tail = d;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    printList(head);

    int position, value;
    std::cout << "Enter the position to insert: ";
    std::cin >> position;
    std::cout << "Enter the value to insert: ";
    std::cin >> value;

    if (size(head) < position) {
        std::cout << "Invalid Position!" << std::endl;
    } else if (position == 0) {
        insertAtHead(head, value);
    } else if (position == size(head)) {
        insertAtTail(head, tail, value);
    } else {
        insertAtIndex(head, position, value);
    }

    printList(head);

    return 0;
}
