//2447 별찍기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void printArr(char** arr, int col, int row) {
	int i, j;
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
}

void printStar(int n, int colStart, int rowStart, char** arr, int arrSize) {
	if (n == 0)
		return;
	else {
		int tum = n / 3;
		for (int i = colStart + tum; i < colStart + tum * 2; i++)
			for (int j = rowStart + tum; j < rowStart + tum * 2; j++)
				arr[i][j] = ' ';

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				printStar(n / 3, colStart + i * tum, rowStart + j * tum, arr, arrSize);
	}
}


int main() {
	int n;
	scanf("%d", &n);
	char** A = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
		A[i] = (char*)malloc(sizeof(char) * n);


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = '*';
	printStar(n, 0, 0, A, n);
	printArr(A, n, n);

	//free
	for (int i = 0; i < n; i++)
		free(A[i]);
	free(A);
}
