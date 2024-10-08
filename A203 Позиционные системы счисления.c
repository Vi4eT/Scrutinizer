#include <stdio.h>
#include <stdlib.h>
#define N 32
int main(void)
{
	int b, c;
	char s[N], *p;
	scanf_s("%d%d\n", &b, &c);
	gets_s(s, N);
	_itoa_s((int)strtol(s, &p, b), s, N, c);
	for (p = s; *p;)
		*p >= 'a' && *p <= 'z' ? *p -= 32, (int)++p : (int)++p;
	puts(s);
	return 0;
}