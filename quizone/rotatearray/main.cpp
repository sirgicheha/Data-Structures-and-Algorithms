#include <iostream>

using namespace std;

#include <iostream>

void rotate(int nums[], int numsSize, int k) {
    if (numsSize <= 1 || k == 0) {
        return;
    }

    k %= numsSize;

    int temp[k];
    for (int i = 0; i < k; i++) {
        temp[i] = nums[numsSize - k + i];
    }

    for (int i = numsSize - 1; i >= k; i--) {
        nums[i] = nums[i - k];
    }

    for (int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, numsSize, k);

    for (int i = 0; i < numsSize; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
