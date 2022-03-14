#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>

bool check(int);

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        if (check(N)) {
            printf("%d\n", N);
            continue;
        }
        if (N % 2 == 0) {
            for (int j = 2; j <= (N / 2 + 1);j++) {
                if (check(j) && check(N - j)) { 
                    printf("%d %d\n", j, N - j);
                    break;
                }
            }
            continue;
        }
        else {
            int A = N - 2;
            if (check(A)) {
                printf("2 %d\n", A);
                continue;
            }
            N = N - 3;
            for (int j = 2; j <= (N / 2 + 1);j++) {
                if (check(j) && check(N - j)) {
                    printf("3 %d %d\n", j, N - j);
                    break;
                }
                continue;
            }
        }
    }
    return 0;
}

bool check(int N) {
    if (N < 3) return true;
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) return false;
    }
    return true;
}
