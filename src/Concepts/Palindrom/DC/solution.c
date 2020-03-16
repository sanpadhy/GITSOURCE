#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrom(char *str) {
	int i, j; 
	for(i = 0, j = strlen(str)-1; i < j; i++, j--) {
		printf("%c, %c\n", str[i], str[j]); 
		if(tolower(str[i]) != tolower(str[j])) {
			return 0; 
		}
	}
	return 1; 
}

int main() {
	char *str = "Deleveled";
       	int result = 0;  	
	
	result = isPalindrom(str); 

	printf("%s", result? "true": "false"); 	
	
	return 0; 	
}
