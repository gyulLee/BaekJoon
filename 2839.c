//2839 º≥≈¡ πË¥ﬁ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int total = 0;

void countNum(int n) {
	if (n < 5 && n % 3 != 0)
		total = -1;
	else if (n % 5 == 0)
		total += n / 5;
	else {
		total++;
		countNum(n - 3);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	countNum(n);
	printf("%d", total);
}