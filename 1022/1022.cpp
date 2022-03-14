#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[101];
bool colour[101];
vector <int> ans; 

void dfs(int);

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int p;
		while (true) {
			scanf("%d", &p);
			if (p == 0) break;
			tree[i].push_back(p);
		}
	}
	for (int i = 0; i < N; ++i) colour[i] = false;
	for (int i = 1; i <= N; ++i) if (!colour[i]) dfs(i);
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	return 0;
}

void dfs(int v) {
	colour[v] = true;
	for (size_t i = 0; i < tree[v].size(); ++i) {
		int to = tree[v][i];
		if (!colour[to])
			dfs(to);
	}
	ans.push_back(v);
}