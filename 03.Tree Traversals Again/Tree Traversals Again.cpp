#include <bits/stdc++.h>

using namespace std;

struct o
{
	string type;
	int data;
};

vector<o> operation(60);
vector<int> result;

void traversal(int i, int j) {
	if (i >= j)
		return;
	int depth = 1;
	int p = i;
	while (depth > 0) {
		p++;
		if (operation[p].type == "Pop")
			depth--;
		else 
			depth++;
	}
	traversal(i+1, p-1);
	traversal(p+1, j);
	result.push_back(operation[i].data);
}

int main() {
	int i, n;
	cin >> n;
	if (n == 0) {
		return 0;
	}
	for (i=0;i<n*2;i++) {
		cin >> operation[i].type;
		if (operation[i].type == "Push") 
			cin >> operation[i].data;
	}
	traversal(0, n*2-1);
	for (i=0;i<n-1;i++)
		cout << result[i] << " ";
	cout << result[n-1] << endl;
	return 0;
}