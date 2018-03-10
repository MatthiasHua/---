#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	int tmp;
	double f, s;
	priority_queue<double, vector<double>, greater<double> > q;
	cin >> N;
	for (int i; i < N; i++) {
		cin >> tmp;
		q.push((double) tmp);
	}
	while(q.size() > 1) {
		f = q.top();
		q.pop();
		s = q.top();
		q.pop();
		q.push((f + s) / 2);
	}
	cout << (int)q.top() << endl;
	return 0;
}
