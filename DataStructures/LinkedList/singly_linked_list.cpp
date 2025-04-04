/**
 * Linked List is another linear data structure which can be expanded or shrink easily using nodes which store data and address to next node object.
 * 
 * This code implements singly linked list which has only address to next node and is not circular (ends at last node).
 * 
 * We have only considered head pointer in `singly linked list`.
 * 
 * Time Complexities:
 *    1. Access = O(n)
 *    2. Display = O(n)
 *    3. Append = O(n)
 *    4. Add = O(n)
 *    5. Pop = O(n)
 *    6. Remove = O(n)
 */

#include <iostream>


class Node {
    public:
    int data;
    Node* nextnode;
};


class SLL {
    public:
    Node* head;

    SLL() {
        head = nullptr; 
    }

    int length() {
        int l = 0;
        Node* currnode = head;
        while (currnode != NULL) {
            currnode = currnode -> nextnode;
            ++l;
        }
        
        return l;
    }

    void append(int x) {
        Node* newnode = new Node;
        newnode -> data = x;
        
        if (head == NULL) {
            head = newnode;
            return;
        }

        Node* currnode = head;
        while(currnode -> nextnode != NULL)
            currnode = currnode -> nextnode;
        
        currnode -> nextnode = newnode;
    }

    void add(int pos, int x) {
        int size = length();
        if (pos < 0 || pos >= size) {
            printf("Invalid index");
            return;     
        }

        Node* newnode = new Node;
        newnode -> data = x;

        Node* currnode = head;

        if (pos == 0) {
            newnode -> nextnode = head;
            head = newnode;
            return;
        }

        else if (pos == size - 1) {
            append(x);
            return;
        }

        int i = 0;
        while (i < pos - 1) {
            currnode = currnode -> nextnode;
            ++i;
        }
        
        newnode -> nextnode = currnode -> nextnode; 
        currnode -> nextnode = newnode;
    }
    
    int pop() {
        Node* currnode = head;
        Node* prevnode = NULL;

        while (currnode -> nextnode != NULL) {
            prevnode = currnode;
            currnode = currnode -> nextnode;
        }
        
        int element = currnode -> data;
        delete currnode;
        prevnode -> nextnode = NULL;

        return element;
    }

    int remove(int pos) {
        int size = length();
        if (pos < 0 || pos >= size)
            return -1;
        
        Node* currnode = head;
        Node* prevnode = NULL;

        if (pos == 0) {
            head = currnode -> nextnode;
        }

        else if (pos == size - 1) {
            return pop();
        }

        else {
            int i = 0;
            while (i < pos) {
                prevnode = currnode;
                currnode = currnode -> nextnode;
                ++i;
            }
            prevnode -> nextnode = currnode -> nextnode;
        }
        
        int element = currnode -> data;
        delete currnode;
        return element;
    }

    void display() {
        Node* currnode = head;

        if (head == NULL) {
            printf("Linked List is empty!\n");
            return;
        }

        printf("Linked List:\n");
        while(currnode -> nextnode != NULL) {
            printf("%d -> ", currnode -> data);
            currnode = currnode -> nextnode;
        }
        printf("%d\n\n", currnode -> data);
    }
};


int main() {
    SLL ll = SLL();
    
    ll.append(78);
    ll.display();

    ll.append(145);
    ll.display();

    ll.append(90);
    ll.display();

    ll.add(0, 83);
    ll.display();

    printf("Popped element: %d\n\n", ll.pop());
    ll.display();

    printf("Popped element: %d\n\n", ll.remove(29));
    ll.display();
}
