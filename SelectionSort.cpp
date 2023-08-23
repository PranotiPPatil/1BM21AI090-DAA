#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function to perform selection sort
void selectionSort(vector<int> &arr, int &numComparisons, int &numSwaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            // Counting comparisons
            numComparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            // Counting swaps
            numSwaps++;
            swap(arr[i], arr[minIndex]);
        }
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
    selectionSort(arr, numComparisons, numSwaps);
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

