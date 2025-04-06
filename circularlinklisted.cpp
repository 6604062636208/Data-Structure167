#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up the memory
    ~CircularLinkedList() {
        if (head != nullptr) {
            Node* current = head;
            Node* nextNode;
            do {
                nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);
        }
    }

    // Insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Point tail to head to make it circular
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Update the tail's next to head
        }
    }

    // Delete the first node with a specific value
    void remove(int value) {
        if (head == nullptr) return;

        Node *current = head, *prev = tail;

        // Find the node to delete
        do {
            if (current->data == value) {
                if (current == head) {
                    head = head->next;
                    tail->next = head; // Update tail's next if head was deleted
                    delete current;
                    if (head == nullptr) tail = nullptr; // List is now empty
                } else {
                    prev->next = current->next;
                    if (current == tail) {
                        tail = prev; // Update tail if the last node was deleted
                    }
                    delete current;
                }
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
    }

    // Display all nodes in the list
    void display() const {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    std::cout << "Circular Linked List: ";
    cll.display();

    cll.remove(20);
    std::cout << "After removing 20: ";
    cll.display();

    return 0;
}
