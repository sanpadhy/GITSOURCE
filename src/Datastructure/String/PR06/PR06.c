#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool CheckForUniqueChar(char *s) {
	if(strlen(s) > 128) {
		return false;
	}

	bool charSet[128] = {false}; 
	for (int i = 0; i < strlen(s); i++) {
		int c = s[i];
		if (charSet[c] == true) {
			return false; 
		}	

		charSet[c] = true;
	}

	return true;
}

int main() {
	char *s = "HJHGHJGHGHGGGG"; 
	printf("%d", CheckForUniqueChar(s)); 
	return 0; 
}
/*
boolean isUniqueChars(String str) {
int checker= 0;
for (int i= 0; i < str.length(); i++) {
int val= str.charAt(i) - 'a';
if ((checker & (1 << val)) > 0) {
return false;
}
checker I= (1 << val);
}
return true;
}
*/

