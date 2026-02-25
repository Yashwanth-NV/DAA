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

    // Insertion Sort logic
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Element to be inserted
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at correct position
        arr[j + 1] = key;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;  // Add newline at the end

    return 0;
}
