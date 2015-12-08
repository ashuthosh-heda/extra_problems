#include <stdio.h>

struct node{
	int data;
	struct node* next;
};

struct node* createList(int* a,int len){
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

void sortedList(struct node** listRef){
	//If no node
	if (*listRef == NULL)
		return;

	//If one Node
	if ((*listRef)->next == NULL){
		return;
	}

	struct node* high = *listRef;

	//If only two nodes are presents
	if (high->data > high->next->data){
		if (high->next->next == NULL){
			*listRef = high->next;
			high->next = NULL;
			(*listRef)->next = high;
		}
	}
	
	struct node* prevHigh = NULL;
	struct node* prevLow = NULL;

	//Loop to find first wrong occurance
	while (high->next && (high->data < high->next->data)){
		prevHigh = high;
		high = high->next;
	}

	//If no wrong occurance then the given list is sorted
	if (high->next == NULL)
		return;

	struct node* low = NULL;
	
	low = high->next;

	//Loop to find second wrong occurance
	while (low->next && (low->data < low->next->data)){
		prevLow = low;
		low = low->next;
	}

	//Handles the case with adjacent misplacement
	if (low->next == NULL){
		prevLow = high;
		low = high->next;
	}
	else{
		prevLow = low;
		low = low->next;
	}

	//First wrong occurance at first node case
	if (prevHigh != NULL)
		prevHigh->next = low;
	else
		*listRef = low;

	prevLow->next = high;

	//Swapping next
	struct node* temp = low->next;
	low->next = high->next;
	high->next = temp;
}

void main(){

	int a[10] = { 1, 2, 14, 11, 9, 15, 30 };

	struct node* list = createList(a,7);

	printf("Initial List: ");
	displayList(list);

	sortedList(&list);

	printf("Final list: ");
	displayList(list);

	getchar();
}