#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function to merge two sorted subarrays
void merge(vector<int> &arr, int left, int mid, int right, int &numComparisons, int &numMerges) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        // Counting comparisons
        numComparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Counting merges
    numMerges++;
}

// Recursive merge sort function
void mergeSort(vector<int> &arr, int left, int right, int &numComparisons, int &numMerges) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, numComparisons, numMerges);
        mergeSort(arr, mid + 1, right, numComparisons, numMerges);

        merge(arr, left, mid, right, numComparisons, numMerges);
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

    int numComparisons = 0, numMerges = 0;

    clock_t startTime = clock();
    mergeSort(arr, 0, n - 1, numComparisons, numMerges);
    clock_t endTime = clock();

    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\n";
    cout << "Number of comparisons: " << numComparisons << endl;
    cout << "Number of merges: " << numMerges << endl;
    cout << "Execution time: " << executionTime << " seconds" << endl;

    return 0;
}

