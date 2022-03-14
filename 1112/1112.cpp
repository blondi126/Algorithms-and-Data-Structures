#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void Sort(int*, int*, int, int);

int main()
{
    int N;
    scanf("%d", &N);
    
    int* A, * B;
    A = (int*)malloc(N * sizeof(int));
    B = (int*)malloc(N * sizeof(int));
    int a, b;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) {
            A[i] = b;
            B[i] = a;
        }
        else {
            A[i] = a;
            B[i] = b;
        }
    }
    Sort(B, A, 0, N - 1);
    /* for (int i = 0; i < N; i++) {

        printf("%d", A[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d", B[i]);
    }  
    printf("\n"); */
    int P = N;
    if (P != 1) {
        for (int i = 0; i < (N-1); i++) {
            int gr = B[i];
            int j = i+1;
            while ((A[j] < gr)) {
                A[j] = 1000;
                P--;
                if (j < N - 1)j++;
            }
           
            i = j - 1;
            
        }
    }
    Sort(A, B, 0, N - 1);
    /* printf("\n");
    for (int i = 0; i < N; i++) {

        printf("%d", A[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d", B[i]);
    } */
    printf("%d", P);
    int i = 0;
    while ((A[i] <1000)&&(i<N)) {
        printf("\n%d %d", A[i], B[i]);
        i++;
    }
    
    free(A);
    free(B);
    return 0;
}

void Sort(int* num, int* num2, int left, int right)
{
    int pivot, pivot2; 
    int l_hold = left; 
    int r_hold = right; 
    pivot = num[left];
    pivot2 = num2[left];

    while (left < right)
    {
        while ((num[right] >= pivot) && (left < right))
            right--; 
        if (left != right) 
        {
            num[left] = num[right]; 
            num2[left] = num2[right];
            left++; 
        }
        while ((num[left] <= pivot) && (left < right))
            left++; 
        if (left != right) 
        {
            num[right] = num[left];
            num2[right] = num2[left];
            right--; 
        }
    }
    num[left] = pivot;
    num2[left] = pivot2;
    pivot = left;
    pivot2 = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) 
        Sort(num, num2, left, pivot - 1);
    if (right > pivot)
        Sort(num, num2, pivot + 1, right);
} 