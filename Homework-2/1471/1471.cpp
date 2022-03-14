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
    /* int n;
    scanf("%d", &n);
    vector<pair<int, int> > g[500001];
    int u, v, w;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(u, w));
        g[v].push_back(make_pair(u, w));
    }
    /* int* u, * v, * w;
    int * len;
    len = (int*)malloc((n) * sizeof(int));
    u = (int*)malloc(n * sizeof(int));
    v = (int*)malloc(n * sizeof(int));
    w = (int*)malloc(n * sizeof(int));
    std::stack <int> path;
    std::stack <int> lenght;
    path.push(0);
    lenght.push(0);
    int sum=0;
    len[0] = 0;
    //int p = 0;
     for (int i = 1; i < n; i++) {
        //lenght[i] = p;
        //if ((i == 0) || (i == 2) || (i == 6) || (i == 14) || (i == 30) || (i == 62) || (i == 126) || (i == 254) || (i == 510) || (i == 1022) || (i == 2046) || (i == 4094) || (i == 8190) || (i == 16382) || (i == 32766)) p++;
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        if (u[i] > v[i]) {
            while (path.top() != v[i]) { path.pop(); lenght.pop(); }
            path.push(u[i]);
            lenght.push(lenght.top()+w[i]);
            len[i] = lenght.top();
        }
        else {
            while (path.top() != u[i]) { path.pop(); lenght.pop(); }
            path.push(v[i]);
            lenght.push(lenght.top() + w[i]);
            len[i] = lenght.top();
        }
    }
    //lenght[n - 1] = p;
    int m;
    scanf("%d", &m); */
   // free(u);
    //free(v);
    //free(w);

    int n, u, v, w;
    scanf("%d", &n);
   // d= (int*)malloc(n * sizeof(int)+1);
    //f = (int*)malloc(n * sizeof(int)+1);
   // dist  = (int*)malloc(n * sizeof(int)+1);
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