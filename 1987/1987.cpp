#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
//#include <stack>

int main()
{
    int N;
    scanf("%d", &N);
      long* A,* B;
    A = (long*)malloc(N * sizeof(long));
    B = (long*)malloc(N * sizeof(long));

    for (int i = 0; i < N; i++) {
        scanf("%ld %ld", &A[i], &B[i]);
       
    }
   
    int M;
    scanf("%d", &M);
 
    long C;
    //int* ans;
   // ans = (int*)malloc(M * sizeof(int));
    int p = 0;
    for (int i = 0; i < M; i++) {
        int ans=-1;
        scanf("%ld", &C);
  
        int j;
        int l = 1, k = 0;;
        for ( j=0; j < N; j++) {
            if (B[j] < C) continue;
            if (A[j] > C) break;
            if ((C >= A[j]) && (C <= B[j])) {
                ans = j+1;
              //  lenght = B[j] - A[j];
            }
        }
      
        printf("%d\n", ans);
    }
     
  //  for (int i = 0;i < M;i++) printf("%d\n", ans[i]);
    free(A);
    free(B);
    //free(ans);
   
    return 0;
}