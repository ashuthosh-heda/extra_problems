#include<stdio.h>

struct testcases{
	int a[30];
	int length;
	int ind1;
	int ind2;
	int sum;
} tests[20] = {
	{
		{ -1, -1, -2, -5, -6, -4, 0, -2, -2 },
		9,
		6,
		6,
		0
	},
	{
		{ -2, -11, -1, -5 },
		4,
		2,
		2,
		-1
	},
	{
		{ 5, 6, -1, 3, 2, -3 },
		6,
		0,
		4,
		15
	},
	{
		{ 1, 2, 3, 3, 3, -12, -12, 5, 5, 5, 5, -29 },
		12,
		7,
		10,
		20
	},
	{
		{ 4, 4, 1, 2, 4, 5, -20, -125, 35 },
		9,
		8,
		8,
		35
	},
	{
		{ 1 },
		1,
		0,
		0,
		1
	},
	{
		{ 45, 25, -36, 85, 48, -125 },
		6,
		0,
		4,
		167
	},
	{
		{ -100, -100, -100, -100 },
		4,
		0,
		0,
		-100
	},
	{
		{ 50, -49, 50 },
		3,
		0,
		2,
		51
	},
	{
		0,
		0,
		-1,
		-1,
		-1
	},
	{
		{ -1, 0, 2 },
		3,
		1,
		2,
		2
	}
};

int sumOfMaxSeq(int* a, int len, int* ind1, int* ind2){
	int maxsum = a[0];
	int sum = a[0];
	int count = 0;
	*ind1 = 0;
	*ind2 = 0;

	for (int i = 1; i < len; i++)
	{
		if (a[i] > (sum + a[i])){
			sum = a[i];
			*ind1 = i;
		}
		else{
			sum = sum + a[i];
		}

		if (sum > maxsum){
			maxsum = sum;
			*ind2 = i;
		}
	}
	if (maxsum <= 0)
		*ind1 = *ind2;
	return maxsum;
}

void test(int nt){
	int sum = 0;
	int ind1;
	int ind2;
	for (int i = 0; i < nt; i++){
		ind1 = -1;
		ind2 = -1;
		sum = sumOfMaxSeq(tests[i].a, tests[i].length, &ind1, &ind2);
		if (ind1 == tests[i].ind1 && ind2 == tests[i].ind2 && sum == tests[i].sum){
			printf("Sub Array : ");
			for (int j = ind1; j <= ind2; j++){
				printf("%d ", tests[i].a[j]);
			}
			printf("\nMax Sum: %d", sum);
			printf("\t\t\tPass\n");
		}
		else
			printf("Fail\n");
	}
}

void main(){
	int num_test = 11;
	test(num_test);
	getchar();
}
