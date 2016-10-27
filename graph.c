#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct NODE node;

struct NODE{
	int id;
	int degree;
	node *next;
};


node* gen_base_graph(node* list[]){
	int i;
	int j;
	int a[]={0, 1, 2, 0, 1};
	node* new_node, *p;

	for (i = 0; i < 3; i++){
		list[i] = (node*)malloc(sizeof(node));             //TODO: malloc --> don't foret to free the memo
		if (list[i] == NULL){
				printf("Error: malloc failed. Not enough memory.");
				exit(EXIT_FAILURE);
			}
		list[i]->id = i;
		list[i]->degree = 2;
		list[i]->next = NULL;
	}

	for (i = 0; i < 3; i++){
		p=list[a[i]];
		for (j = 1; j <= 2; j++){
			new_node = (node*)malloc(sizeof(node));        //TODO: malloc --> don't foret to free the memo
			new_node->id = a[i+j];
			new_node->degree = 2;
			new_node->next=NULL;
			p->next = new_node;
			p=p->next;
		}
	}
	return *list;
}



void free_graph(node* list[], int n){
	node *p;
	int i;
	for (i=0; i<n; i++){
		while (list[i]){
			p = list[i];
			list[i]=list[i]->next;
			free(p);
		}
	}
}


int main(void){
	int N = 1000;
	node* list[N];
	int i;
	node* p;
	gen_base_graph(list);

	for (i=0; i<3; i++){
		for (p = list[i]; p; p=p->next)
			printf("%d\t", p->id);
		printf("\n");
	}

	free_graph(list, 3);

	return 0;
}
