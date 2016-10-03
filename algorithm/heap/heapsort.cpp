// 2015005005_JungSunWook_508
#include <stdio.h>

void max_heapify(int* arr, int n, int i){
	int lft,rgt,largest;
	int x;
	lft = 2*i + 1;
	rgt = 2*i + 2;
	if(lft < n+1 && arr[lft] > arr[i]){
		largest = lft;
	}
	else
		largest = i;
	if(rgt < n+1 && arr[rgt] > arr[largest]){
		largest = rgt;
	}
	if(largest != i && lft <= n){
		x = arr[i];
		arr[i] = arr[largest];
		arr[largest] = x;
		max_heapify(arr,n,largest);
	}

}

void build_max_heap (int* arr, int n){
	// build heap
	int size = n;
	for (int i = size/2; i >= 0; i--)
	{
		max_heapify(arr,n,i);
	}
}

void heapsort(int* arr, int n,int k){
	build_max_heap(arr, n);
	for(int i = n; i > n-k; i--){
		int p = 0;
		p = arr[0];
		arr[0] = arr[i];
		arr[i] = p;
		printf("%d",arr[i]);
		if(i == n-k+1){
			printf("\n");
		}
		else
			printf(" ");
		max_heapify(arr,i-1,0);
	}
};

int main (void){
	int N,k;
	int list[100000];
	scanf("%d %d",&N,&k);
	for (int i = 0; i < N; i++)
		scanf("%d",&list[i]);
	// heap sorting
	heapsort(list,N-1,k);
	/*Extract heap sort numbers*/
	for (int i = 0; i < N-k; i++)
	{
		printf("%d",list[i]);
		if(i == N-k-1)
			printf("\n");
		else
			printf(" ");
	}

	return 0;
}