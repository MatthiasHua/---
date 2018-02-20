#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &heap, int tmp) {
	int i = heap.size();
	heap.push_back(tmp);
	while (heap[i/2] > heap[i]) {
		heap[i] = heap[i/2];
		heap[i/2] = tmp;
		i = i/2;
	}
}

int main() {
	int i, m, n, tmp;
	vector<int> heap;
	heap.push_back(-10001);
	cin >> m >> n;
	for (i=0;i<m;i++) {
		cin >> tmp;
		insert(heap, tmp);
	}
	for (i=1;i<=n;i++) {
		cin >> tmp;
		while (tmp > 1) {
			cout << heap[tmp] << " ";
			tmp /= 2;
		}
		cout << heap[1] << endl;
	}
}