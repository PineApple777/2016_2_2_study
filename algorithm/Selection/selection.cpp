#include <stdio.h>

int main (void){
	int T, M, list[30000];
	int x = 0, y = 0;
	scanf("%d %d",&T,&M);

	// getting number
	while(x < T){
		scanf("%d",&list[x]);
		x++;
	}
	// sorting
	for(y = 0; y < M ; y++){
		int min = y, p = y+1, chg = 0;
		while ( p < T ){
			if(list[min] > list[p]){
				min = p;
			}
			p++;
		}
		chg = list[y];
		list[y] = list[min];
		list[min] = chg;
	}

	// printing increasing order
	for(x = 0; x < T; x++){
		printf("%d\n",list[x]);
	}

	return 0;
}