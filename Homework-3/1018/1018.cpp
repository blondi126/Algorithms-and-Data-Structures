#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
    int N;
    scanf("%d", &N);
    long* A, * B;
    A = (long*)malloc(N * sizeof(long));
    B = (long*)malloc(N * sizeof(long));
    for (int i = 0; i < N; i++) {
        scanf("%ld %ld", &A[i], &B[i]);
    }
   
    int p = 0;
    for (int i = 0; i < M; i++) {
        int ans = -1;
        scanf("%ld", &C);
        int j;
        int l = 1, k = 0;;
        for (j = 0; j < N; j++) {
            if (B[j] < C) continue;
            if (A[j] > C) break;
            if ((C >= A[j]) && (C <= B[j])) {
                ans = j + 1;
            }
        }
        printf("%d\n", ans);
    }

    free(A);
    free(B);
    return 0;
}