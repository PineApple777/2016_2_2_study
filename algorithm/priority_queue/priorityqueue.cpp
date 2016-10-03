// 2015005005_JungSunWook_508
#include <stdio.h>
#include <stdlib.h>
typedef struct heap_struct* Heap;
struct heap_struct {
	int ext_nums;
	int size;
	int* elements;
};

void max_heapify(Heap H, int n, int i){
	int lft,rgt,largest;
	int x;
	lft = 2*i;
	rgt = 2*i + 1;
	if(lft < n+1 && H->elements[lft] > H->elements[i]){
		largest = lft;
	}
	else
		largest = i;
	if(rgt < n+1 && H->elements[rgt] > H->elements[largest]){
		largest = rgt;
	}
	if(largest != i && lft <= n){
		x = H->elements[i];
		H->elements[i] = H->elements[largest];
		H->elements[largest] = x;
		max_heapify(H,n,largest);
	}

}

void build_max_heap (Heap H, int n){
	// build heap
	int cap = n;
	for (int i = cap/2; i > 0; i--)
	{
		max_heapify(H,n,i);
	}
}

Heap insert_heap(Heap H, int num){
	if (H == NULL){
		//printf("debug : you make heap!!");
		H = (Heap)malloc(sizeof(struct heap_struct));
		H -> size = 1;
		H -> ext_nums = 0;
		H -> elements = (int *)malloc(sizeof(int)*(H->size+1));
		H -> elements[1] = num; 
	}
	else{
		/* main point!! */
		// insert part
		H->size++;
		H->elements = (int *)realloc(H->elements,sizeof(int)*(H->size+1));
		H->elements[H->size] = num;
		// heap sort part
		build_max_heap(H,(H->size)-(H->ext_nums));
	}
	return H;
}

void extract_maxnum(Heap H){
	int p = 0;
	if(H != NULL && H->elements != NULL){
		// extract part
		p = H->elements[1];
		H->elements[1] = H->elements[(H->size)-(H->ext_nums)];
		H->elements[(H->size)-(H->ext_nums)] = p;
		H->ext_nums++;
		// heapsort part
		max_heapify(H,(H->size)-(H->ext_nums),1);

	}
}

void swap_numbers(Heap H, int N1, int N2){
	if(H != NULL && H->elements != NULL){
		// swap part
		H->elements[N1] = N2;
		// heapsort part
		build_max_heap(H,(H->size)-(H->ext_nums));
	}
}

void print_heap(Heap H){
	if (H != NULL && H->elements != NULL){
		// printing extracted numbers part
		int n = H->size - H->ext_nums;
		for (int i = H->size; i > n; i--)
		{
			/* code */
			printf("%d",H->elements[i]);
			if(i == n+1){
				printf("\n");
			}
			else
				printf(" ");
		}

		// printing heapsorted last numbers part
		for (int i = 1; i < n+1; i++)
		{
			/* code */
			printf("%d",H->elements[i]);
			if(i == n)
				printf("\n");
			else
				printf(" ");
		}
	}
}

int main (void){
	int mode;
	Heap H = NULL;
	while(1){
		scanf(" %d",&mode);
		if (mode == 0){
			print_heap(H);
			break;
		}
		else if (mode == 1){
			int num = 0;
			scanf(" %d",&num);
			H = insert_heap(H, num);
		}
		else if(mode == 2){
			extract_maxnum(H);
		}
		else if(mode == 3){
			int n1 = 0, n2 = 0;
			scanf(" %d %d",&n1,&n2);
			swap_numbers(H,n1,n2);
		}
	}
	return 0;
}