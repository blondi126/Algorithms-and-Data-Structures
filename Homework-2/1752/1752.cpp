#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> tree[20001];
bool used[20001];

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int v, u;
    for (int i = 1; i < n ; i++) {
        scanf("%d %d", &v, &u);
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
	int s = 1; 
	queue <int> knots;
	knots.push(s);
	vector<bool> used(n);
	vector<int> d(n), p(n);
	used[s] = true;
	p[s] = -1;
	while (!knots.empty()) {
		int v = knots.front();
		knots.pop();
		for (size_t i = 0; i < tree[v].size(); ++i) {
			int to = tree[v][i];
			if (!used[to]) {
				used[to] = true;
				knots.push(to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
		}
	}


    return 0;
}