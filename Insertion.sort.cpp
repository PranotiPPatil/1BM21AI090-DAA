#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> numbers(N);
    cout << "Enter " << N << " elements:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    clock_t start_time = clock();
    insertionSort(numbers);
    clock_t end_time = clock();

    cout << "Sorted array: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Time taken: " << elapsed_time << " seconds" << endl;

    return 0;
}
