#include <iostream>
using namespace std;

// Linear Search: O(n)
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // return index
    }
    return -1; // not found
}

// Binary Search: O(log n) (works only on sorted arrays)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2; // middle element

        if (arr[mid] == key)
            return mid; // key found
        else if (arr[mid] < key)
            low = mid + 1; // search in right half
        else
            high = mid - 1; // search in left half
    }
    return -1; // not found
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    int indexLinear = linearSearch(arr, n, key);
    if (indexLinear != -1)
        cout << "Linear Search: Element found at index " << indexLinear << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    // Binary Search
    int indexBinary = binarySearch(arr, n, key);
    if (indexBinary != -1)
        cout << "Binary Search: Element found at index " << indexBinary << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    return 0;
}