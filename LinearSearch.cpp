#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N, target;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> numbers(N);
    cout << "Enter " << N << " elements:\n";
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    cout << "Enter the element to search for: ";
    cin >> target;

    int index = linearSearch(numbers, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
