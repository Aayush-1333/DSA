#include <iostream>


class Stack {
    public:
    int top;
    int S[10];

    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 9) {
            printf("OVERFLOW!!");
            return;
        }
        S[++top] = x;
    }

    int pop() {
        if (top == -1)
            return -1;
        
        return S[top--];
    }

    int peek() {
        if (top == -1)
            return -1;
        return S[top];
    }

    void display() {
        if (top == -1) {
            printf("\nStack is empty!\n");
            return;
        }

        printf("\nStack:");
        for (int i = top; i >= 0; i--)
            printf("\n|%d|", S[i]);
        printf("\n");
    }
};


int main() {
    Stack s = Stack();
    s.push(12);
    s.push(45);
    s.push(459);
    s.display();

    printf("\nTop = %d\n", s.peek());

    printf("\nPopped elem = %d\n", s.pop());
    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.peek();

    s.display();
}
