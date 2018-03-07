#include <bits/stdc++.h>
#define min 500

using namespace std;

struct node {
	int d;
	int v;
};

int findMin(node dict[], int collection[], int N) {
	int mind = 501, minv = 501, mini;
	for (int i = 0; i < N; i ++)
		if (!collection[i] && (dict[i].d < mind || (dict[i].d == mind && dict[i].v < minv))) {
			mind = dict[i].d;
			minv = dict[i].v;
			mini = i;
			//cout << i << " " << collection[i] << endl;
		}
	return mini;
}

void dijkstra(node graph[min][min], int S, int D, int N) {
	int path[min];
	node dict[min];
	int collection[min] = {0};
	int tmp;
	for (int i = 0; i < N; i++) {
		path[i] = S;
		dict[i].d = graph[i][S].d;
		dict[i].v = graph[i][S].v;
	}
	collection[S] = 1;
	while (1) {
		tmp = findMin(dict, collection, N);
		collection[tmp] = 1;
		if (tmp == D) {
			cout << dict[tmp].d << " " << dict[tmp].v << endl;

			return;
		}
		for (int i = 0; i < N; i++) {
			if (!collection[i] && (dict[i].d > dict[tmp].d + graph[i][tmp].d || (dict[i].d == dict[tmp].d + graph[i][tmp].d && dict[i].v > dict[tmp].v + graph[i][tmp].v))) {
				dict[i].d = dict[tmp].d + graph[i][tmp].d;
				dict[i].v = dict[tmp].v + graph[i][tmp].v;
				path[i] = tmp;
			}
		}
	}
	
	
}

int main() {
	int N, M, S, D, c1, c2, d, v;
	cin >> N >> M >> S >> D;
	node graph[min][min];
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j++) {
			graph[i][j].d = 501;
			graph[i][j].v = 501;
		}
	for (int i = 0; i < M; i ++) {
		cin >>  c1 >> c2 >> d >> v;
		graph[c1][c2].d = d;
		graph[c1][c2].v = v;
		graph[c2][c1].d = d;
		graph[c2][c1].v = v;
	} 
	dijkstra(graph, S, D, N);
	return 0;
} 
