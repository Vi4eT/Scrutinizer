#pragma warning(disable : 4996)
#include <stdio.h>
int fill(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		a[i] = i;
	return *a;
}
void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int shift1(int a[], int n)
{
	int i, x;
	x = a[0];
	for (i = 0; i < n; i++)
		a[i] = a[i + 1];
	a[n - 1] = x;
	return *a;
}
int reverse(int a[], int n, int k)
{
	int i, j, x;
	k %= n;
	if (k != 0)
	{
		for (i = 0; i < n / 2; i++)
		{
			x = a[i];
			a[i] = a[n - 1 - i];
			a[n - 1 - i] = x;
		}
		for (i = 0; i < k / 2; i++)
		{
			x = a[i];
			a[i] = a[k - 1 - i];
			a[k - 1 - i] = x;
		}
		for (i = k, j = 0; i < (n - k) / 2 + k; i++, j++)
		{
			x = a[i];
			a[i] = a[n - 1 - j];
			a[n - 1 - j] = x;
		}
	}
	print(a, n);
	return *a;
}
int NOD(int n, int k)
{
	int c;
	while (k)
	{
		c = n % k;
		n = k;
		k = c;
	}
	return n;
}
int shift(int a[], int n, int k)
{
	int x, y = 1, i, j;
	for (i = 0; i < NOD(n, k); i++)
	{
		x = a[i];
		j = i;
		while (y != i)
		{
			y = (k + j) % n;
			if (y >= n)
				y -= n;
			if (y == i)
				break;
			a[j] = a[y];
			j = y;
		}
		a[j] = x;
	}
	print(a, n);
	return *a;
}
int main(void)
{
	int a[100], n, k, i;
	scanf("%d %d", &n, &k);
	fill(a, n);
	printf("Original array:\n");
	print(a, n);
	printf("New array:\n");
	if (k == 0 || n == k)
		print(a, n);
	else
		shift(a, n, k);
	return 0;
}