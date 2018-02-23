#include <bits/stdc++.h>
#define MAX 10001 

using namespace std;

void BFS(int &depth, int &count, int N, vector<vector<bool> > &E, vector<int> &visited, queue<int> &q, int &last) {
	int i;
	if (depth > 6 || !q.size())
		return ;
	int tmp = q.front();
	q.pop();
	count++;
	for (i=1;i<=N;i++)
		if (visited[i] && E[i][tmp]) {
			q.push(i);
			visited[i] = 0;
		}
	if (tmp == last) {
		last = q.back(); 
		depth++;
	}
	BFS(depth, count, N, E, visited, q, last);
} 

void cv(int i, int N, vector<vector<bool> > &E) {
	vector<int> visited(MAX, 1);
	queue<int> q;
	int depth = 0, count = 0, last = i;
	q.push(i);
	visited[last] = 0;
	BFS(depth, count, N, E, visited, q, last);
	printf("%d: %.2lf%c\n", i, (double)100 * count / N, '%');
} 

int main() {
	int i, M, N, a, b;
	vector<vector<bool> > E(MAX,vector<bool>(MAX,false));  
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> a >> b;
		E[a][b] = true;
		E[b][a] = true;
	}
	for (i=1;i<=N;i++)
		cv(i, N, E);
	return 0;
}
