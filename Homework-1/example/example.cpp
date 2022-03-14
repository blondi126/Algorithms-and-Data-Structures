#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#define MAX 70001
using namespace std;
int n, q, i, l, r, x;


struct gorod {
    int people, num;
    gorod(int people = 0, int num = 0) {
        this->people = people; 
        this->num = num;
    }
} a[MAX];

int f(gorod a, gorod b) {
    if (a.people == b.people) return a.num < b.num;
    return a.people < b.people;
}

int Query(int l, int r, int x) {
    int Left = lower_bound(a, a + n, gorod(x, l), f) - a;
    int Right = upper_bound(a, a + n, gorod(x, r), f) - a;
    return Left < Right;
}

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i].people), a[i].num = i + 1;
    sort(a, a + n, f);
    scanf("%d", &q);
    int P[70001];
    int bg = q-1;
    while (q--) {
        scanf("%d %d %d", &l, &r, &x);
        P[q] = Query(l, r, x);
    
    }
    for (int i = bg; i >= 0; i--) {
        printf("%d", P[i]);
   }
    return 0;
}