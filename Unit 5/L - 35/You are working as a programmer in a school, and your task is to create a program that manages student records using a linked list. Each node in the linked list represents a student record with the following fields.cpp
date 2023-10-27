




#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* insertEnd(Node* head, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        return temp;
    }
    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void freeMemory(Node* &head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;
    int num;
    while (true) {
        cin >> num;
        if (num == -1) break;
        head = insertEnd(head, num);
    }
    
    printList(head);
    freeMemory(head);
    
    return 0;
}
