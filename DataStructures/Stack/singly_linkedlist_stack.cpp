/**
 * Stack implementation using singly linked list.
 * 
 * Operations:
 *   1. Push = O(1)
 *   2. Pop = O(1)
 *   3. Peek = O(1) 
 */
#include <iostream>
using namespace std;


class Node {
    public:
    int data;
    Node* nextnode;
};


class Stack {
    private:
    Node* head;

    public:
    Stack() {
        head = nullptr;
    }

    void push(int x) {
        Node* newnode = new Node;
        newnode -> data = x;
        newnode -> nextnode = head;
        head = newnode;
    }

    int pop() {
        if (head != nullptr) {
            int element = head -> data;
            head = head -> nextnode;
            return element;
        }
        return -1;
    }

    int peek() {
        if (head != nullptr)
            return head -> data;
        return -1;
    }
};


int main() {
    Stack s = Stack();
    s.push(90);
    s.push(120);
    cout << "Top element: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element: " << s.peek() << endl;
}
