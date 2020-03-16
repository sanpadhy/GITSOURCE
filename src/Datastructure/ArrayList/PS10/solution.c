
// CPP program to find smallest length  
// subarray that contains all elements  
// of another array. 
#include <bits/stdc++.h> 
using namespace std; 
  
// function return the minimum length of sub_array 
int minimumSubArray(int A[], int n, int B[], int m) 
{ 
    int result = INT_MAX; 
  
    // Pick starting point 
    for (int i = 0; i < n; i++) { 
  
        // Pick ending point 
        for (int j = i; j < n; j++) { 
  
            // k is index in first array and 
            // 'index' is index in second array. 
            int k, index = 0;  
            for (k = i; k <= j; k++) { 
                if (A[k] == B[index]) 
                    index++; 
                if (index == m) 
                    break; 
            } 
  
            // update minimum length sub_array 
            if (index == m && result > k - i + 1) 
              result = (k == n) ? k - i : k - i + 1; 
        } 
    } 
  
    // return minimum length subarray 
    return result; 
} 
  
// driver program to test above function 
int main() 
{ 
    int A[] = { 5, 6, 5, 2, 7, 5, 6, 7, 5, 5, 7 }; 
    int B[] = { 5, 5, 7 }; 
    int n = sizeof(A)/sizeof(A[0]); 
    int m = sizeof(B)/sizeof(B[0]); 
    cout << minimumSubArray(A, n, B, m); 
    return 0; 
} 

