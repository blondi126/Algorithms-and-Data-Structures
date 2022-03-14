#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[901][8101];

int main()
{
    for (int i = 0; i <= 900; i++)
       for (int j = 0; j <= 8100; j++)
          dp[i][j] = -1;

    dp[0][0] = 0;

    for (int i = 1;i <= 900;++i) 
        for (int j = 1;j <= 8100;++j) 
            for (int d = 1;d <= 9;++d) {
                if (d > i) continue;
                if (d * d > j) continue;
                if (dp[i - d][j - d * d] == -1) continue;
                if (dp[i - d][j - d * d] <= 99)
                    if ((dp[i][j] == -1) || (dp[i][j] - dp[i - d][j - d * d] > 1)) dp[i][j] = 1 + dp[i - d][j - d * d];
            }
    
    int t;
    scanf("%d", &t);
    int s1, s2;
    for (int i = 0; i<t; i++) {
        scanf("%d %d", &s1, &s2);
        if ((s1 > 900) || (s2 > 8100) || (dp[s1][s2] == -1)) {
            printf("No solution");
            continue;
        }
        while ((s1 > 0) && (s2 > 0)) {
                for (int j = 1;j <= 9; j++) {
                    if (dp[s1][s2] == 1 + dp[s1 - j][s2 - j * j]) {
                        printf("%d",j);
                        s1 = s1 - j;
                        s2 = s2 - j * j; 
                        break;
                    }
                }
        }
        printf("\n");
    }
    return 0;
}