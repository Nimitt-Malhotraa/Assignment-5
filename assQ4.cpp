#include <iostream>

using namespace std;

struct Node {
int data;
Node* next;
};

void insertAtEnd(Node*& head, int value) {
Node* newNode = new Node();
newNode->data = value;
newNode->next = nullptr;
if (head == nullptr) {
head = newNode;
} else {
Node* temp = head;
while (temp->next != nullptr) {
temp = temp->next;
}
temp->next = newNode;
}
}

void reverseList(Node*& head) {
Node* prev = nullptr;
Node* current = head;
Node* nextNode = nullptr;
while (current != nullptr) {
nextNode = current->next;
current->next = prev;
prev = current;
current = nextNode;
}
head = prev;
}

void displayList(Node* head) {
Node* temp = head;
while (temp != nullptr) {
cout << temp->data << "->";
temp = temp->next;
}
cout << "NULL" << endl;
}

int main() {
Node* head = nullptr;
insertAtEnd(head, 1);
insertAtEnd(head, 2);
insertAtEnd(head, 3);
insertAtEnd(head, 4);

cout << "Input: ";
displayList(head);

reverseList(head);

cout << "Output: ";
displayList(head);

return 0;
}