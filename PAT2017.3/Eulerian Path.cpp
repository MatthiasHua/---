#include <bits/stdc++.h>

using namespace std;

int find(int fl[], int i) {
	if (!fl[i])
		return i;
	fl[i] = find(fl, fl[i]);
	return fl[i];
}

int main() {
	int N, M, a, b, odd = 0, root;
	cin >> M >> N;
	int degree[505] = {0}, fl[505] = {0};
	queue<int> q;
	if (N == 0) {
		cout << 0 << endl;
		cout << "Eulerian" << endl;
		return 0; 
	} 
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		if (find(fl, a) != find(fl, b)) 
			fl[find(fl, a)] = find(fl, b);
	}
	root = find(fl, a);
	for (int i = 1; i <= M; i++) {
		if (degree[i] % 2 == 1)
			odd++;
		if (degree[i] > 0) {
			if (find(fl, i) != root)
			odd += 4; 
			q.push(degree[i]);			
		}
	}
	while(q.size() > 1) { 
		cout << q.front() << " ";
		q.pop();
	}
	cout << q.front() << endl;
	if (odd == 0)
		cout << "Eulerian" << endl;
	else if (odd == 2)
		cout << "Semi-Eulerian" << endl;
	else 
		cout << "Non-Eulerian" << endl;
	return 0;
}
