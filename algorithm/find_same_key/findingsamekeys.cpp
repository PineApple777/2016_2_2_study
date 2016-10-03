//2015005005_JungSunWook_508
#include <stdio.h>
#include <stdlib.h>
int main (void){
	int N = 0,M = 0;
	int C_a[100000] = {};
	int C_b[100000] = {};
	int A[100000],B[100000];
	int result = 0;
	scanf("%d %d\n",&N,&M);
	for (int i = 0; i < N ; i++)
	{
		scanf(" %d",&A[i]);
		C_a[A[i]]++;
	}

	for (int i = 0; i < M; i++)
	{
		scanf(" %d",&B[i]);
		C_b[B[i]]++;
	}
	for (int i = 0; i < 100000; ++i)
	{
		if(C_a[i] > 0 && C_b[i] > 0){
			result++;
		}
	}
	printf("%d\n",result);
	return 0;
}