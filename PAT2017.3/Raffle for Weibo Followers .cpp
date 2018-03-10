#include <bits/stdc++.h>

using namespace std;


int main() {
	int M, N, S;
	string s;
	map<string, int>p;
	int winner = 0;
	cin >> M >> N >> S;
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (p[s])
			S++;
		else if (i + 1  == S) {
			p[s] = 1;
			cout << s << endl;
			winner ++;
			S += N; 
		}
	} 
	if (!winner)
		cout << "Keep going..." << endl;
	return 0;
}
