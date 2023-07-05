//19637  IF문 좀 대신 써줘

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bin_search_recursion(int key, int arr[], int low, int high) {
    int middle;

    if (low > high)
        return -1;

    middle = (low + high) / 2;
    int b = arr[middle - 1];
    if (middle == 0) b = -1;

    if (arr[middle]>=key && key>b)
        return middle;
    else if (arr[middle-1] >= key)
        return bin_search_recursion(key, arr, low, middle - 1);
    else
        return bin_search_recursion(key, arr, middle + 1, high);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char** levName = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
        levName[i] = (char*)malloc(sizeof(char) * 12);

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        char name[12] = { NULL };
        scanf("%s %d", name, &arr[i]);
        strcpy(levName[i], name); 
    }
    
    int* keys = (int*)malloc(sizeof(int) * m);
    char** outputs = (char**)malloc(sizeof(char*) * m);
    for (int i = 0; i < m; i++)
        outputs[i] = (char*)malloc(sizeof(char) * 12);

    for (int i = 0; i < m; i++) {
        scanf("%d", &keys[i]);
        if (n == 1)
            strcpy(outputs[i], levName[0]); // 이것 때문에 런타임 오류남
        else
            strcpy(outputs[i], levName[bin_search_recursion(keys[i], arr, 0, n - 1)]);
    }
    
    for (int i = 0; i < m; i++)
        printf("%s\n", outputs[i]);
    
    //free
    for (int i = 0; i < n; i++)
        free(levName[i]);
    free(levName);
    free(arr);
    for (int i = 0; i < m; i++)
        free(outputs[i]);
    free(outputs);
    free(keys);
    return 0;
}
