/*
	双向链表的一些函数
 */
#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *next;
	struct node *prev;
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

// 通过key删除节点
void remove_node(struct node *list, int key)
{
	struct node *p;

	p = list;

	while(p){
		if(p->key == key){
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
			break;
		}else{
			p = p->next;
		}
	}

}


struct node *create_list()
{
	struct node *list, *node, *tail;
	int length, i;

	printf("input length:");
	scanf("%d", &length);
	printf("input %d key:", length);
	for (i = 0; i < length; i++) {
		node = (struct node*)calloc(1, sizeof(struct node));
		scanf("%d", &(node->key));
		node->next = NULL;
		node->prev = NULL;

		if(i == 0){
			list = node;
			tail = node;
		}else{
			node->prev = tail;
			tail->next = node;
			tail = tail->next;
		}
	}

	return list;
}

int main()
{
	struct node* l;
	l = create_list();
	show_list(l);
	remove_node(l, 2);
	show_list(l);
	return 0;
}
