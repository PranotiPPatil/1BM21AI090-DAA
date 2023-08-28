#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int N, target;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> numbers(N);
    cout << "Enter " << N << " sorted elements:\n";
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    cout << "Enter the element to search for: ";
    cin >> target;

    int index = binarySearch(numbers, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
