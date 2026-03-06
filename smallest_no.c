#include <stdio.h>
int main() {
    int arr[100], n, i;
    int smallest, second_smallest;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if(n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }
    smallest = second_smallest = __INT_MAX__;
    for(i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if(arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }
    if(second_smallest == __INT_MAX__) {
        printf("No second smallest element found (all elements may be equal).\n");
    } else {
        printf("Second smallest element is: %d\n", second_smallest);
    }
    return 0;
}
