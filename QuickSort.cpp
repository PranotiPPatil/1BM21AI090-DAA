#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int> &arr, int low, int high, int &numComparisons, int &numSwaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        // Counting comparisons
        numComparisons++;
        if (arr[j] < pivot) {
            i++;
            // Counting swaps
            numSwaps++;
            swap(arr[i], arr[j]);
        }
    }

    // Counting swaps
    numSwaps++;
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive quicksort function
void quickSort(vector<int> &arr, int low, int high, int &numComparisons, int &numSwaps) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, numComparisons, numSwaps);

        quickSort(arr, low, pivotIndex - 1, numComparisons, numSwaps);
        quickSort(arr, pivotIndex + 1, high, numComparisons, numSwaps);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int numComparisons = 0, numSwaps = 0;

    clock_t startTime = clock();
    quickSort(arr, 0, n - 1, numComparisons, numSwaps);
    clock_t endTime = clock();

    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\n";
    cout << "Number of comparisons: " << numComparisons << endl;
    cout << "Number of swaps: " << numSwaps << endl;
    cout << "Execution time: " << executionTime << " seconds" << endl;

    return 0;
}

