#include <bits/stdc++.h>

using namespace std;

int popwithreturn(priority_queue<int, vector<int>, greater<int> > &pq) {
	int i = pq.top();
	pq.pop();
	return i;
}

int wpl(priority_queue<int, vector<int>, greater<int> > &pq) {
	int i, sum = 0;
	while (pq.size() > 1) {
		i = popwithreturn(pq) + popwithreturn(pq);
		pq.push(i);
		sum += i;
	}
	return sum;
}

int checkprefix(int n, vector<string> &code) {
	int i, j, rp;
	rp = 1;
	sort(code.begin(), code.begin() + n);
	for (i=0;i<n && rp;i++)
		for (j=i+1;j<n && rp;j++)
			if (code[j].substr(0, code[i].size()) == code[i])
				rp = 0;	
	return rp;
}

int main() {
	int i, j, n, m, sum, WPL;
	char c;
	priority_queue<int, vector<int>, greater<int> > pq;
	vector<string> code(64);
	vector<int> list(64);
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> c >> list[i];
		pq.push(list[i]);
	}
	WPL = wpl(pq);
	cin >> m;
	for (i=0;i<m;i++) {
		sum = 0;
		code.clear();
		for (j=0;j<n;j++) {
			cin >> c >> code[j];
			sum += code[j].length() * list[j];
		}
		if (sum == WPL && checkprefix(n, code))
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	return 0;
}
