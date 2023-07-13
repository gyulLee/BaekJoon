//2156
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* wine = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &wine[i]);

    int** memo = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i < n + 1; i++)
        memo[i] = (int*)malloc(sizeof(int) * 3);

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < 3; j++)
            memo[i][j] = 0;

    int max = 0;

    // iteration
    for (int i = 1; i <= n; i++) {
        memo[i][0] = max;
        memo[i][1] = memo[i - 1][0] + wine[i - 1];
        memo[i][2] = memo[i - 1][1] + wine[i - 1];

        if (memo[i][0] > max)
            max = memo[i][0];
        if (memo[i][1] > max)
            max = memo[i][1];
        if (memo[i][2] > max)
            max = memo[i][2];
    }

    printf("%d", max);

    // free
    free(wine);
    for (int i = 0; i < n + 1; i++)
        free(memo[i]);
    free(memo);

    return 0;
}