#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int M;
    scanf("%d", &M);
    int N[25001];
    int g = 0;
    for (int i = 0;i < 25001;i++) {
        scanf("%d", &N[i]);
        if (N[i] == -1) {
            g = i;
            break;
        }
    }
    int max;
    int p = 0;
    for (int i = M; i <= g; i++) {
        max = N[p];
        for (int j = p+1; j < i; j++) {
            if (N[j] > max) max = N[j];
        }
        printf("%d\n", max);
        p++;
    }
    return 0;
}