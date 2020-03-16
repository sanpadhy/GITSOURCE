#include<iostream>
using namespace std;
int arraySum(int arr[], int n) {
   int sum = 0;
   for (int i = 0; i < n; i++)
   sum += arr[i];
   return sum;
}
void getPair(int A[], int n, int B[], int m) {
   int sum_first = arraySum(A, n);
   int sum_second = arraySum(B, m);
   int newsum_first, newsum_second, first, second;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         newsum_first = sum_first - A[i] + B[j];
         newsum_second = sum_second - B[j] + A[i];
         if (newsum_first == newsum_second) {
            first = A[i];
            second = B[j];
         }
      }
   }
   cout << "(" << first << ", " << second << ")";
}
int main() {
   int A[] = { 4, 1, 2, 2, 1, 1 };
   int n = sizeof(A) / sizeof(A[0]);
   int B[] = { 3, 3, 6, 3 };
   int m = sizeof(B) / sizeof(B[0]);
   getPair(A, n, B, m);
}
