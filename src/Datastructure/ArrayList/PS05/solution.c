#include <stdio.h>

unsigned int getSum(unsigned int *ar, int len)
{
	unsigned int sum = 0; 	
	for(unsigned int i = 0; i < len; i++) {
		sum += ar[i]; 
	}

	return sum; 
}

unsigned int getMax(unsigned int *arr, unsigned int len) {
	unsigned int cmax = arr[0]; 

	for (unsigned int i = 1; i < len; i++) {
		if(arr[i] > cmax) {
			cmax = arr[i]; 
		}
	}

	return cmax; 
}

unsigned int getMin(unsigned int *ar, int len) {
	unsigned int cmin = ar[0]; 
	
	for (unsigned int i = 0; i < len; i++) {
		if(ar[i] < cmin) {
			cmin = ar[i]; 
		}	
	}

	return cmin; 
}



int findMissingNum(unsigned int *arr, int len)
{
	unsigned int sum = getSum(arr, len); 

	unsigned int cmax = getMax(arr, len); 
	unsigned int cmin = getMin(arr, len); 

	unsigned int expected_sum = (cmax * (cmax+1))/2 - (cmin * (cmin-1))/2; 

	unsigned int missing_num = expected_sum - sum; 

	return missing_num; 
	
}


int main()
{
	unsigned int ar[4] = {4, 7, 5, 8}; 
	unsigned int missing = findMissingNum(ar, 4); 

	printf("Missing Num: %d\n", missing); 

	return 0; 	
}
