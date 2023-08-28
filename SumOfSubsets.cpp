#include <iostream>
#include <vector>
using namespace std;

void displaySubset(const vector<int>& subset) {
    cout << "{ ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << "}" << endl;
}

void findSubsets(const vector<int>& set, vector<int>& subset, int index, int targetSum, int currentSum) {
    if (currentSum == targetSum) {
        displaySubset(subset);
        return;
    }

    if (index == set.size() || currentSum > targetSum) {
        return;
    }

    subset.push_back(set[index]);
    findSubsets(set, subset, index + 1, targetSum, currentSum + set[index]);
    subset.pop_back();

    findSubsets(set, subset, index + 1, targetSum, currentSum);
}

int main() {
    vector<int> set = {1, 2, 5, 6, 8};
    int targetSum = 9;

    vector<int> subset;
    cout << "Subsets with sum " << targetSum << ":\n";
    findSubsets(set, subset, 0, targetSum, 0);

    return 0;
}
