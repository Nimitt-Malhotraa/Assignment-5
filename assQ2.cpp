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

void displayList(Node* head) {
if (head == nullptr) {
cout << "List is empty." << endl;
return;
}
Node* temp = head;
while (temp != nullptr) {
cout << temp->data << "->";
temp = temp->next;
}
cout << "NULL" << endl;
}

void countAndDelete(Node*& head, int key) {
int count = 0;
Node* temp;
while (head != nullptr && head->data == key) {
temp = head;
head = head->next;
delete temp;
count++;
}
Node* current = head;
if (current != nullptr) {
while (current->next != nullptr) {
if (current->next->data == key) {
temp = current->next;
current->next = temp->next;
delete temp;
count++;
} else {
current = current->next;
}
}
}
cout << "Count: " << count << endl;
}

int main() {
Node* head = nullptr;
insertAtEnd(head, 1);
insertAtEnd(head, 2);
insertAtEnd(head, 1);
insertAtEnd(head, 2);
insertAtEnd(head, 1);
insertAtEnd(head, 3);
insertAtEnd(head, 1);

cout << "Original Linked List: ";
displayList(head);

int key = 1;
countAndDelete(head, key);

cout << "Updated Linked List: ";
displayList(head);

return 0;
}