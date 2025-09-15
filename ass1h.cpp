#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
};
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
void displayList(Node* head) {
if (head == nullptr) {
cout << "List is empty." << endl;
return;
}
Node* temp = head;
cout << "Displaying all nodes: ";
while (temp != nullptr) {
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL" << endl;
}
int main() {
Node* head = nullptr;
head = insertAtEnd(head, 10);
head = insertAtEnd(head, 20);
head = insertAtEnd(head, 30);
displayList(head);
return 0;
}