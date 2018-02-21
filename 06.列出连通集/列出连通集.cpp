#include <bits/stdc++.h>
#define MAX 9

using namespace std;

void DFS(int G[MAX][MAX], vector<int> &visited, int N, int s) {
	int i;
	visited[s] = 0;
	cout << s << " ";
	for (i=0;i<N;i++)
		if (G[s][i] && visited[i])
			DFS(G, visited, N, i);
}

void BFS(int G[MAX][MAX], vector<int> &visited, int N, int s) {
	int i, tmp;
	queue<int> sk;
	sk.push(s);
	visited[s] = 0;
	while (sk.size() > 0) {
		tmp = sk.front();
		sk.pop();
		cout << tmp << " ";
		for (i=0;i<N;i++)
			if (G[tmp][i] && visited[i]) { 
				sk.push(i);
				visited[i] = 0;
			} 
	}
}

void printDFS(int G[MAX][MAX], int N) {
	int i;
	vector<int> visited(N, 1);
	for (i=0;i<N;i++) {
		if (visited[i]) {
			cout << "{ ";
			DFS(G, visited, N, i);
			cout << "}" << endl;
		}
	}
}

void printBFS(int G[MAX][MAX], int N) {
	int i;
	vector<int> visited(N, 1);
	for (i=0;i<N;i++) {
		if (visited[i]) {
			cout << "{ ";
			BFS(G, visited, N, i);
			cout << "}" << endl;
		}
	}
}

int main() {
	int i, N, E, v1, v2;
	int G[MAX][MAX] = {0};
	cin >> N >> E;
	for (i=0;i<E;i++) {
		cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	printDFS(G, N);
	printBFS(G, N);
	return 0;
} 
