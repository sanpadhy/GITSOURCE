
// C++ program to count 2s from 0 to n 
#include <bits/stdc++.h> 
using namespace std; 
  
// Counts the number of '2' 
// digits in a single number 
int number0f2s(int n) 
{ 
    int count = 0; 
    while (n > 0) 
    { 
        if (n % 10 == 2) 
            count++; 
  
        n = n / 10; 
    } 
    return count; 
} 
  
// Counts the number of '2'  
// digits between 0 and n  
int numberOf2sinRange(int n) 
{ 
    // Initialize result 
    int count = 0 ;  
  
    // Count 2's in every number 
    // from 2 to n 
    for (int i = 2; i <= n; i++) 
        count += number0f2s(i); 
  
    return count; 
} 
  
// Driver Code 
int main() 
{ 
    cout << numberOf2sinRange(22); 
    cout << endl; 
    cout << numberOf2sinRange(100); 
    return 0; 
} 

