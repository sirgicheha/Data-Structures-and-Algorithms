#include <iostream>

using namespace std;

#include <iostream>
#include <unordered_set>

bool containsDuplicates(int arr[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) != seen.end()) {
            return true;
        }
        seen.insert(arr[i]);
    }
    return false;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bool hasDuplicates1 = containsDuplicates(arr1, n1);
    cout << "Array 1 has duplicates: " << (hasDuplicates1 ? "true" : "false") << endl;

    int arr2[] = {1, 2, 3, 1, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bool hasDuplicates2 = containsDuplicates(arr2, n2);
    cout << "Array 2 has duplicates: " << (hasDuplicates2 ? "true" : "false") << endl;

    return 0;
}
