//11497 �볪�� �ǳʶٱ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max = -1;

int countMax(int arr[], int size) {
    int m = -1;
    int sub;
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        tmp = arr[i + 1] - arr[i];
        sub = (tmp < 0) ? tmp * (-1) : tmp;
        if (sub > m) m = sub;
    }
    return m;
}

int partition(int* A, int s, int e) { // pivot�� �������� ���� ���� ����, ū ���� ������
    int i, j;
    int t;

    i = s - 1;
    for (j = s; j < e; j++) {
        if (A[j] < A[e]) { // A[e] : pivot
            i++; // i: pivot���� ���� element�� ������ �˷��ִ� ����
            //A[i] <-> A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    //������� i�� pivot���� ���� ������ ������ �˷���
    i++; // ���⼭ �ϳ� ���ϸ� pivot�� �� �ε����� �ȴ�
    t = A[i];
    A[i] = A[e];
    A[e] = t;
    return i; // pivot�� ��������� ��ġ�� �ε��� ��ȯ
}

void quickSort(int* A, int p, int r) {
    if (p < r) { // p�� r�� ���ų� p�� �� Ŀ���� �ƹ��͵� ���� �ʴ´�.
        int q = partition(A, p, r); // pivot�� ��ġ�� �ε���
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
        if (m % 2 == 0) { // ¦���϶�
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
        else { // Ȧ���϶�
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