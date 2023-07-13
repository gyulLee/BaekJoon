//2156 recursion
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max = -1;

void wineTasting(int total, int next, int repeat, int* wine, int size, int** memo) {

	int t = total;

	if (next >= size) {
		if (total > max) max = total;
	}
	else {
		if (memo[next][repeat] != -1)
			if (total > max) max = total;
		if (repeat == 2) {
			memo[next][repeat] = t;
			wineTasting(t, next + 1, 0, wine, size, memo);
		}
		else {
			memo[next][repeat] = t;
			wineTasting(t, next + 1, 0, wine, size, memo);
			t += wine[next];
			memo[next][repeat] = t;
			wineTasting(t, next + 1, repeat + 1, wine, size, memo);
		}
	}
}


int main() {
	int i, j, n;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int** memo = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i < n + 1; i++)
		memo[i] = (int*)malloc(sizeof(int) * 3);

	for (i = 0; i < n + 1; i++)
		for (j = 0; j < 3; j++)
			memo[i][j] = -1;

	wineTasting(0, 0, 0, a, n, memo);
	printf("%d", max);

	//free
	free(a);
	for (i = 0; i < n + 1; i++)
		free(memo[i]);
	free(memo);
}