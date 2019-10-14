#include "header.h"
char* intToStrint(int number) {
	if (number == 0) {
		char* str = (char*)malloc(2);
		str[0] = '0';
		str[1] = 0;
		return str;
	}
	char* str;
	int isNegative = 0;
	int num = number;
	int length = 0;
	while (num) {
		length++;
		num /= 10;

	}
	if (number < 0) {
		isNegative = 1;
		number = -number;
	}
	str = (char*)malloc(length + 1);
	int i = 0;
	while (number > 0) {
		int n = number % 10;
		str[i] = n + 48;
		i++;
		number /= 10;
	}
	str[i] = 0;
	
	i = 0;
	char* str2;
	if (isNegative) {
		str2 = (char*)malloc (length + 2);
		str2[i] = '-';
		i++;
	}
	else {
		str2 = (char*)malloc(length + 1);
	}
	for (int j = 0; j < length; j++) {
		str2[j + i] = str[length - 1 - j];
	}
	str2[length + i] = 0;
	free(str);
	return str2;
}