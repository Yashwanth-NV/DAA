#include <iostream>
using namespace std;

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

    // Selection Sort logic
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the minimum element in remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap minimum element with first element of unsorted portion
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;  // Add newline at the end

    return 0;
}