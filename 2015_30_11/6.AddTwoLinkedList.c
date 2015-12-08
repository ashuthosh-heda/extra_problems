#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node* next;
};

void insertAtStart(struct node** head, int num){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = *head;
	*head = newNode;
}

void insert(struct node** head, int num){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = num;
	temp->next = NULL;

	if (*head == NULL){
		*head = temp;
	}
	else{
		struct node* tempHead = *head;
		while (tempHead->next)
			tempHead = tempHead->next;

		tempHead->next = temp;
	}
}

void displayList(struct node* head){
	if (head == NULL){
		printf("Empty List\n\n");
		return;
	}

	while (head->next){
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("%d", head->data);
	printf("\n\n");
}

int lenOfList(struct node* list){
	int len = 0;
	while (list){
		list = list->next;
		len++;
	}
	return len;
}

struct node* addListsSameLen(struct node* l1, struct node* l2, int* c){
	if (l1 == NULL || l2 == NULL)
		return NULL;

	int sum;

	struct node* res = (struct node*)malloc(sizeof(struct node));

	res->next = addListsSameLen(l1->next, l2->next, c);

	sum = l1->data + l2->data + *c;
	*c = sum / 10;
	sum = sum % 10;

	res->data = sum;

	return res;
}

void addRemaining(struct node* l1, struct node* t, int* c, struct node* res){
	int sum;

	if (l1 != t){
		addRemaining(l1->next, t, c, res);

		sum = l1->data + *c;
		*c = sum / 10;
		sum = sum % 10;

		insertAtStart(&res, sum);
	}
}

struct node* addLists(struct node* list1, struct node* list2){
	if (list1 == NULL && list2 == NULL)
		return NULL;

	if (list1 == NULL)
		return list2;

	if (list2 == NULL)
		return list1;
	
	int len1 = lenOfList(list1);
	int len2 = lenOfList(list2);

	struct node* res = NULL;

	int c = 0;

	if (len1 == len2){
		res = addListsSameLen(list1, list2, &c);
	}

	else{
		int diff = len1 - len2;

		if (diff < 0){
			diff = -diff;
			struct node* temp = list1;
			list1 = list2;
			list2 = temp;
		}

		struct node* temp2 = list1;

		while (diff){
			temp2 = temp2->next;
			diff--;
		}

		res = addListsSameLen(temp2, list2, &c);

		addRemaining(list1, temp2, &c,res);
	}

	if (c != 0){
		insertAtStart(&res, c);
	}

	return res;
}

void main(){

	struct node* list1 = NULL;
	struct node* list2 = NULL;
	char choice;
	int data;

	printf("\tEnter First List\n");
	do{
		printf("\nDo you want to insert more(y/n): ");
		scanf("%c", &choice);

		if (choice != 'n'){
			printf("\nEnter a Number: ");
			scanf("%d", &data);
			getchar();
			insert(&list1, data);
		}
	} while (choice != 'n');

	getchar();
	printf("\n\n\tEnter Second List\n");
	do{
		printf("\nDo you want to insert more(y/n): ");
		scanf("%c", &choice);

		if (choice != 'n'){
			printf("\nEnter a Number: ");
			scanf("%d", &data);
			getchar();
			insert(&list2, data);
		}
	} while (choice != 'n');

	printf("List1 : ");
	displayList(list1);
	printf("List2 : ");
	displayList(list2);

	struct node* addedList = addLists(list1, list2);

	printf("Added List: ");
	displayList(addedList);

	getchar();
	getchar();
}