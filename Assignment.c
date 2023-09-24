#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp;
    temp = *a; *a = *b; *b = temp;
}

// Function to print an array of integers
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate and print all permutations of 1 to n
void generatePermutations(int n) {
    int arr[8]; // Assuming n <= 8, create an array to store permutations
    int indexes[8]; // An array to keep track of current index of each element
    
    // Initialize the array with 1 to n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        indexes[i] = 0; // Initialize indexes to 0
    }

    printArray(arr, n); // Print the initial permutation

    int i = 0;
    while (i < n) {
        if (indexes[i] < i) {
            if (i % 2 == 0) {
                swap(&arr[0], &arr[i]);
            } else {
                swap(&arr[indexes[i]], &arr[i]);
            }
            printArray(arr, n);
            indexes[i]++;
            i = 0;
        } else {
            indexes[i] = 0;
            i++;
        }
    }
}

int main() {
    int n;

    printf("Enter the number you want to permute ( number <= 8): ");
    scanf("%d", &n);

    if (n > 8 || n <= 0) {
        printf("Invalid input. Please enter a value between 1 and 8.\n");
        return 1;
    }

    generatePermutations(n);

    return 0;
}
