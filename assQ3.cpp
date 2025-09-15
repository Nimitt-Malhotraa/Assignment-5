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

void findMiddle(Node* head) {
if (head == nullptr) {
cout << "List is empty." << endl;
return;
}
Node* slow = head;
Node* fast = head;
while (fast != nullptr && fast->next != nullptr) {
slow = slow->next;
fast = fast->next->next;
}
cout << "Middle element is: " << slow->data << endl;
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
insertAtEnd(head, 5);

cout << "Input: ";
displayList(head);

findMiddle(head);

return 0;
}