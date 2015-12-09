#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node* createList(int* a, int len){
	struct node* head = NULL;
	while (len - 1 >= 0){
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = a[len - 1];
		newNode->next = head;
		head = newNode;
		len--;
	}
	return head;
}

void displayList(struct node* list){
	if (list == NULL){
		printf("Empty list\n\n");
		return;
	}

	while (list->next){
		printf("%d -> ", list->data);
		list = list->next;
	}
	printf("%d.\n\n", list->data);
}

void reverseList(struct node** list){
	//If list is Empty
	if (*list == NULL)
		return;

	struct node* head = *list;
	struct node* res = head->next;

	//If list is having only one element
	if (res == NULL)
		return;

	reverseList(&res);

	//Makes List Circular
	head->next->next = head;

	//To Change list behaviour from circular to singly linked list
	head->next = NULL;

	//To update the List reference with reversed list
	*list = res;
}

//Reversing the descending part of the list
struct node* sortLinkedList1(struct node *list){
	if (list == NULL)
		return NULL;

	if (list->next == NULL)
		return list;
	
	struct node* temp = NULL;
	struct node* head = list;

	while (head && (head->data < head->next->data)){
		temp = head;
		head = head->next;
	}

	if (head == NULL)
		return list;

	reverseList(&(temp->next));

	return list;

}

//Bubble Sort Approach
struct node* sortLinkedList2(struct node *head) {
	if (head == NULL)
		return NULL;

	if (head->next == NULL)
		return head;

	struct node *temp = head;

	int sorted = 0;
	int data;
	while (sorted == 0){
		temp = head;
		sorted = 1;
		while (temp->next){
			if (temp->data > temp->next->data){
				data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = data;

				sorted = 0;
			}
			temp = temp->next;
		}
	}

	return head;
}

void main(){

	int a[10] = { 1, 2, 7, 20, 15, 10 };

	struct node* list = createList(a, 6);

	printf("Initial List: ");
	displayList(list);

	struct node* res = sortLinkedList1(list);

	printf("Final list: ");
	displayList(res);

	getchar();
}