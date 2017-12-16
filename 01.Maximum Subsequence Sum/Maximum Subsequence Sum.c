#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct
{
	long max;
	int left;
	int right;
}MS, *PMS;

void inputlist(int list[], int k) {
	int i;
	for (i=0;i<k;i++){
		scanf("%d", &list[i]);
	}
}

PMS MaxSubseqSum(int list[], int k) {
//运用在线处理的方法
	int i, left = 0;
	long sum = 0;
	PMS m = (MS*)malloc(sizeof(MS));
	m->max = 0;
	m->left = list[0];
	m->right = list[k-1];
	for (i=0;i<k;i++) {
		sum += list[i];
		if (sum > m->max) {
			m->max = sum;
			m->left = list[left];
			m->right = list[i];
		}
		else if (sum < 0) {
			sum = 0;
			left = i + 1;
		}
		else if (list[i] == 0 && m->max == 0) {
			m->left = 0;
			m->right = 0;			
		}
	}
	return m;
}

int main() {
	int list[MAX], k, i;
	scanf("%d", &k);
	inputlist(list, k);
	PMS m = MaxSubseqSum(list, k);
	printf("%ld %d %d", m->max, m->left, m->right);
	return 0;
}