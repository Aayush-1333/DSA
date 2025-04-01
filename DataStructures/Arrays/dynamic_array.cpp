/**
 * Arrays are one of the most fundamental linear data structures. There are two types of arrays:
 *    1. Static Arrays
 *    2. Dynamic Arrays
 * 
 * In this code I have implemented `dynamic arrays` using `static arrays`.
 * 
 * Here are the time complexities:
 *    1. Access = O(1)
 *    2. Append = O(1)
 *    3. Add = O(n)
 *    4. Pop = O(1)
 *    5. Remove = O(n)
 *    6. Display = O(n)
 *    7. Linear Search = O(n)
 */
#include <iostream>


class DynamicArray {    
    private:
    int capacity;

    public:
    int size;
    int* A;

    DynamicArray() {
        size = 0;
        A = NULL;
        capacity = 20;
        initializeArray();
    }

    void initializeArray() {
        int* B = new int[capacity];

        // copy elements if original array is not empty
        if (size > 0) {
            for (int i = 0; i < size; i++)
                B[i] = A[i];
            delete[] A;
        }

        A = B;
    }

    void append(int x) {
        if (size == capacity) {
            capacity = 2 * capacity;
            initializeArray();
        } 
        A[size++] = x;
    }

    void add(int pos, int x) {
        if (pos < 0 || pos > size - 1) {
            printf("Invalid Index");
            return;
        }

        if (size == capacity) {
            capacity = 2 * capacity;
            initializeArray();
        }
        for (int i = size - 1; i >= pos; i--) 
            A[i+1] = A[i];
        A[pos] = x;
        ++size;
    }

    int pop() {
        if (size > 0) {
            int popped_elem = A[size-1];
            --size;
            return popped_elem;
        }
        return -1;
    }

    int remove(int pos) {
        if (pos >= 0 && pos <= size - 1) {
            int del_elem = A[pos];
            for (int i = pos; i < size - 1; i++) 
                A[i] = A[i+1];
            --size;
            return del_elem;
        }

        return -1;
    }

    void display() {
        // printf("\nLength = %d and Capacity = %d\n", size, capacity);
        printf("[ ");
        for (int i = 0; i < size; i++)
            printf("%d ", A[i]);
        printf("]\n");
    }

    int linear_search(int x) {
        for (int i = 0; i < size; i++) {
            if (A[i] == x)
                return i;
        }
        return -1;
    }
};


int main() {
    DynamicArray arr = DynamicArray();
    arr.append(12);
    arr.append(88);
    arr.append(78);
    arr.append(18);

    arr.display();

    arr.add(1, 90);
    arr.display();

    arr.add(3, 99);
    arr.display();

    printf("\nPopped element: %d\n", arr.pop());
    arr.display();

    printf("\nPopped element: %d\n", arr.remove(2));
    arr.display();
}
