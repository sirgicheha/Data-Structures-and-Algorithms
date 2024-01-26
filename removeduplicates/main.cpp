#include <iostream>
#include <vector>

using namespace std;

#include <iostream>

int removeDuplicates(int nums[], int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int currentUniqueIndex = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[currentUniqueIndex]) {
            currentUniqueIndex++;
            nums[currentUniqueIndex] = nums[i];
        }
    }

    return currentUniqueIndex + 1;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 4, 5, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, numsSize);

    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
