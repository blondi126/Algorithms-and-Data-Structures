#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    long* lenght;
    lenght = (long*)malloc(N * sizeof(long));
    long long left = 1; long long right = 0;
    float c;
    for (int i = 0; i < N; i++) {
        scanf("%f", &c);
        lenght[i] = (long)(c * 100.0);
        if (lenght[i] > right) right = lenght[i];
        //right = right + lenght[i];
    }
    // for (int i = 0; i < N; i++) printf("%d ", lenght[i]);
    // right = floor(right * 100) / 100;
    // printf("%d, %d ", left, right);
    // right = right / K;
    long  middle = 0;
        while (left <= right) {
            //printf("l=%f, r=%f ", left, right);
            middle = (left + right) / 2;
            //printf("%d ", middle);
            //middle = floor(middle * 100) / 100;
            //printf("m=%d ", middle);
            long long sum = 0;
            for (int i = 0; i < N;i++) {
                sum = sum + (lenght[i] / middle);


                //printf("Sum=%d ", sum);
            }
            if (sum >= K) left = middle + 1;
            else if (sum < K) right = middle - 1;
        }
    // printf("%d ", right);
    //right = floor(right * 100) / 100;
    double otvet = (double)right / 100;
    printf("%.2f", otvet);
    free(lenght);
    return 0;
}
