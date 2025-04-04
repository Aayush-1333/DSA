#include <iostream>


void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int* selection_sort(int* arr, int size) {
    int smallest, smallest_index, tmp;

    for (int i = 0; i < size; i++) {
        smallest = arr[i];
        smallest_index = i;

        for (int j = i+1; j < size; j++) {
            if (arr[j] < smallest) {
                smallest = arr[j];
                smallest_index = j;
            }
        }
        // swap elements
        swap(&arr[i], &arr[smallest_index]);
    }

    return arr;
}

void display(int* arr, int size) {
    printf("\nArray:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int len;
    printf("Enter array size > ");
    scanf("%d", &len);

    int nums[len];
    printf("\nEnter elements:\n");
    for (int i = 0; i < len; i++)
        scanf("%d", &nums[i]);

    int* new_arr = selection_sort(nums, len);
    display(new_arr, len);
}
