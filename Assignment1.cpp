/*Each Step of the bubble sort process for the array[5, 2, 8, 1, 3]:

1. Easy: Understanding Bubble Sort

   Step1. We compare adjacent elements, starting from the first pair.
   Comparing 5 and 2, we find that 5 is greater than 2, so we swap them to get [2, 5, 8, 1, 3]. 
   Now we compare 5 and 8, requiring no swap. 
   Now comparing 8 and 1, we find that 8 is greater than 1, after swapping to get [2, 5, 1, 8, 3].
   Now 8 and 3, we swap to get [2, 5, 1, 3, 8]. After Pass 1 the array becomes [2, 5, 1, 3, 8].

 Step 2, we repeat the process for the remaining unsorted elements. 
 Comparing 2 and 5, no swap is needed. However, comparing 5 and 1, we swap to get [2, 1, 5, 3, 8].
 Then, comparing 5 and 3, we swap again to get [2, 1, 3, 5, 8]. After Pass 2, the array becomes [2, 1, 3, 5, 8].

 Step 3: we compare 2 and 1, requiring a swap to get [1, 2, 3, 5, 8].
 After Pass 3, the array becomes [1, 2, 3, 5, 8].

So, in total the bubble sort algorithm performs 10 comparisons and 6 swaps to sort the given array
 */

/*
Tracing the bubble sort algorithm step by step for the unsorted array[7, 4, 2, 9, 1]:

2. Intermediate: Trace the Bubble Sort

Pass 1 :

    Start with the array[7, 4, 2, 9, 1].
    Compare adjacent elements :
Compare 7 and 4 : Since 7 > 4, swap them : [4, 7, 2, 9, 1] .
Compare 7 and 2 : Since 7 > 2, swap them : [4, 2, 7, 9, 1] .
Compare 7 and 9 : No swap needed.
Compare 9 and 1 : Since 9 > 1, swap them : [4, 2, 7, 1, 9] .
After Pass 1 : [4, 2, 7, 1, 9]

Pass 2 :

    Repeat the process for the remaining unsorted elements :
Compare 4 and 2 : Since 4 > 2, swap them : [2, 4, 7, 1, 9] .
Compare 4 and 7 : No swap needed.
Compare 7 and 1 : Since 7 > 1, swap them : [2, 4, 1, 7, 9] .
After Pass 2 : [2, 4, 1, 7, 9]

Pass 3 :

    Repeat the process :
Compare 2 and 4 : No swap needed.
Compare 4 and 1 : Since 4 > 1, swap them : [2, 1, 4, 7, 9] .
After Pass 3 : [2, 1, 4, 7, 9]

Pass 4 :

    Repeat the process :
Compare 2 and 1 : Since 2 > 1, swap them : [1, 2, 4, 7, 9] .
After Pass 4 : [1, 2, 4, 7, 9]

The sorted array is[1, 2, 4, 7, 9]

*/

/*
3. Intermediate: Code Implementation
*/
#include <iostream>
    using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = { 3, 6, 1, 8, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    cout << "Unsorted array:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    // Sort the array using bubble sort
    bubbleSort(arr, size);

    // Print the sorted array
    cout << "Sorted array:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}




/*
4. Advanced: Optimization Challenge

Optimization:
------------ -

The key idea is to keep track of whether any swaps are made in each pass.If no swaps are made in a pass, 
it means that the array is already sorted up to that point, and we can terminate the sorting process early.



#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    bool isSorted; // Flag to track if the array is already sorted
    for (int i = 0; i < size - 1; ++i) {
        isSorted = true; // Initialize isSorted to true at the beginning of each pass
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = false; // Set isSorted to false if a swap is made
            }
        }
        // If the array is already sorted up to this point, break out of the outer loop
        if (isSorted) {
            break;
        }
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    cout << "Unsorted array:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    // Sort the array using optimized bubble sort
    bubbleSort(arr, size);

    // Print the sorted array
    cout << "Sorted array:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}

*/



/*

5. Advanced: Comparison with Other Sorting Algorithms

Bubble Sort :

Advantages:
Simple implementation : Bubble sort is easy to understand and implement.
No additional space : It operates in - place, requiring only a constant amount of extra memory.

Disadvantages :
    Inefficiency : Bubble sort has poor time complexity, making it inefficient for large datasets, especially when compared to other sorting 
    algorithms like quicksort and mergesort.
    O(n ^ 2) time complexity : Bubble sort has a time complexity of O(n ^ 2) in the worst case, which can be prohibitive for large datasets.

    Scenarios for use:
        Bubble sort may be suitable for small datasets or situations where simplicity and ease of implementation are prioritized over efficiency.
            It can also be useful when dealing with nearly sorted arrays, as it performs well in such cases due to its adaptive nature.

            Quicksort :

            Advantages :
            Efficiency : Quicksort has excellent average - case time complexity of O(n log n) and performs well on large datasets.
            In - place sorting : It can be implemented to sort the array in - place, requiring only a logarithmic amount of additional memory.
            Adaptive : Quicksort adapts well to nearly sorted arrays and performs efficiently in practice.

            Disadvantages :
            Not stable : Quicksort is not stable, meaning it may change the relative order of equal elements.
            Worst - case time complexity : While its average - case time complexity is good, the worst - case time complexity of quicksort 
            can be O(n ^ 2), though this is rare with good pivot selection strategies.


            Scenarios for use:
                Quicksort is ideal for large datasets or situations where high performance is required.
                    It is commonly used in practice due to its efficiency and effectiveness in a wide range of scenarios.


                    Mergesort :

                    Advantages :
                    Stable : Mergesort is a stable sorting algorithm, meaning it preserves the relative order of equal elements.
                    Predictable performance : It has a consistent time complexity of O(n log n) regardless of the input data, making it suitable 
                    for scenarios where predictable performance is important.
                    Parallelizable : Mergesort can be easily parallelized, allowing for efficient sorting on multi - core or distributed systems.


                    Disadvantages :
                    Additional space : Mergesort requires additional memory proportional to the size of the input array, making it less suitable for
                    memory - constrained environments.
                    Scenarios for use :
                    Mergesort is well - suited for scenarios where stable sorting and consistent performance are required.
                    It is often used in external sorting applications, such as sorting large files that do not fit into memory.
*/
