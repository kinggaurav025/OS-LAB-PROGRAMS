#include <stdio.h>
int main() {
    int arr[100], n, i;
    int largest, second_largest;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    largest = second_largest = -__INT_MAX__;
    for(i = 0; i < n; i++) {
        if(arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if(arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    if(second_largest == -__INT_MAX__) {
        printf("No second largest element found (all elements may be equal).\n");
    } else {
        printf("Second largest element is: %d\n", second_largest);
    }
    return 0;
}
