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
Node* insertAtBeginning(Node* head, int value) {
Node* newNode = new Node();
newNode->data = value;
newNode->next = head;
head = newNode;
return head;
}
int main() {
Node* head = nullptr;
head = insertAtBeginning(head, 20);
head = insertAtBeginning(head, 10);
cout << "Initial List: ";
displayList(head);
cout << "Inserting 5 at the beginning..." << endl;
head = insertAtBeginning(head, 5);
cout << "Final List: ";
displayList(head);
return 0;
}