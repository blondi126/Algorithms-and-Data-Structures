#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stack>
#include <iostream>
//#include <vector>

int main()
{
    //std::vector <int> shar;
    //shar.push_back(0);
    //int shar[100000];
    //bool ans;
    std::stack <int> balls;
    int N;
    scanf("%d", &N);
    // int* M;
    // M = (int*)malloc(N * sizeof(int));
    if (N < 3) {
        //int c;
         //for (int i = 0; i < N; i++) {
         //    scanf("%d", &c);
        // }
        printf("Not a proof");
        return 0;
        //ans = false;
    }
    else {
        //int* num;
        //num = (int*)malloc(N * sizeof(int));
        int c;
        std::stack <int> balls;
        balls.push(0);
        int p=1;
        int check = -1;
       // int count = 1;
        for (int i = 0; i < N; i++) {
            
            //shar.push_back(c);
            scanf("%d", &c);
            // shar[p] = c;

            if (c > balls.top()) {
                
                
                //p++;
                //if (c == 1) continue; else {
                    for (int j = balls.top() + p; j < c; j++) {
                        // bool l = true;
                         //for (int k = 0; k < p; k++) { if (j == shar[k]) l = false; }
                        // for (int k = 0; k <= p; k++) {
                        //     if (j == shar[k]) { l = false;break; } 
                        // }
                        // if (l==true) balls.push(j);
                        balls.push(j);
                        //count++;
                    }
               // }
                    if ((c - check) == 1)p++; else p = 2;
                    check = c;
                //p++;
            }
            else if (balls.top() == c) {
                int ops = balls.top();
                balls.pop(); 
                p += (ops - balls.top());
                //count--;
            }
            else {
                printf("Cheater");
                return 0;
            }
            //else break;
            //p=1;

        // printf("%d\n", balls.top());
        }

        //if (balls.top() == 0) ans = false; else ans = true;
    }
    //free(num);
   // if (ans == true) printf("Cheater");
   // else 
  // if (!balls.empty()) {
  //      if (balls.top() == 0) printf("Not a proof");
  //      else printf("Cheater");
  // }
  //  else 
   // if(balls.top()==0) 
        printf("Not a proof"); 
   // else 
      //  printf("Cheater");
        return 0;
}