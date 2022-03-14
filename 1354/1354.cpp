#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
    char word[10000];
    char p;
    int N = 0;
    while (true) {
        scanf("%c", &p);
        if (p == '\n') break;
        word[N] = p;
        N++;
    }
    //for (int i = 0; i < N; i++) printf("%c", word[i]);
    char* reverse;
    reverse = (char*)malloc(N * sizeof(char));
    bool ans = true;
    for (int i = 0; i < N; i++) {
        reverse[i] = word[N - 1 - i];
       // if (reverse[i] != word[i]) ans = false;
    }
   // for (int i = 0; i < N; i++) printf("%c", reverse[i]);

        //printf("search\n");
    int k = 1;
    if (k == N) {
        printf("%c%c", word[0], word[0]);
    }
        while (k<N) {
            char* palindrom;
            palindrom = (char*)malloc((N - k) * sizeof(char));
            ans = true;
            for (int i = k;i < N;i++) {
                palindrom[i - k] = word[N - 1 - (i-k)];
                if (palindrom[i-k] != word[i]) ans = false;
                //if (!ans) break;
            }
            //for (int i = 0;i < N - k; i++) printf("%c", palindrom[i]);
           // printf("\n");
            if (ans) {
               // printf("\n");
               //for (int i = 0;i < N - k; i++) printf("%c", palindrom[i]);
                bool l = false;
                if (N - k == 1) l = true;
                for (int i = 0; i < N; i++) {
                    if (palindrom[0] == reverse[i]) {
                        for (int j = 1; j < N - k;j++) {
                            if (palindrom[j] == reverse[i + j])
                                l = true;
                            else l = false;
                        }
                        if (l) {
                            //printf("\n");
                            for (int j = 0;j < N;j++) printf("%c", word[j]);
                            for (int j = i + N - k ;j < N;j++) printf("%c", reverse[j]);\
                                return 0;
                        }
                    }
                }
                return 0;
            }
            k++;
            free(palindrom);
        }
}