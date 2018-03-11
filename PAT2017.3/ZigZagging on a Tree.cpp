#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int gettree(int tree[MAX][2], int m[], int b[], int mi, int mj, int i, int j) {
	if (i > j)
		return -1;
	if (i == j)
		return b[i];
	int k = 0;
	while(m[k + mi] != b[j]) 
		k++;
 	tree[b[j]][0] = gettree(tree, m, b, mi, mi + k - 1, i, i + k - 1);
	tree[b[j]][1] = gettree(tree, m, b, mi + k + 1, mj, i + k, j - 1);
	return b[j];
}

void printtree(int tree[MAX][2], int root) {
	stack<int> s;
	queue<int> st, q; 
	int tmp, rv = 1, last = root;
	st.push(root);
	while(st.size()) {
		tmp = st.front();
		st.pop();
		if (tree[tmp][0] != -1)
			st.push(tree[tmp][0]);
		if (tree[tmp][1] != -1)
			st.push(tree[tmp][1]);			
		if (rv)
			s.push(tmp);
		else
			q.push(tmp);
		if (tmp == last) {
			if (rv)
				while (s.size()) {
					q.push(s.top());
					s.pop();
				}
			last = st.back();
			rv = rv ? 0 : 1;
		}
	}
	while(q.size() > 1) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << q.front() << endl;
	
}

int main() {
	int N;
	cin >> N;
	int m[MAX], b[MAX], root;
	int tree[MAX][2];
	for (int i = 0; i < MAX; i++) {
		tree[i][0] = -1;
		tree[i][1] = -1;
	}
	for (int i = 0; i < N; i++)
		cin >> m[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];
	root = gettree(tree, m, b, 0, N - 1, 0, N - 1);
	printtree(tree, root);
	return 0;
}
