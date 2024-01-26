#include <iostream>
#include <limits>

using namespace std;
int summation(int arr[], int n) {
   int sum = 0;
   for (int i = 0; i < n; i++) {
       sum += arr[i];
   }
   return sum;
}

int maximum(int arr[], int n) {
   int max = numeric_limits<int>::min();
   for (int i = 0; i < n; i++) {
       if (arr[i] > max) {
           max = arr[i];
       }
   }
   return max;
}

int main() {
   cout << "Enter the length of the array (0 <= n <= ∞): ";
   int n;
   cin >> n;

   int arr[n];
   cout << "Enter the " << n << " integers of the array:" << endl;
   for (int i = 0; i < n; i++) {
       cin >> arr[i];
   }

   int sum = summation(arr, n);
   cout << "The sum of the integers in the array is: " << sum << endl;

   int max = maximum(arr, n);
   cout << "The maximum integer in the array is: " << max << endl;

   return 0;
}
