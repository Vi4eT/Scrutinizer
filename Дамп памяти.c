#pragma warning(disable : 4996)
#pragma warning(disable : 4305)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#define N 20
int random(int arr[])
{
	int i;
	for (i = 0; i < N; i++)
		arr[i] = rand();
	return *arr;
}
int fill(int arr[])
{
	int i;
	double x;
	for (i = 0; i < N; i++)
	{
		x = (double)arr[i] / (RAND_MAX + 1) * 100;
		arr[i] = (int)x;
	}
	return *arr;
}
double fillb(double b[], int a[])
{
	int i;
	double x;
	for (i = 0; i < N; i++)
	{
		x = (double)a[i];
		b[i] = x;
	}
	return *b;
}

void print(double arr[])
{
	int i;
	for (i = 0; i < N; i++)
		printf("%.1lf ", arr[i]);
	printf("\n");
}
void printint(int arr[])
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void memorydump(void *ptr, int size)
{
	int i, j, k, f;
	unsigned char *p;
	p = (unsigned char *)ptr;
	for (i = 0; i < size; i++)
	{
		printf("%p: ", &p[i]);
		for (j = 0, k = i; i < size && j < 16; j++, i++)
			printf("%02X ", p[i]);
		if (j < 16)
		{
			for (f = 48; f > j * 3; f--)
				printf(" ");
		}
		printf(" ");
		for (j = 0; k < size && j < 16; j++, k++)
		{
			if (isprint(p[k]) == 0)
				printf(".");
			else
				printf("%c", p[k]);
		}
		printf("\n");
		if (i == size)
			break;
		i--;
	}
}
int main(void)
{
	int a[N];
	double d = 112.111, b[N];
	float f = 112.111;
	char s[10], *p = (char *)malloc(10);
	srand((unsigned)time(0));
	random(a);
	fill(a);
	fillb(b, a);
	printf("int array:\n");
	memorydump(a, sizeof(a));
	printf("double array:\n");
	memorydump(b, sizeof(b));
	printf("float:\n");
	memorydump(&f, sizeof(f));
	printf("double:\n");
	memorydump(&d, sizeof(d));
	strcpy(s, "Hello!");
	strcpy(p, "Hello!");
	printf("static char array:\n");
	memorydump(s, (int)(sizeof(s)));
	printf("dynamic char array:\n");
	memorydump(p, sizeof(p));
	return 0;
}