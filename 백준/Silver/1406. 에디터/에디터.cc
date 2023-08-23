#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Dlist {
	struct Dlist* prev;
	struct Dlist* next;
	char value;
};

Dlist* head, * tail, * cur;
int size = 0;

void init() {
	head = (Dlist*)malloc(sizeof(Dlist));
	tail = (Dlist*)malloc(sizeof(Dlist));
	head->value = '\0';
	head->prev = NULL;
	head->next = tail;
	tail->value = '\0';
	tail->prev = head;
	tail->next = NULL;
	//커서: 현재 위치
	cur = (Dlist*)malloc(sizeof(Dlist));
	cur = tail->prev;
}

void insert(Dlist* head, char data) {
	Dlist* newNode = (Dlist*)malloc(sizeof(Dlist));
	newNode->next = head->next;
	newNode->prev = head;
	newNode->value = data;
	newNode->next->prev = newNode;
	head->next = newNode;
	size++;
	cur = newNode;
}
// a

void moveleft(Dlist* node) {
	//if (cur->prev != head) cur = cur->prev;
	if (node != head) cur = node->prev;
}

void moveright(Dlist* node) {
	if (node->next != tail) cur = node->next;
}

void eraseleft(Dlist* node) {
	if (node != head) {
		cur = node->prev;
		node->next->prev = node->prev;
		node->prev->next = node->next;
		//cur = node->prev;
	}
}
//a b(node) c

void print() {
	Dlist* tmp = (Dlist*)malloc(sizeof(Dlist));
	tmp = head->next;
	while (tmp != tail) {
		printf("%c", tmp->value);
		tmp = tmp->next;
	}
}

int main() {

	char str[100009];
	scanf("%s", str);
	init();
	for (int i = 0; str[i] != '\0'; i++) {
		insert(cur, str[i]);
	}

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char ord, tmp;
		scanf(" %c", &ord);
		switch (ord) {
		case'P': 
			scanf(" %c", &tmp);
			insert(cur, tmp);
			break;
		case 'L': 
			moveleft(cur);
			break;
		case 'D': 
			moveright(cur);
			break;
		case 'B': 
			eraseleft(cur);
			break;
		}
		
	}
	print();

	return 0;
}


