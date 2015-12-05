#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node* next;
};

//Function to insert node at the start of the linked list
void insert(struct node** head, int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL)
		*head = newNode;
	else{
		newNode->next = *head;
		*head = newNode;
	}
}

//Function to display linked list
void displayList(struct node* list){
	if (list == NULL){
		printf("List is Empty\n\n");
		return;
	}
	while (list){
		if (list->next == NULL)
			printf("%d.\n\n", list->data);
		else
			printf("%d -> ", list->data);
		list = list->next;
	}
}

//Recursive Reversing Linked List.
void reverseList1(struct node** list){
	//If list is Empty
	if (*list == NULL)
		return;

	struct node* head = *list;
	struct node* res = head->next;

	//If list is having only one element
	if (res == NULL)
		return;

	reverseList1(&res);

	//Makes List Circular
	head->next->next = head;

	//To Change list behaviour from circular to singly linked list
	head->next = NULL;

	//To update the List reference with reversed list
	*list = res;
}

void main(){
	struct node* list = NULL;

	char choice;
	int data;

	printf("Enter a List of Numbers\n");

	do{
		printf("\nDo you want to insert more(y/n): ");
		scanf("%c", &choice);

		if (choice != 'n'){
			printf("\nEnter a Number: ");
			scanf("%d", &data);
			getchar();
			insert(&list, data);
		}

	} while (choice != 'n');

	printf("\n\nEntered List: ");
	displayList(list);

	reverseList1(&list);

	printf("\n\nReversed List: ");
	displayList(list);

	getchar();
	getchar();
}