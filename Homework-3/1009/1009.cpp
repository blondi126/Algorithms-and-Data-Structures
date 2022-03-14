#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int N,K;
    scanf("%d", &N);
    scanf("%d", &K);
    int right= K * (K - 1);
    int right_2 = K-1;
    int p = 3;
    while (p <= N) {
        int m = right_2;
        right_2 = right;
        right = (right + m) * (K - 1);
        p++;
    }
    printf("%d", right);
    return 0;
}