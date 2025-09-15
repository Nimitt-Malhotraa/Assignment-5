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
Node* deleteFromEnd(Node* head) {
if (head == nullptr) {
cout << "List is empty." << endl;
return nullptr;
}
if (head->next == nullptr) {
delete head;
return nullptr;
}
Node* temp = head;
while (temp->next->next != nullptr) {
temp = temp->next;
}
delete temp->next;
temp->next = nullptr;
return head;
}
int main() {
Node* head = nullptr;
head = insertAtEnd(head, 10);
head = insertAtEnd(head, 20);
head = insertAtEnd(head, 30);
cout << "Initial List: ";
displayList(head);
cout << "Deleting from the end..." << endl;
head = deleteFromEnd(head);
cout << "Final List: ";
displayList(head);
return 0;
}