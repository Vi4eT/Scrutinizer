#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
int del(char a)
{
	if (((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z')))
		return 0;
	else
		return 1;
}
int main(void)
{
	int i = 0, j = 0, k = 0, c = 0, lword = 0, lstr = 0, check = 0;
	char str[101], word[101];
	gets_s(word, 101);
	gets_s(str, 101);
	lword = strlen(word);
	lstr = strlen(str);
	for (i = 0; i <= lstr; i++)
	{
		if (str[i] == word[0])
		{
			if (i + lword > lstr)
				break;
			for (j = 0, c = 0; j < lword; j++)
				if (str[i + j] == word[j])
					c++;
			if (!i)
				check = (c == lword) && (del(str[i + lword]));
			else
				check = (c == lword) && (del(str[i - 1])) && (del(str[i + lword]));
			if (check)
			{
				for (j = i - 1, k = 0; j >= 0; j--)
					if (del(str[j]))
						k++;
					else
						break;
				for (j = i - k; j <= lstr - lword - k; j++)
					str[j] = str[j + lword + k];
				lstr = strlen(str);
				i = i - k - 1;
			}
		}
	}
	puts(str);
	return 0;
}