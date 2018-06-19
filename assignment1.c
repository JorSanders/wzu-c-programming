/*
 * Made by
 * Jor Gyo Sanders
 * Rakib Hassan
 * Odunlami Sunday Tunde
 */

#include <stdio.h>

void swap(int *, int *);

int findBiggest(int[], int);

int main() {

    int size = 5;
    int currentSize = size;
    int unsorted[size];
    int sorted[currentSize];

    // Request the numbers from the user
    printf("Please enter %d numbers.\n", size);
    for (int i = 0; i < currentSize; i++) {
        printf("input a number: \n");
        scanf("%d", &unsorted[i]);
    }

    // Loop through the array. Copy the biggest item to the sorted array
    while (currentSize >= 1) {
        int biggest = findBiggest(unsorted, currentSize);

        sorted[currentSize - 1] = unsorted[biggest];

        swap(&unsorted[currentSize - 1], &unsorted[biggest]);

        currentSize--;
    }

    // Print out the sorted array
    printf("\n");
    printf("Your values from small to large are:\n");

    for (int i = 0; i < size; i++) {
        printf("%d \n", sorted[i]);
    }

    int a = 5;
    getchar();

}

// Finds the biggest value of an array
// Param list the array
// Param size size of the array
// Returns index of the biggest number
int findBiggest(int *list, int size) {
    int biggest = 0;

    for (int i = 0; i < size - 2; i++) {

        if (list[i] < list[(i + 1)]) {
            biggest = i+1;
        }
    }

    return biggest;
}

// Swap the two values
// Param a int
// Param b int
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
