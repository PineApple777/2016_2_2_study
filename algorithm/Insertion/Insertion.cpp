//2015005005_JungSunWook_508
#include <stdio.h>
#include <iostream>

int main (void){
	long long int list[30000];
	long long int T = 0; // total repeat time
	int n = 0; // first while statement counter
	scanf("%lld",&T);
	//__fpurge(stdin);
	while (n < T){
		long long int num = 0; // new number we insert
		scanf("%lld",&num);
		//__fpurge(stdin);
		if (n == 0) list[0] = num; // check end point of list
		else{
			int y = 0; // second while statement counter
			int box = 0; // get old number when change some list number and number we will insert
			while( y <= n){
				if (y == n) list[y] = num;
				else{
					// sorting and insert
					if(list[y] > num){
						box = list[y];
						list[y] = num;
						num = box;
					}
				}
				y++;
			}
		}
		n++;
	}

	// print decreasing order
	while (T > 0){
		printf("%lld\n",list[T-1]);
		T--;
	}

	return 0;
}