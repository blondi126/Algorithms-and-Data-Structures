#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
    char word[5000];
    char p;
    int N = 0;
    while (true) {
        scanf("%c", &p);
        if (p == '\n') break;
        word[N] = p;
        N++;
    }
    int k = 1;
    int count = 0;
    while (k <= N) {
        char* ex;
        ex = (char*)malloc(k * sizeof(char));
        char** A;
        A = (char**)malloc((N - k + 1) * sizeof(char*));
        for (int i = 0; i < N - k + 1;i++) {
            A[i] = (char*)malloc(k * sizeof(char));
            for (int j = 0; j < k; j++) A[i][j] = word[i + j];
        }
        for (int i = 0; i < N - k + 1;i++) {
            //  printf("\n");
            for (int j = 0; j < k; j++) {
                ex[j] = A[i][j];
                //  printf("%c", ex[j]);
            }
            bool ans = false;
            for (int j = 0; j < i;j++) {
                ans = false;
                for (int p = 0; p < k; p++) {
                    if (ex[p] == A[j][p]) ans = true;
                    else { ans = false; break; }
                }
                if (ans) break;
            }
            if (!ans) count++;
        }
        k++;
        free(ex);
        for (int i = 0; i < N - k + 1;i++) free(A[i]);
        free(A);
    }
    printf("%d", count);
    return 0;
}