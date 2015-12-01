#include <stdio.h>
#include <malloc.h>
#define INT_MIN -5624852

struct node{
	int data;
	struct node* next;
};

struct node* createList(int* a, int len){
	struct node* head = NULL;
	while (len-1 >= 0){
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = a[len - 1];
		newNode->next = head;
		head = newNode;
		len--;
	}
	return head;
}

void displayList(struct node* list){
	while (list->next){
		printf("%d -> ", list->data);
		list = list->next;
	}
	printf("%d\n\n", list->data);
}

//Approach 1: Counting the number of nodes and then traversing to the count/2 node
//and return the data of the node.
int medianList1(struct node* head){
	if (head == NULL)
		return INT_MIN;
	
	struct node* temp = head;
	int count = 0;

	while (temp){
		count++;
		temp = temp->next;
	}

	int mid = count / 2;
	while (mid){
		head = head->next;
		mid--;
	}

	return head->data;
}


//Approach 2:Maintaining two pointers, one with one incremental and the other
//with two incremental. When the second pointer reaches NULL we get the median
//from the First pointer
int medianList2(struct node* head){
	if (head == NULL)
		return INT_MIN;

	struct node* frst = head;
	struct node* scnd = head;

	while (scnd != NULL && scnd->next != NULL){
		frst = frst->next;
		scnd = scnd->next->next;
	}

	return frst->data;
}


void main(){

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	struct node* list = createList(arr,9);

	printf("Given List: ");
	displayList(list);

	int mid = medianList2(list);
	if (mid == INT_MIN)
		printf("Empty\n");
	else
		printf("Median of the List is %d\n", mid);

	getchar();
}