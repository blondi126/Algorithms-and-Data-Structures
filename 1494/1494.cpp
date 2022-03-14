#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stack>
#include <iostream>

int main()
{
    std::stack <int> balls;
    int N;
    scanf("%d", &N);
 
    if (N < 3) {
       
        printf("Not a proof");
        return 0;
        //ans = false;
    }
    else {
      
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
                        balls.push(j);
                   
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
        
        }

    }
   
        printf("Not a proof"); 
 
        return 0;
}