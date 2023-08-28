#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
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

    cout << "Original array: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    clock_t start_time = clock();
    bubbleSort(numbers);
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
