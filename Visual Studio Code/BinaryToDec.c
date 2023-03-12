#include <stdio.h>

int binToDec(char str[]) {
	int num = 0;
	int n = 0;
	int k = 0;
	while (str[k] != '\0') {
		k += 1;
		n += 1;
	}

	for (int i = 0; i < n; i++) {
		int digit = (int)(str[i]) - (int)('0');
		int t = 1;
		for (int j = 0; j < n-i-1; j++) {
			t = t * 2;
		}
		num += digit * t;
	}
	
	return num;
}


int main() {
	char number[20];
	scanf("%s", number);
	int result = binToDec(number);
	printf("%d\n", result);


	return 0;
}








