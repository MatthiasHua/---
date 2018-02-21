#include <bits/stdc++.h>

using namespace std;

struct p {
	int x, y;
};

double distant(p a, p b) {
	return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}

void BFS(queue<int> &q, int N, vector<int> &visited, vector<p> &G, double D) {
	if (!q.size()) {
		cout << "No" << endl;
		return; 
	}
	int fp = q.front(), i;
	if (50 - G[fp].x <= D || G[fp].x + 50 <= D || 50 - G[fp].y <= D || G[fp].y + 50 <= D) {
		cout << "Yes" << endl;
		return; 
	}
	//cout << G[fp].x << " " << G[fp].y << endl;
	q.pop();
	visited[fp] = 0;
	for (i=0;i<N;i++) {
		if (visited[i] && distant(G[fp], G[i]) <= D)
			q.push(i);
	}
	BFS(q, N, visited, G, D);
}

int main() {
	int i, N;
	double D;
	vector<p> G(100);
	vector<int> visited(100, 1);
	queue<int> q;
	cin >> N >> D;
	if (D > 50 - 7.5) {
		cout << "Yes" << endl;
		return 0;
	}
	for (i=0;i<N;i++) {
		cin >> G[i].x >> G[i].y;
		//cout << G[i].x << G[i].y << endl;
		if (distant((p){0, 0}, G[i]) <= 7.5 + D)
			q.push(i);	
	}
	BFS(q, N, visited, G, D);
	//for (i=0;i<q.size();i++) {
	//	cout << q.front() << " " << G[q.front()].x << endl; 
	//	q.pop();
	//}
	return 0;
}
