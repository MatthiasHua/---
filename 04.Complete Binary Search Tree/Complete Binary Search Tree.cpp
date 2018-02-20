#include <bits/stdc++.h>

using namespace std;

void tolevel(int i, int &j, vector<int> &level, vector<int> tree, int n) {
	if (i <= n) {
		tolevel(2*i, j, level, tree, n);
		level[i] = tree[j];
		j++;
		tolevel(2*i+1, j, level, tree, n);
	}
}

int main() {
	int i, j = 0, n;
	vector<int> tree(1000), level(1000);
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> tree[i];
	}      
	sort(tree.begin(), tree.begin() + n);
	tolevel(1, j, level, tree, n);
	for (i=1;i<n;i++)
		cout << level[i] << " ";
	cout << level[n] << endl;
	return 0;
}