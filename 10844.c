//10844 쉬운 계단 수 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long m[10][100];

long long countNum(int i, int j) {
	if (m[i][j] != -1)
		return m[i][j];

	if (j == 0)
		return 1;

	if (i == 0) {
		if (m[i + 1][j - 1] == -1)
			m[i + 1][j - 1] = countNum(i + 1, j - 1) % 1000000000;
		return m[i + 1][j - 1];
	}
	else if (i == 9) {
		if (m[i - 1][j - 1] == -1)
			m[i - 1][j - 1] = countNum(i - 1, j - 1) % 1000000000;
		return m[i - 1][j - 1];
	}
	else {
		if (m[i + 1][j - 1] == -1)
			m[i + 1][j - 1] = countNum(i + 1, j - 1) % 1000000000;
		if (m[i - 1][j - 1] == -1)
			m[i - 1][j - 1] = countNum(i - 1, j - 1) % 1000000000;
		return m[i + 1][j - 1] + m[i - 1][j - 1];
	}
}


int main() {
	long long total = 0;
	int length = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 100; j++)
			m[i][j] = -1;

	scanf("%d", &length);
	for (int i = 1; i < 10; i++)
		total += countNum(i, length - 1);
	printf("%lld", total % 1000000000);
}