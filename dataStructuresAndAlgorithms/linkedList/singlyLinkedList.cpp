#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next;

    Node(char c) {
        this->data = c;
        this->next = nullptr;
    }
};

Node *pushFront(char c, Node *tail) {
    Node *newHead = new Node(c);
    newHead->next = tail;
    return newHead;
}

Node *pushRear(char c, Node *head) {
    Node *tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    // create new rear node
    Node *newRear = new Node(c);
    newRear->next = nullptr;
    // Link to the last node of current head
    tmp->next = newRear;
    return head;
}

Node *addAtIndex(char c, int index, Node *head) {
    int pindex = index - 1;
    Node *phead = head;
    while (pindex) {
        phead = phead->next;
        pindex--;
    }
    Node *newNode = new Node(c);
    newNode->next = phead->next;
    phead->next = newNode;
    return head;
}

int getLength(Node *head) {
    int count = 0;
    Node *tmp = head;
    while (tmp != nullptr) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void printList(Node *head) {
    Node *tmp = head;
    while(tmp) {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "END, Total list size: " << getLength(head) << endl;
}

void printListWithAddr(Node *head) {
    Node *tmp = head;
    cout << "\n=== DEBUG ===\n" << endl;
    while(tmp) {
        cout << tmp->data << " at: " << tmp << " next: " << tmp->next << endl;
        tmp = tmp->next;
    }
    cout << "END, Total list size: " << getLength(head) << endl;
}

Node *deleteFront(Node *head) {
    Node *tmp = head;
    if(tmp->next == nullptr) {
        delete head;
        head = nullptr;
        return head;
    }
    // update new head
    head = head->next;
    delete tmp;
    return head;
}

Node *deleteRear(Node *head) {
    Node *tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    delete tmp->next;
    tmp->next = nullptr;
    return head;
}

Node *deleteAtPosition(int index, Node *head) {
    int pindex = index - 1;
    Node *phead = head;
    while (pindex) {
        phead = phead->next;
        pindex--;
    }
    Node *dNode = phead->next;
    phead->next = phead->next->next;
    delete dNode;
    return head;
}

void deleteList(Node *head) {
    delete head;
    head = nullptr;
}

Node *reverseList(Node *head) {
    Node *curr = head, *prev = nullptr, *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}


int main(void) {
    Node *head = new Node('M');
    printList(head);
    head = pushFront('S', head);
    printList(head);
    head = pushRear('A', head);
    printList(head);
    head = addAtIndex('+', 1, head);
    printList(head);
    head = deleteAtPosition(1, head);
    printList(head);

    head = reverseList(head);
    printList(head);

    printListWithAddr(head);
    
    int a = 0, b = 1, c = 0;
    cout << a << b;
    for(int i = 0; i < 4; i++) {
        cout << (c = a + b);
        b = c;
        a = b;
    }
    cout << endl;

    return 0;
}
