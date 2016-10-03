// 2015005005_JungSunWook_508
#include <stdio.h>
void merge(int* list,int fnt ,int pnt,int bak);

void merge_sort(int* list ,int fnt,int bak){
	int x;
	if(fnt < bak){
		x = (fnt + bak)/2;
		//printf("debug : %d\n",x);
		merge_sort(list,fnt,x);
		merge_sort(list,x+1,bak);
		merge(list,fnt,x,bak);
	}
}

void merge(int* list,int fnt ,int pnt,int bak){
	int x = fnt,store = 0;
	int result[100000];
	if( fnt == pnt ){
		if (list[fnt] > list[bak]){
			store = list[fnt];
			list[fnt] = list[bak];
			list[bak] = store;
		}
	}else{
		int pnt_2 = pnt+1;
		int cnt = fnt;
		while(cnt <= bak){
			if (fnt > pnt){
				result[cnt] = list[pnt_2];
				pnt_2++;
			}
			else if(pnt_2 > bak){
				result[cnt] = list[fnt];
				fnt++;
			}
			else{
				if(list[fnt] > list[pnt_2]){
					result[cnt] = list[pnt_2];
					pnt_2++;
				}else{
					result[cnt] = list[fnt];
					fnt++;
				}	
			}
			cnt++;
		}
		while( x <= bak ){
			
			list[x] = result[x];
			x++;
		}
	}
}

int main (){
	int T, list[100000];
	int n = 0;
	scanf("%d",&T);

	// getting numbers
	for (n = 0; n < T; n++)	
		scanf("%d",&list[n]);
	// dividing, merging and sorting
	merge_sort(list, 0, T-1);
	// printing
	for (n = T; n > 0; n--)	
		printf("%d\n",list[n-1]);
	return 0;
}