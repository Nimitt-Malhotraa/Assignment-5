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
int main() {
Node* head = nullptr;
insertAtEnd(head, 10);
insertAtEnd(head, 20);
cout << "Initial List: ";
displayList(head);
cout << "Inserting 30 at the end..." << endl;
insertAtEnd(head, 30);
cout << "Final List: ";
displayList(head);
return 0;
}