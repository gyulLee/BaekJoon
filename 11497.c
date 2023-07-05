//11497 통나무 건너뛰기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max = -1;

int countMax(int arr[], int size) {
    int m = -1;
    int sub, tmp;
    for (int i = 0; i < size - 1; i++) {
        tmp = arr[i + 1] - arr[i];
        sub = (tmp < 0) ? tmp * (-1) : tmp;
        if (sub > m) m = sub;
    }
    return m;
}

int partition(int* A, int s, int e) { // pivot을 기준으로 작은 수를 왼쪽, 큰 수를 오른쪽
    int i, j;
    int t;

    i = s - 1;
    for (j = s; j < e; j++) {
        if (A[j] < A[e]) { // A[e] : pivot
            i++; // i: pivot보다 작은 element의 개수를 알려주는 역할
            //A[i] <-> A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    //여기까지 i는 pivot보다 작은 숫자의 개수를 알려줌
    i++; // 여기서 하나 더하면 pivot이 갈 인덱스가 된다
    t = A[i];
    A[i] = A[e];
    A[e] = t;
    return i; // pivot이 결론적으로 위치한 인덱스 반환
}

void quickSort(int* A, int p, int r) {
    if (p < r) { // p랑 r이 같거나 p가 더 커지면 아무것도 하지 않는다.
        int q = partition(A, p, r); // pivot이 위치한 인덱스
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* r = (int*)malloc(sizeof(int) * n);
    int ri = 0;
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        int* A = (int*)malloc(sizeof(int) * m);
        int* A1 = (int*)malloc(sizeof(int) * (m / 2));
        int* A2 = (int*)malloc(sizeof(int) * (m / 2));
        for (int j = 0; j < m; j++)
            scanf("%d", &A[j]);
        if (m % 2 == 0) { // 짝수일때
            quickSort(A, 0, m - 1);
            int top = A[m - 1];
            int a = top - A[m - 2];
            int b = top - A[m - 3];
            if (a > max) max = a;
            if (b > max) max = b;

            int a1 = 0;
            int a2 = 0;
            A1[a1++] = A[0];
            A2[a2++] = A[0];
            for (int j = 1; j < m - 1; j++) {
                if (j % 2 == 0)
                    A1[a1++] = A[j];
                else
                    A2[a2++] = A[j];
            }
            a = countMax(A1, m / 2);
            b = countMax(A2, m / 2);
            if (a > max) max = a;
            if (b > max) max = b;
            //printf("%d", max);
            r[ri++] = max;
        }
        else { // 홀수일때
            quickSort(A, 0, m - 1);
            int top = A[m - 1];
            int a = top - A[m - 2];
            int b = top - A[m - 3];
            if (a > max) max = a;
            if (b > max) max = b;

            int a1 = 0;
            int a2 = 0;
            for (int j = 0; j < m - 1; j++) {
                if (j % 2 == 0)
                    A1[a1++] = A[j];
                else
                    A2[a2++] = A[j];
            }
            a = countMax(A1, m / 2);
            b = countMax(A2, m / 2);
            if (a > max) max = a;
            if (b > max) max = b;
            //printf("%d", max);
            r[ri++] = max;
        }

        max = -1;
        free(A);
        free(A1);
        free(A2);
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", r[i]);
    free(r);
}
