#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
};
void displayList(Node* head) {
Node* temp = head;
while (temp != nullptr) {
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL" << endl;
}
Node* insertAtEnd(Node* head, int value) {
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
return head;
}
Node* deleteSpecificNode(Node* head, int key) {
if (head == nullptr) {
return nullptr;
}
Node* temp = head;
Node* prev = nullptr;
if (temp->data == key) {
head = temp->next;
delete temp;
return head;
}
while (temp != nullptr && temp->data != key) {
prev = temp;
temp = temp->next;
}
if (temp == nullptr) {
cout << "Node with value " << key << " not found." << endl;
} else {
prev->next = temp->next;
delete temp;
}
return head;
}
int main() {
Node* head = nullptr;
head = insertAtEnd(head, 10);
head = insertAtEnd(head, 20);
head = insertAtEnd(head, 30);
cout << "Initial List: ";
displayList(head);
cout << "Deleting node with value 20..." << endl;
head = deleteSpecificNode(head, 20);
cout << "Final List: ";
displayList(head);
return 0;
}