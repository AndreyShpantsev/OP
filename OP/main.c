#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

typedef struct Node {
	int value;

	struct Node* next;
}l_list;

l_list* create_node(int data) {
	l_list* node = (l_list*)malloc(sizeof(l_list));
	node->value = data;
	node->next = NULL;
}

void push_front(l_list** list, int data) {
	l_list* newElement = create_node(data);
	l_list* tmp = list;
	newElement->next = *list;
	*list = newElement;
}

void push_back(l_list** list, int data) {
	l_list* newElement = create_node(data);

	l_list* tmp = *list;

	while (tmp->next != 0) {
		tmp = tmp->next;
	}
	
	tmp->next = newElement;
}

int GetSize(l_list** list) {
	l_list* tmp = *list;
	int count = 1;
	while (tmp->next != 0) {
		tmp = tmp->next;
		count++;
	}
	return count;
}

void push_center(l_list** list, int data, int len) {
	l_list* newElement = create_node(data);

	l_list* tmp = *list;
	int count = 0;

	while (count < len / 2 - 1 && tmp->next != 0) {
		tmp = tmp->next;
		count++;
	}

	newElement->next = tmp->next;
	tmp->next = newElement;
}

int main() {
	system("chcp 1251");
	l_list* list = create_node(1);
	int x[4];
	for (int i = 0; i < 4; i++) {
		printf("Введите элемент: ");
		scanf("%d", &x[i]);
	}
	push_front(&list, x[0]);
	push_back(&list, x[1]);
	push_back(&list, x[2]);
	push_center(&list, x[3], GetSize(&list));

	l_list* tmp = list;

	while (tmp != NULL) {
		printf("%d", tmp->value);
		tmp = tmp->next;
	}

	printf("\n%d", GetSize(&list));
	return 0;
}