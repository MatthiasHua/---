#include <bits/stdc++.h>

using namespace std;

int find(int i, vector<int> &s) {
	if (s[i] < 0)
		return i;
	s[i] = find(s[i], s);
	return s[i];
}

void Union(int i, int j, vector<int> &s) {
	if (s[i] < s[j]) {
		s[i] += s[j];
		s[j] = i;
	}
	else {
		s[j] += s[i];
		s[i] = j;
	}
}

int main() {
	int n, i, j;
	char o;
	vector<int> s(10001, -1);
	cin >> n;
	while(1) {
		cin >> o;
		if (o == 'S')
			break;
		cin >> i >> j;
		i = find(i, s);
		j = find(j, s);
		if (o == 'I')
			Union(i, j, s);
		else if (i == j)
			cout << "yes" << endl;
		else 
			cout << "no" << endl;
	}
	j=0;
	for (i=1;i<=n;i++) 
		if (s[i] < 0)
			j++;
	if (j > 1)
		cout << "There are " << j << " components." << endl;
	else 
		cout << "The network is connected." << endl;
	return 0;
}