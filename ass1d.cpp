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
Node* deleteFromBeginning(Node* head) {
if (head == nullptr) {
cout << "List is empty." << endl;
return nullptr;
}
Node* temp = head;
head = head->next;
delete temp;
return head;
}
int main() {
Node* head = nullptr;
head = insertAtEnd(head, 10);
head = insertAtEnd(head, 20);
head = insertAtEnd(head, 30);
cout << "Initial List: ";
displayList(head);
cout << "Deleting from the beginning..." << endl;
head = deleteFromBeginning(head);
cout << "Final List: ";
displayList(head);
return 0;
}