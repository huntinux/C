#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 单链表的逆置
// from: 1->2->3->4
// to:   1<-2<-3<-4


struct node{
	int key;
	struct node *next;
};


void show_list(struct node *list)
{
	struct node *p;

	p = list;
	while(p){
		printf("%d ", p->key);
		p = p->next;
	}
	printf("\n");
}

struct node * create_list()
{
	struct node *list, *node, *p;
	int length, i;

	printf("Please input the length of the list:");
	scanf("%d", &length);
	if(length <= 0){
		printf("length must be bigger than 0");
		return NULL;
	}

	printf("Please input %d int key:\n", length);

	for(i = 0; i < length; i++) {
		// create node
		node = (struct node *)calloc(1, sizeof(struct node));
		scanf("%d", &(node->key));

		// insert the node into the list
		if(i == 0){
			list = node;
			p = list;
		}else{
			p->next = node;
			p = p->next;
		}
	}
	p->next = NULL;

	return list;
}

struct node * reverse_list(struct node *list)
{
	struct node *p, *q, *r;
	assert(list != NULL && list->next != NULL);

	q=list;
	p=r=NULL;

	while(q){
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	return p;
}


int main()
{
	struct node *l,*p;
	l = create_list();
	show_list(l);
	p = reverse_list(l);
	show_list(p);

	return 0;
}
