#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>

int main()
{
	int N;
	scanf("%d", &N);
	int k = sqrt(N);
	int min = 25;
	int var = N;
	while (k > 0) {
		int N = var;
		int k2 = k;
		int count = 0;
		while (N > 0) {
			N = N - k2*k2;
			k2 = sqrt(N);
			count++;
		}
		if (count < min) min = count;
		k--;
	}
	if (min == 25) min = 1;
	printf("%d",  min);
	return 0;
}