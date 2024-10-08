#include <stdio.h>
int main(void)
{
	int d = 0, i = 9, j = 0, a[10] = {0}, check = 0;
	char *digit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
		 *secondten[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
		 *zeroend[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"},
		 *large[] = {"hundred", "thousand", "million", "billion"};
	scanf_s("%d", &d);
	do
	{
		a[i] = d % 10;
		d /= 10;
		i--;
		j++;
	} while (d);
	for (i++, j = (j - 1) / 3; j >= 0; j--)
	{
		switch (i % 3)
		{
		case 1:
			printf("%s %s", digit[a[i++]], large[0]);
			if (!a[i])
			{
				if (a[i + 1])
					printf(" %s", digit[a[++i]]);
				break;
			}
			printf(" ");
		case 2:
			if (a[i] == 1)
				printf("%s", secondten[a[++i]]);
			else if (!a[i + 1])
				printf("%s", zeroend[a[i] - 2]);
			else
			{
				printf("%s-%s", zeroend[a[i] - 2], digit[a[i + 1]]);
				i++;
			}
			break;
		case 0:
			printf("%s", digit[a[i]]);
			break;
		}
		i++;
		if (j)
		{
			printf(" %s", large[j]);
			for (; j > 0; j--, i++)
			{
				if (!a[i])
					if (!a[++i])
						if (!a[++i])
							check = 0;
						else
							check = 1;
					else
						check = 1;
				else
					check = 1;
				if (check)
				{
					printf(" ");
					break;
				}
			}
			if (!check)
				break;
		}
	}
	return 0;
}