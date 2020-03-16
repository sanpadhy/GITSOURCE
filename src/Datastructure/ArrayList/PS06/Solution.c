
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the starting and the 
// ending index of the sub-array with equal 
// number of alphabets and numeric digits 
void findSubArray(int arr[], int n) 
{ 
    int sum = 0; 
    int maxsize = -1, startindex; 
    for (int i = 0; i < n; i++) { 
  
        // If its an alphabet 
        if (isalpha(arr[i])) { 
            arr[i] = 0; 
        } 
  
        // Else its a number 
        else { 
            arr[i] = 1; 
        } 
    } 
  
    // Pick a starting point as i 
    for (int i = 0; i < n - 1; i++) { 
        sum = (arr[i] == 0) ? -1 : 1; 
  
        // Consider all sub-arrays starting from i 
        for (int j = i + 1; j < n; j++) { 
            (arr[j] == 0) ? (sum += -1) : (sum += 1); 
  
            // If this is a 0 sum sub-array then 
            // compare it with maximum size sub-array 
            // calculated so far 
            if (sum == 0 && maxsize < j - i + 1) { 
                maxsize = j - i + 1; 
                startindex = i; 
            } 
        } 
    } 
  
    // If no valid sub-array found 
    if (maxsize == -1) 
        cout << maxsize; 
    else
        cout << startindex << " " << (startindex + maxsize - 1); 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 'A', 'B', 'X', 4, 6, 'X', 'a' }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    findSubArray(arr, size); 
  
    return 0; 
} 

