#include <iostream>

using namespace std;

#include <iostream>
#include <unordered_map>

int singleNumber(int arr[], int n) {
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (auto it = count.begin(); it != count.end(); it++) {
        if (it->second == 1) {
            return it->first;
        }
    }
    return -1;
}

int main() {
    int arr1[] = {2, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int single1 = singleNumber(arr1, n1);
    cout << "Single element in array 1 is: " << single1 << endl;

    int arr2[] = {4, 1, 2, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int single2 = singleNumber(arr2, n2);
    cout << "Single element in array 2 is: " << single2 << endl;

    return 0;
}
