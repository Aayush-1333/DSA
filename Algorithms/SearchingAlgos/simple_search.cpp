#include <iostream>


int simple_search(int A[], int size, int item) {
    for (int i = 0; i < size; i++) {
        if (A[i] == item)
            return i;
    }
    return -1;
}


int main() {
    int size;
    printf("Enter size > ");
    scanf("%d", &size);

    int nums[size];
    printf("Enter number of elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &nums[i]);
    
    int element;
    printf("Enter element > ");
    scanf("%d", &element);
    printf("\nElement is at index = %d\n", simple_search(nums, size, element));
}
