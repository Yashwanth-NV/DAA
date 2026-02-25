#include <iostream>
using namespace std;

// Merge two subarrays
void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    // Compare and merge elements from left and right subarrays
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right subarray
    while (j <= high)
        temp[k++] = arr[j++];

    // Copy sorted elements back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

// Merge sort function - Divide and Conquer approach
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Sort left half
        mergeSort(arr, low, mid);
        // Sort right half
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int n, arr[100];

    cout << "Enter number of elements: ";
    cin >> n;
    
    // Validate input
    if (n <= 0 || n > 100) {
        cout << "Invalid input! Array size must be between 1 and 100." << endl;
        return 1;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;  // Add newline at the end

    return 0;
}
