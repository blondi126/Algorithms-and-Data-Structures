#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
    int M;
    scanf("%d", &M);
    int A[5000];
    for (int i = 0; i < 5000; i++) A[i] = 0;
    int B[5000];
    int l, r;
    for (int i = 0;i < 99999;i++) {
        scanf("%d %d", &l, &r);
        if ((l == 0) && (r == 0)) break;
        if ((l >= M) || (r <= 0)) continue;
        if (l <= 0) {
            if (r > A[0]) {
                A[0] = r; 
                B[0] = l;
            }
        }
        else if (r > A[l]) {
            A[l] = r; 
            B[l] = l;
        }
    }
    
  // printf("%d ",A[0]);
  //  printf("%d ",A[1]);
  // printf("%d\n",A[2]);
  // printf("%d ", B[0]);
  // printf("%d ", B[1]);
  
    if (A[0]==0) { printf("No solution"); return 0; }
   
    for (int i = 1; i < M;i++) {
        if (A[i - 1] > A[i]) {
            A[i] = A[i - 1]; // printf("%d", A[i]);
            B[i] = B[i - 1];
        }
  
        if (A[i] == i) { printf("No solution"); return 0; }
    }
   // for (int i = 0; i < 5000; i++) { printf("%d ", A[i]); }
   // printf("%d ", A[0]);
   // printf("%d ", A[1]);
   // printf("%d\n", A[2]);
    int x = A[0], count = 1;
    int A2[5000], B2[5000];
    B2[0] = B[0]; A2[0] = x;
    while (x < M) {
        B2[count] = B[x];
        x = A[x];
        A2[count] = x;
      
        count++;
       
    }
    printf("%d\n", count);
    for (int i = 0; i < count;i++) printf("%d %d\n", B2[i], A2[i]);
    return 0;
}

