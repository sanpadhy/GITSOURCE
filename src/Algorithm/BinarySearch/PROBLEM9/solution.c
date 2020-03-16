/* 
 * Ternary Search divide the array into three parts for search operation. 
 * It has same time complexity wrt binary search but implementation wise more complex. 
 */


#include <stdio.h>

// Ternary search algorithm to return the position of
// target x in the array A of size N
int TernarySearch(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int left_mid = low + (high - low) / 3;
		int right_mid = high - (high - low) / 3;

		// int left_mid = (2*low + high)/3;
		// int right_mid = (low + 2*high)/3;

		if (arr[left_mid] == x)
			return left_mid;

		else if (arr[right_mid] == x)
			return right_mid;

		else if (arr[left_mid] > x)
			high = left_mid - 1;

		else if (arr[right_mid] < x)
			low = right_mid + 1;

		else
			low = left_mid + 1, high = right_mid - 1;
	}

	return -1;
}

// Ternary search algorithm
int main(void)
{
	int A[] = { 2, 5, 6, 8, 9, 10 };
	int target = 6;

	int n = sizeof(A) / sizeof(A[0]);
	int index = TernarySearch(A, n, target);

	if (index != -1)
		printf("Element found at index %d", index);
	else
		printf("Element not found in the array");

	return 0;
}
