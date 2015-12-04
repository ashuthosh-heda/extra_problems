#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node* next;
};

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

//Iteration Approach
struct node* mergeLists1(struct node* head1, struct node* head2){
	if (head1 == NULL && head2 == NULL)
		return NULL;

	if (head1 == NULL)
		return head2;

	if (head2 == NULL)
		return head1;

	if (head1->data > head2->data){
		struct node* temp = head1;
		head1 = head2;
		head2 = temp;
	}

	struct node* res = head1;
	while (head1 && head2){
		while (head1->next && (head1->next->data <= head2->data))
			head1 = head1->next;

		struct node* temp = head1->next;
		head1->next = head2;
		head2 = temp;
	}
	return res;
}

//Recursion Approach
struct node* mergeLists2(struct node* head1, struct node* head2){
	struct node* res = NULL;

	if (head1 == NULL)
		return head2;

	if (head2 == NULL)
		return head1;

	if (head1->data <= head2->data){
		res = head1;
		res->next = mergeLists1(head1->next, head2);
	}
	else{
		res = head2;
		res->next = mergeLists1(head1, head2->next);
	}
	return res;
}

void main(){

	struct node* list1 = NULL;
	struct node* list2 = NULL;
	
	printf("Enter List1 in Non-Decreasing Order(Ascending Order)(-1 to stop)\n");
	int data;
	do{
		scanf("%d", &data);
		if (data != -1)
			insert(&list1, data);
	} while (data != -1);

	printf("Enter List2 in Non-Decreasing Order(Ascending Order)(-1 to stop)\n");
	do{
		scanf("%d", &data);
		if (data != -1)
			insert(&list2, data);
	} while (data != -1);

	printf("List1 : ");
	displayList(list1);
	printf("List2 : ");
	displayList(list2);

	struct node* merged = mergeLists1(list1, list2);
	//struct node* merged = mergeLists2(list1, list2);

	printf("Merged List: ");
	displayList(merged);

	printf("List1 : ");
	displayList(list1);
	printf("List2 : ");
	displayList(list2);

	getchar();
	getchar();
}