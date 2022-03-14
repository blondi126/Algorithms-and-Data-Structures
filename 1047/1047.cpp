#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
    int N;
    scanf("%d", &N);
    float a0, an_1;
    scanf("%f", &a0);
    scanf("%f", &an_1);
    float* c;
    c = (float*)malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        scanf("%f", &c[i]);
    }
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += ((N - i) * c[i]);
    }
    float a1 = (N * a0 + an_1 - 2 * sum) / (N + 1); //выведение формулы есть в тетради, писал вам в вк
    printf("%.2f", a1);
    return 0;
}
