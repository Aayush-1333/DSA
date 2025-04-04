#include <iostream>


class Queue {
    public:
    int front;
    int rear;
    int Q[10];

    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (front == 9)
            return;

        if (rear == -1 && front == -1)
            rear = 0;
        
        Q[++front] = x;
    }

    int dequeue() {
        if (front == -1)
            return -1;
        return Q[front--];
    }

    void display() {
        for (int i = front; i >= rear; i--)
            printf("%d ", Q[i]);
        printf("\n");
    }
};

int main() {
    Queue q = Queue();
    q.enqueue(10);
    q.enqueue(40);
    q.dequeue();
    q.display();
}
