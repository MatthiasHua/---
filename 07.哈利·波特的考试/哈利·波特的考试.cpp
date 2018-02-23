#include <bits/stdc++.h>
#define MAX 101
using namespace std;

void floyd(int N, int d[MAX][MAX]) {
	int i, j, k, mina = -1, min = 101, max = 0;
	for (k=1;k<=N;k++)
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
	for (i=1;i<=N;i++) {
		max = 0;
		for (j=1;j<=N;j++)
			if (d[i][j] > max)
				max = d[i][j];
		if (max < min) {
			min = max;
			mina = i;
		}
	}
	if (mina == -1)
		cout << 0 << endl;
	else 
		cout << mina << " " << min << endl;
}

int main() {
	int d[MAX][MAX];
	int i, j, N, M, a, b, c;
	cin >> N >> M;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			d[i][j] = 101;	
	for (i=1;i<=N;i++)
		d[i][i] = 0;
	for (i=0;i<M;i++) {
		cin >> a >> b >> c;
		d[a][b] = c;
		d[b][a] = c;
	}
	floyd(N, d);
	return 0;
}
