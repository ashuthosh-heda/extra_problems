#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node* next;
};

//Normal Insert at start. Creates Linked List
void insert(struct node** list, int num){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;

	if (*list == NULL)
		*list = newNode;
	else{
		struct node* temp = *list;
		while (temp->next)
			temp = temp->next;

		temp->next = newNode;
	}
}

//Makes Linked List as Circular Linked List
void circular(struct node** list){
	if (*list == NULL)
		return;

	struct node* temp = *list;
	while (temp->next)
		temp = temp->next;

	temp->next = *list;
}

//Function to Display Linked List
void displayList(struct node* list){
	//If list is empty
	if (list == NULL){
		printf("List is Empty\n");
		return;
	}
	
	//Only One Element
	if (list->next == list){
		printf("%d.\n\n", list->data);
		return;
	}

	struct node* temp = list;
	while (list->next != temp){
		printf("%d -> ", list->data);
		list = list->next;
	}
	printf("%d.", list->data);
	printf("\n\n");
}

//Inserting a element in a CircularLinkedList
void insertElement(struct node** list, int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	struct node* temp = *list;

	//Only one Element in the list
	if (temp->next == *list){
		if (temp->data <= data){
			temp->next = newNode;
			newNode->next = temp;
		}
		else{
			newNode->next = *list;
			temp->next = newNode;
			*list = newNode;
		}
	}
	//Inserting at first
	else if (data < temp->data){
		newNode->next = *list;
		while (temp->data <= temp->next->data)
			temp = temp->next;
		temp->next = newNode;
		*list = newNode;
	}
	//Inserting at second if first element is equal to inserting element
	else if (data == temp->data){
		newNode->next = temp->next;
		temp->next = newNode;
	}
	//Inserting at appropriate Place in the ciruclar Linked List
	else{
		while ((temp->next->data <= data) && (temp->next != *list)){
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void main(){

	struct node* list = NULL;

	printf("Enter list of Numbers to create a Circular Linked list(Non-Decreasing Order)\n\n");
	int data;
	char choice;
	do{
		printf("Do you want to Insert(y/n): ");
		scanf("%c", &choice);
		if (choice != 'n'){
			printf("Enter Number: ");
			scanf("%d", &data);
			getchar();
			insert(&list, data);
		}
		else
			circular(&list);
	} while (choice != 'n');

	printf("\nEntered List: ");
	displayList(list);

	if (list == NULL){
		getchar();
		getchar();
		return;
	}

	getchar();
	do{
		printf("Do you want to Insert More(y/n): ");
		scanf("%c", &choice);

		if (choice != 'n'){
			printf("Enter Element to Insert: ");
			scanf("%d", &data);
			getchar();

			insertElement(&list, data);
			printf("\nEntered List after Inserting Element: ");
			displayList(list);
		}
		
	} while (choice != 'n');

	printf("\n\nFinal List: ");
	displayList(list);

	getchar();
	getchar();
}