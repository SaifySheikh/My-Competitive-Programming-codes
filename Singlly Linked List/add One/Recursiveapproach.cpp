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

 int Helper(Node* temp){
     if(temp==NULL){
         return 1;
     }
     int carry = Helper(temp->next);
     temp->data=temp->data+carry;
     if(temp->data<10){
         return 0;
     }else{
         temp->data=0;
         return 1;
     }
 }
Node *addOne(Node *head)
{
    int carry = Helper(head);
    if(carry==1){
        Node* newhead=new Node(1);
        newhead->next=head;
        return newhead;
    }
    return head;

}