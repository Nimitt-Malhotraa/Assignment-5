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
void insertAfterNode(Node* head, int key, int value) {
Node* temp = head;
while (temp != nullptr && temp->data != key) {
temp = temp->next;
}
if (temp == nullptr) {
cout << "Node with value " << key << " not found." << endl;
} else {
Node* newNode = new Node();
newNode->data = value;
newNode->next = temp->next;
temp->next = newNode;
}
}
int main() {
Node* head = nullptr;
head = insertAtEnd(head, 10);
head = insertAtEnd(head, 20);
head = insertAtEnd(head, 30);
cout << "Initial List: ";
displayList(head);
cout << "Inserting 25 after node 20..." << endl;
insertAfterNode(head, 20, 25);
cout << "Final List: ";
displayList(head);
return 0;
}