#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//#include <stack>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > tree[50001];
int in[50001], out[50001], lenght[50001];
int up[50001][17];
int i, l, k, dfs_timer = 0;

void dfs(int, int, int);
int LCA(int, int);

int main()
{
   

    int n, u, v, w;
    scanf("%d", &n);
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }
    l = 1, k = 2;
    while (k <= n) {
        k = k * 2;
        l++;
    }
    dfs(0,0,0);
    int m;
    scanf("%d", &m);
    int lca, res;
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        lca = LCA(u, v);
        res = lenght[u] + lenght[v] - 2* lenght[lca];
        printf("%d\n", res);
    }
}

void dfs(int v,int p, int len) {
    int i, to;
    in[v] = dfs_timer++;
    up[v][0] = p; lenght[v] = len;
    for (i = 1; i <= l; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (i = 0; i < tree[v].size(); i++)
    {
        to = tree[v][i].first;
        if (to != p) dfs(to, v, len + tree[v][i].second);
    }
    out[v] = dfs_timer++;
}

int LCA(int a, int b) {
    if ((in[a] <= in[b]) && (out[a] >= out[b])) return a;
    if ((in[b] <= in[a]) && (out[b] >= out[a])) return b;
    for (int i = l; i >= 0; i--)
    if (!((in[up[a][i]] <= in[b]) && (out[up[a][i]] >= out[b]))) a = up[a][i];
    return up[a][0];
}