#include <stdio.h>
#define MAX 100000

void inputlist(int list[], int k) {
	int i;
	for (i=0;i<k;i++){
		scanf("%d", &list[i]);
	}
}

int MaxSubseqSum(int list[], int k) {
//运用在线处理的方法
	int i, sum = 0, max = 0;
	for (i=0;i<k;i++) {
		sum += list[i];
		if (sum > max) 
			max = sum;
		else if (sum < 0)
			sum = 0;
	}
	return max;
}

int main() {
	int list[MAX], k, i;
	scanf("%d", &k);
	inputlist(list, k);
	printf("%d", MaxSubseqSum(list, k));
	return 0;
}