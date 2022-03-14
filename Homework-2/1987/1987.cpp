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
   // std::stack <long> a;
   // std::stack <long> b;
   // std::stack <long> b2;
    for (int i = 0; i < N; i++) {
        scanf("%ld %ld", &A[i], &B[i]);
       
    }
    /* long p1, p2;
    scanf("%ld %ld", &p1, &p2);
    int p3 = p1;
    a.push(p1);
    b2.push(p2);
    for (int i = 1; i < N; i++) {
        scanf("%ld %ld", &p1, &p2);
        a.push(p1);
        if (p1 == p3) {
            b2.push(p2);
            continue;
        }

        while (!b2.empty()) { b.push(b2.top());b2.pop(); }
        p3 = p1;
        b2.push(p2);
        // p3 = p1;
        // a.push(p1);
        // b.push(p2);
    }
    while (!b2.empty()) { b.push(b2.top());b2.pop(); } */
    int M;
    scanf("%d", &M);
    //int* C;
    //C = (int*)malloc(N * sizeof(int));
    //for (int i = 0; i < N; i++) printf("! %ld %ld !", A[i], B[i]);
   /* long* c;
    c = (long*)malloc(M * sizeof(long));
    for (int i = 0; i < M; i++) scanf("%ld", &c[i]);
    for (int i = M - 1; i >= 0; i--) {
        if (c[i] > b.top()) { printf("-1\n"); break; }
    } */
    long C;
    //int* ans;
   // ans = (int*)malloc(M * sizeof(int));
    int p = 0;
    for (int i = 0; i < M; i++) {
        int ans=-1;
        scanf("%ld", &C);
      //  if (C < A[0]) {
      //      ans = -1;
      //      continue;
      //  }
      //  long lenght = 1000000001;
       // printf("%ld ", lenght);
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
       // if (lenght == 1000000001) ans[i] = -1;
        printf("%d\n", ans);
    }
     
  //  for (int i = 0;i < M;i++) printf("%d\n", ans[i]);
    free(A);
    free(B);
    //free(ans);
   
    return 0;
}