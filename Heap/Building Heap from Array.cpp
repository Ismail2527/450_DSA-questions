#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to max-heapify a subtree rooted at index i
void maxHeapify(vector<int> &arr, int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max heap from an array
void buildMaxHeap(vector<int> &arr, int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node
    // and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to print the max heap as a tree
void printTree(const vector<int> &arr, int n) {
    int levels = log2(n) + 1; // Calculate the number of levels in the tree
    int index = 0;
    for (int i = 0; i < levels; i++) {
        // Number of elements at this level
        int levelElements = pow(2, i);
        // Calculate initial spaces for this level
        int initialSpaces = pow(2, levels - i - 1) - 1;
        cout << setw(initialSpaces * 2) << "";
        for (int j = 0; j < levelElements && index < n; j++) {
            cout << setw(4) << arr[index++];
            if (j < levelElements - 1) {
                cout << setw((pow(2, levels - i) - 1) * 2) << "";
            }
        }
        cout << endl;
    }
}

// Main function
int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    int n = arr.size();

    cout << "Original array:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    buildMaxHeap(arr, n);

    cout << "Max-Heap Tree Representation:" << endl;
    printTree(arr, n);

    return 0;
}
