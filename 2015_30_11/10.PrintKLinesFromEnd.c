#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void lastKLines(FILE* f, int k){
	FILE* ptr = fopen("file.txt", "r");
	
	int count = 1;
	int c = fgetc(f);

	//If given k is more than lines in file.
	while ((count < k) && (c != EOF)){
		if (c == '\n')
			count++;
		c = fgetc(f);
	}

	//Printing whole file as k is more than Lines in the file
	if (count != k){
		c = fgetc(ptr);
		while (c != EOF){
			printf("%c", c);
			c = fgetc(ptr);
		}
		return;
	}

	//Counting total lines in file after k lines
	count = 0;
	while (c != EOF){
		if (c == '\n')
			count++;
		c = fgetc(f);
	}

	//Taking the ptr position to the start of kth line from end
	c = fgetc(ptr);
	while (count != 0){
		if (c == '\n')
			count--;
		c = fgetc(ptr);
	}

	//Printing Last K Lines
	do{
		printf("%c", c);
		c = fgetc(ptr);
	} while (c != EOF);

	fclose(ptr);
}

void main(){
	FILE* test = fopen("file.txt", "r");
	
	lastKLines(test, 15);

	fclose(test);

	getchar();
}