SUBJECTIVE
----------------------------

Array: 
	
	A Data structure with contiguous memory with elements of same type. 

Array --> 
	
	Static array 
        Dynamic array 

Array can be unidirection or multidimensional. 

	Array = [ a00  a01 a02 a03 
          	a10  a11 a12 a13   --------> memory layout [a00 a01 a02 a03 | a10 a11 a12 .... ]
          	a20  a21 a22 a23
         	a30  a31 a32 a33] 

	a[i][j] --> for(i = 0; i < ROWS; i++) {
			for(j = 0; j < COLUMNS; j++) {
			}
 	    	} 

ArrayList 
---------------------

	When you need an array-like data structure that offers dynamic resizing, you would usually use an Arraylist or 
	dynamic array.
	
	An Arraylist is an array that resizes itself as needed while still providing 0( 1) access. A typical implementa­
	tion is that when the array is full, the array doubles in size. Each doubling takes 0( n) time, but happens so
	rarely that its amortized insertion time is still O ( 1).

	inserting N elements takes O(N) work total. Each insertion is 0(1) on average, even though
	some insertions take O ( N) time in the worst case.


Inbuild functions: 
------------------------------

	abs() --> Absolute 

	isalpha(arr[i]) -- To check the variable is alphanumeric. 
	
	

PROGRAMS
-------------------------------

Q.1.
	
	Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference. Return the difference.

	EXAMPLE
	Input: {1, 3, 15, 11, 2}, {23, 127,235, 19, 8}
	Output: 3. That is, the pair (11, 8).

Time complexity: O(mlog(m) + nlog(n))

Q.2. 

	Sum Swap: Given two arrays of integers, find a pair of values (one value from each array) that you can swap to give the two arrays the same sum.

	EXAMPLE
	Input: {4, 1, 2, 1, 1, 2} and {3, 6, 3, 3}
	Output: {1, 3}

Q.3. 
	
	Design an algorithm to find all pairs of integers within an array which sum to a specified value.


Q.4. 

	Random Set: Write a method to randomly generate a set of m integers from an array of size n. Each element must have equal probability of being chosen.

Not done

Q.5. 
	
	Missing Number: An array A contains all the integers from O to n, except for one number which is missing. In this problem, we cannot access an entire integer in A with a single operation. The elements of A are represented in binary, and the only operation we can use to access them is "fetch the jth bit of A[ i ],"which takes constant time. Write code to find the missing integer. Can you do it inO(n) time?

####################################

Q.6 

	Given an array filled with letters and numbers, find the longest subarray with an equal number of letters and numbers.

Note: When need to find the subarray, have 
for (int i = 0; i < n - 1; i++) {
	for (int j = i + 1; j < n; j++) {

Q.10. 

	You are given two arrays, one shorter (with all distinct elements) and one longer. Find the shortest subarray in the longer array that contains all the elements in the shorter array. The items can appear in any order.

	EXAMPLE
	lnput:{1, 5, 9} & {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 10, 5, 8, 8, 9, 7}
	Output: [ 7, 10] (the underlined portion above)

	Example: 
	Input :  A[] = {2, 2, 4, 5, 8, 9}  
         B[] = {2, 5, 9}  
	Output : 5

	Smallest subarray of A[] that contains all elements of B[] is {2, 4, 5, 8, 9} which is of size 5.

	Input :  A[] = {5, 6, 5, 2, 7, 5, 6, 7, 5, 5, 7}  
        B[] = {5, 5, 7}  
	Output : 3

Q.14. 

	Print all sub-arrays with 0 sum.

042)

	Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such a subset cannot be made, then return null.

	Integers can appear more than once in the list. You may assume all numbers in the list are positive.

	For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.



####################################

Q.7

	Write a method to count the number of 2s that appear in all the numbers between O and n (inclusive).

	Example: 
	Input: 25
	Output: 9 (2, 12, 20, 21, 22, 23, 24 and 25. Note that 22 counts for two 2s.)

	Count the number of 2 can be done by dividing and taking the modulo of a number 
	
	num = 22     -->     num % 10 --> count = 1 
	                     num/10 --> num = 2 
			     num % 10 --> 2 count = 2

Q.8.

	The majority element is an element that makes up more than half of the items in an array. Given a positive integers array, find the majority element. If there is no majority element, return-1. Do this in O(N) time and 0(1) space.

Q.12. 

	C program to find maximum element in a matrix

Q.13. 

	Find the largest element in each row in a matrix. 

Q.16. 

	Third highest number in an array. 


####################################


Q.9.
	Design an algorithm to find the smallest K numbers in an array.

	When ever need to find the k smallest number, take k temporary variables or a separate stacks to maintain the minimum variables in a unsorted array. Time complexity for this would be O(n). 
	
	But I sort and get the smallest values, time complexity is much higher. O(n(logn)). 

Q.11.

	Missing Two: You are given an array with all the numbers from 1 to N appearing exactly once, except for one number that is missing. How can you find the missing number in O(N) time and 0(1) space? What if there were two numbers missing?


Try in Sorted and Unsorted matrix. 


Q.15. 

	Sort binary array in linear time.

Q.17. 

	Lighted bulbs problem in Zarando. 

Q.18.

	Dynamic Array Implementation. 

-------------------------------------

Daily Coding
-------------------------------------

01)

	Given a list of numbers, return whether any two sums to k. For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

	Bonus: Can you do this in one pass?

02) 
	
	    Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

	    For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

	    Follow-up: what if you can't use division?

04) 

         Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

	    For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

	    You can modify the input array in-place.

09)

	Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

	For example, [2, 4, 6, 8] should return 12, since we pick 4 and 8. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

018)

	Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

	For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

	10 = max(10, 5, 2)
	7 = max(5, 2, 7)
	8 = max(2, 7, 8)
	8 = max(7, 8, 7)

	Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.

040)
	
	Using Bit Vector

	Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

	For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

	Do this in $O(N)$ time and $O(1)$ space.


065) 
	
	Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

	For example, given the following matrix:

	[[1,  2,  3,  4,  5],
 	[6,  7,  8,  9,  10],
 	[11, 12, 13, 14, 15],
 	[16, 17, 18, 19, 20]]

	You should print out the following:

	1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12

069)

	Given a list of integers, return the largest product that can be made by multiplying any three integers.

	For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

	You can assume the list has at least three integers.

099)
	
	Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

	For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its 
	length: 4.

	Your algorithm should run in O(n) complexity.

102)
	
	Given a list of integers and a number K, return which contiguous elements of the list sum to K.

	For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4].

126) 

	Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 	     6, 1, 2]. Try solving this without creating a copy of the list. How many swap or move operations do you need?

140)
	
	Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, 	find the two elements that appear only once.

	For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.

	Follow-up: Can you do this in linear time and constant space?

144)

	Given an array of numbers and an index i, return the index of the nearest larger number of the number at index i, 	where distance is measured in array indices.

	For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

	If two distances to larger numbers are equal, then return any one of them. If the array at i doesn't have a nearest 	larger integer, then return null.

	Follow-up: If you can preprocess the array, can you do this in constant time?

150)

	Given a list of points, a central point, and an integer k, find the nearest k points from the central point.

	For example, given the list of points [(0, 0), (5, 4), (3, 1)], the central point (1, 2), and k = 2, return [(0, 0), 
	(3, 1)].

186)
	
	Given an array of positive integers, divide the array into two subsets such that the difference between the sum of 	the subsets is as small as possible.

	For example, given [5, 10, 15, 20, 25], return the sets {10, 25} and {5, 15, 20}, which has a difference of 5, which 
	is the smallest possible difference.


189)
Given an array of elements, return the length of the longest subarray where all its elements are distinct.

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].

190)
Given a circular array, compute its maximum subarray sum in O(n) time.

For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.

197) 
Given an array and a number k that's smaller than the length of the array, rotate the array to the right k elements in-place.

198) 
Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. Given [1, 3, 6, 24], return [1, 3, 6, 24].


203)
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. Find the minimum element in O(log N) time. You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.

243)
Given an array of numbers N and an integer k, your task is to split N into k partitions such that the maximum sum of any partition is minimized. Return this sum.

For example, given N = [5, 1, 2, 7, 3, 4] and k = 3, you should return 8, since the optimal partition is [5, 1, 2], [7], [3, 4].


245)
You are given an array of integers, where each element represents the maximum number of steps that can be jumped going forward from that element. Write a function to return the minimum number of jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.

251)
Given an array of a million integers between zero and a billion, out of order, how can you efficiently sort it? Assume that you cannot store an array of a billion elements in memory. 

339)
Given an array of numbers and a number k, determine if there are three entries in the array which add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49, return true as 20 + 4 + 25 = 49.

-------------------------




