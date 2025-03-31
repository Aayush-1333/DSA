/**
 * `Binary Search` is much better search algorithm as compared to simple search.
 * It uses `divide and conquer` approach to split the array into two halves and tries to guess the element
 * based on the middle index element.
 * 
 * In case the middle index value is larger search in left subarray, else search in right one.
 * 
 * `Time Complexity` = O(n.logn)
 * `Space Complexity` = O(1)
 */
#include <iostream>
using namespace std;


/*
    Binary Search Algorithm

    Parameters:
        `arr`: int[] - input integer array
        `item`: int - element to search
        `size`: int - lemgth of the input array
    
    Returns:
        index of the element else returns -1.
*/
int binary_search(int arr[], int item, int size) {
    int low = 0;
    int high = size - 1;
    int mid, guess;

    while (low <= high) {
        mid = (low+high) / 2;
        guess = arr[mid];

        if (guess == item)
            return mid;
        else if (guess > item)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}


int main() {
    int my_nums[] = {1, 5, 7, 8, 12, 45};
    int arr_size = sizeof(my_nums) / sizeof(my_nums[0]);
    int input_num;

    printf("Enter number to find > ");
    scanf("%d", &input_num);
    printf("The number is at position: %d\n", binary_search(my_nums, input_num, arr_size));
}
