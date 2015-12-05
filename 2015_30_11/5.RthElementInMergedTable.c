#include <stdio.h>

struct testcase{
	int n1;
	int n2;
	int r;
	int sol;
}tests[5] = {
	{
		3,
		1,
		4,
		4
	},
	{
		0,
		0,
		4,
		0
	},
	{
		2,
		3,
		4,
		6
	},
	{
		5,
		6,
		10,
		30
	},
	{
		3,
		5,
		5,
		10
	}
};

//Function to find out the Element at rth position after ascending merging of
//two tables of n1 and n2.
int mergedTableElement(int n1, int n2, int r){
	int element = 0;
	int a = n1;
	int b = n2;

	for (int i = 1; i <= r; i++){
		if (a < b)
			element = a;
		else
			element = b;
		
		if (element >= a)
			a = a + n1;
		
		if (element >= b)
			b = b + n2;

	}

	return element;
}

void test(int n){
	for (int i = 0; i < n; i++){
		int res = mergedTableElement(tests[i].n1, tests[i].n2, tests[i].r);
		if (res == tests[i].sol)
			printf("Pass\n");
		else
			printf("Fail\n");
	}
}

void main(){
	test(5);
	getchar();
}