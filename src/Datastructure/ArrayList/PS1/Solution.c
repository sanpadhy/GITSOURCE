
/*
Given two sorted arrays, find the number of elements in common. The arrays are the same length
and each has all distinct elements.

Brute Force Method: O(N**2)
Best Concievable Time: BSR -- O(N)

we can just throw everything in B into a hash table. This will take O ( N) time. Then, we just go
through A and look up each element in the hash table. This look up (or search) is 0(1), so our runtime is
O(N).


*/ 


