

#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

Node* reverseLinkedList(Node *head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* front = head->next;

    while (curr != nullptr) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

Node *addOne(Node *head) {
    Node* newhead = reverseLinkedList(head);
    Node* temp = newhead;
    int carry = 1;
    while (temp != nullptr) {
        temp->data = temp->data + carry;
        if (temp->data < 10) {
            carry = 0;
            break;
        } else {
            carry = 1;
            temp->data = 0;
        }
        temp = temp->next;
    }
    Node* newHead = reverseLinkedList(newhead);
    if (carry == 1) {
        Node* first = new Node(1);
        first->next = newHead;
        newHead = first;
    }

    return newHead;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    Node* modifiedHead = addOne(head);

    std::cout << "Modified Linked List: ";
    printLinkedList(modifiedHead);

    return 0;
}
