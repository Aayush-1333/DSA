#include <iostream>


class Node {
    public:
    int data;
    Node* prevnode;
    Node* nextnode;
};


class DLL {
    public:
    Node* head;

    DLL() {
        head = nullptr;
    }

    int length() {
        int l = 0;
        Node* currnode = head;

        while(currnode != NULL) {
            ++l;
            currnode = currnode -> nextnode;
        }
        return l;
    }

    void append(int x) {
        Node* newnode = new Node;
        newnode -> data = x;
        newnode -> nextnode = nullptr;
        newnode -> prevnode = nullptr;

        if (head == NULL) {
            head = newnode;
            return;
        }

        Node* currnode = head;
        while(currnode -> nextnode != NULL)
            currnode = currnode -> nextnode;
        currnode -> nextnode = newnode;
        newnode -> prevnode = currnode;
    }

    void insert(int pos, int x) {
        Node* newnode = new Node;
        newnode -> data = x;

        Node* currnode = head;
        int size = length();
        if (pos == 0) {
            currnode -> prevnode = newnode;
            newnode -> nextnode = currnode;
            return;
        }

        else if (pos == size) {
            append(x);
            return;
        }

        int i = 0;
        while (i < pos) {
            currnode = currnode -> nextnode;
            ++i;
        }
        currnode -> prevnode -> nextnode = newnode;
        newnode -> prevnode = currnode -> prevnode;
        newnode -> nextnode = currnode;
    }

    int pop() {
        Node* currnode = head;
        Node* predecessornode = NULL;

        if (head == NULL)
            return -1;

        while (currnode -> nextnode != NULL) {
            predecessornode = currnode;
            currnode = currnode -> nextnode;
        }
        
        predecessornode -> nextnode = NULL;

        int element = currnode -> data;
        delete currnode;
        return element;
    }

    int remove(int pos) {
        int size = length();
        Node* currnode = head;
        Node* predecessornode = NULL;

        if (head == NULL || (pos < 0 || pos >= size))
            return -1;

        if (pos == 0)
            currnode -> nextnode -> prevnode = NULL;

        else if (pos == size - 1) {
            return pop();
        }

        int i = 0;
        while (i < pos) {
            predecessornode = currnode;
            currnode = currnode -> nextnode;
            ++i;
        }
        predecessornode -> nextnode = currnode -> nextnode;
        predecessornode -> prevnode = currnode -> prevnode;
        
        int element = currnode -> data;
        delete currnode;
        return element;
    }

    void display() {
        if (head == NULL) {
            printf("\nLinked List is empty!\n");
            return;
        }

        Node* currnode = head;
        printf("\n\nLinked List:\n");
        while(currnode -> nextnode != NULL) {
            printf("%d <--> ", currnode -> data);
            currnode = currnode -> nextnode;
        }
        printf("%d\n\n", currnode -> data);
    }
};


int main() {
    DLL ll = DLL();

    ll.append(34);
    ll.append(22);
    ll.insert(1, 29);
    ll.display();

    printf("Popped element: %d", ll.remove(1));
    ll.display();
}
