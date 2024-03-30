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

void insertTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void printNode(Node* head) {
    Node* tmp = head;
    std::cout << std::endl << "Printing values:" << std::endl << std::endl;
    while (tmp != nullptr) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl << std::endl;
}

void insertAtPosition(Node*& head, int pos, int value) {
    Node* newNode = new Node(value);
    Node* tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
        if (tmp == nullptr) {
            std::cout << std::endl << "Invalid position" << std::endl << std::endl;
            return;
        }
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void insertHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    Node* tmp = head;
    newNode->next = tmp;
    head = newNode;
}

void deletePosition(Node*& head, int pos) {
    Node* tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
        if (tmp == nullptr) {
            std::cout << std::endl << "Invalid position" << std::endl << std::endl;
            return;
        }
    }
    if (tmp->next == nullptr) {
        std::cout << std::endl << "Invalid position" << std::endl << std::endl;
        return;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}

void deleteHead(Node*& head) {
    if (head == nullptr) {
        std::cout << std::endl << "Invalid position" << std::endl << std::endl;
        return;
    }
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

int main() {
    Node* head = nullptr;
    while (true) {
        std::cout << "Option 1: Insert at tail" << std::endl;
        std::cout << "Option 2: Print" << std::endl;
        std::cout << "Option 3: Insert at any position" << std::endl;
        std::cout << "Option 4: Insert at head" << std::endl;
        std::cout << "Option 5: Delete at position" << std::endl;
        std::cout << "Option 6: Delete at head" << std::endl;
        std::cout << "Option 7: Exit" << std::endl << std::endl;
        int option;
        std::cout << "Choose option: ";
        std::cin >> option;
        std::cout << std::endl;

        if (option == 1) {
            int value;
            std::cout << "Enter value to insert at tail: ";
            std::cin >> value;
            insertTail(head, value);
        } else if (option == 2) {
            printNode(head);
        } else if (option == 3) {
            int position, value;
            std::cout << "Enter position: ";
            std::cin >> position;
            std::cout << "Enter value: ";
            std::cin >> value;
            if (position == 0) {
                insertHead(head, value);
            } else {
                insertAtPosition(head, position, value);
            }
        } else if (option == 4) {
            int value;
            std::cout << "Enter value to insert at head: ";
            std::cin >> value;
            insertHead(head, value);
        } else if (option == 5) {
            int position;
            std::cout << "Enter position to delete: ";
            std::cin >> position;
            if (position == 0) {
                deleteHead(head);
            } else {
                deletePosition(head, position);
            }
        } else if (option == 6) {
            deleteHead(head);
        } else if (option == 7) {
            std::cout << "Program finished" << std::endl;
            break;
        } else {
            std::cout << "Invalid option" << std::endl;
        }
    }
    return 0;
}
