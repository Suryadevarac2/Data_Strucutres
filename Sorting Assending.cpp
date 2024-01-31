#include <iostream> // Include the input/output stream library
using namespace std; // Using the standard namespace

int main() {
    int a[] = { 8, 7, 6, 5, 2, 4, 1, 3, 9 }; // Declare and initialize an array
    int getArrayLength = sizeof(a) / sizeof(int); // Calculate the length of the array
    
    // Bubble sort algorithm
    for (int i = 0; i < getArrayLength; i++) { // Loop through the array up to its length
        for (int j = 0; j < getArrayLength - 1; j++) { // Loop up to the last but one element
            if (a[j] > a[j + 1]) { // Compare adjacent elements
                // Swap elements if they are in the wrong order
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    // Printing the sorted array
    for (int i = 0; i < getArrayLength; i++) {
        cout << a[i]; // Print each element of the array
    }
}
