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
void searchNode(Node* head, int key) {
if (head == nullptr) {
cout << "List is empty." << endl;
return;
}
Node* temp = head;
int position = 0;
bool found = false;
while (temp != nullptr) {
if (temp->data == key) {
cout << "Found " << key << " at position " << position << "." << endl;
found = true;
break;
}
temp = temp->next;
position++;
}
if (!found) {
cout << "Node with value " << key << " not found." << endl;
}
}
int main() {
Node* head = nullptr;
head = insertAtEnd(head, 10);
head = insertAtEnd(head, 20);
head = insertAtEnd(head, 30);
head = insertAtEnd(head, 40);
cout << "Current List: ";
displayList(head);
cout << "Searching for node with value 30..." << endl;
searchNode(head, 30);
return 0;
}