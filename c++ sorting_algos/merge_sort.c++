#include <iostream>
using namespace std;

// Merge function to merge two halves
void merge(int A[], int low, int high, int mid) {
    int i, j, k;
    int c[50]; // Temporary array to store merged results

    i = low;      // Starting index for the left subarray
    k = low;      // Starting index for the merged array
    j = mid + 1;  // Starting index for the right subarray

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            c[k] = A[i];
            k++;
            i++;
        } else {
            c[k] = A[j];
            k++;
            j++;
        }
    }

    // Copy remaining elements of the left subarray
    while (i <= mid) {
        c[k] = A[i];
        k++;
        i++;
    }

    // Copy remaining elements of the right subarray
    while (j <= high) {
        c[k] = A[j];
        k++;
        j++;
    }

    // Copy tray
    for (i = low; i < k; i++) {
        A[i] = c[i];
    }
}

// MergeSort function to sort the array
void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);     // Sort the left half
        mergeSort(A, mid + 1, high); // Sort the right half

        merge(A, low, high, mid);   // Merge the two halves
    }
}

int main() {
    int arrSize = 7;
    int A[7] = {38, 27, 43, 3, 9, 82, 10};

    int low = 0;
    int high = arrSize - 1;

    // Call mergeSort
    mergeSort(A, low, high);

    // Print the sorted array
    for (int i = 0; i < arrSize; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
