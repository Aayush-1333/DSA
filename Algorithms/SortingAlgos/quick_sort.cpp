#include <iostream>


int* merge(int* A, int pivot, int* C, int sizeA, int sizeC) {
    int* mergedArray = new int[sizeA+1+sizeC];
    int i = 0, j = 0, k = 0;

    while (i < sizeA)
        mergedArray[k++] = A[i++];
    mergedArray[k++] = pivot;
    while (j < sizeC)
        mergedArray[k++] = C[j++];

    return mergedArray;
}

int* quick_sort(int* A, int size) {
    if (size < 2)
        return A;
    
    int pivot = A[0];
    int lesser_nums = 0, greater_nums = 0;

    // count number of elements lesser and greater than pivot respectively
    for (int i = 1; i < size; i++) {
        if (A[i] <= pivot)
            ++lesser_nums;
        else
            ++greater_nums;
    }

    // create two sub-arrays
    int less[lesser_nums];
    int greater[greater_nums];

    // store elements in the corresponding sub-arrays
    for (int i = 1, j = 0, k = 0; i < size; i++) {
        if (A[i] <= pivot)
            less[j++] = A[i];
        else
            greater[k++] = A[i];
    }

    // merge the sub-arrays along with the pivot
    return merge(
        quick_sort(less, lesser_nums), 
        pivot, 
        quick_sort(greater, greater_nums), 
        lesser_nums, 
        greater_nums
    );
}

void display(int* A, int size) {
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
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

    int* result = quick_sort(nums, len);
    display(result, len); 
}
